#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int N;
double E;
long long answer;
long long X[1001], Y[1001];
int parent[1001];
vector<pair<long long, pair<int, int>>> link;


void initialize() {
	N = 0;
	E = 0.0;
	answer = 0;
	memset(X, 0, sizeof(X));
	memset(Y, 0, sizeof(Y));
	memset(parent, 0, sizeof(parent));
	link.clear();
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> X[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> Y[i];
	}

	cin >> E;
}


void calculation() {
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			long long dx = (X[i] - X[j]) * (X[i] - X[j]);
			long long dy = (Y[i] - Y[j]) * (Y[i] - Y[j]);
			link.push_back(make_pair(dx + dy, make_pair(i, j)));
		}
	}

	sort(link.begin(), link.end());
}

int getParent(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = getParent(parent[node]);
}

void unionParent(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);

	if (node1 != node2) parent[node2] = node1;
}

bool isCycle(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);

	if (node1 == node2) return true;
	else return false;
}

void kruskal() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < link.size(); i++) {
		// 사이클 만들어지는지 확인
		if (!isCycle(link[i].second.first, link[i].second.second)) {
			answer += link[i].first;

			unionParent(link[i].second.first, link[i].second.second);
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();

		// 간선 가중치 값 저장
		calculation();

		// Kruskal Algorithm
		kruskal();

		printf("#%d %.0lf\n", testcase, answer * E);
	}

	return 0;
}