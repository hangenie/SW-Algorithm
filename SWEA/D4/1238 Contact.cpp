#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int answer, start;
map<int, vector<int>> contact;
bool visited[101];


void initialize() {
	answer = 0;
	contact.clear();
	memset(visited, false, sizeof(visited));
}

void input() {
	int N;
	cin >> N >> start;

	for (int i = 0; i < N / 2; i++) {
		int from, to;

		cin >> from >> to;

		contact[from].push_back(to);
	}
}

void BFS() {
	int stage = 0;
	queue<pair<int, int>> q;

	q.push(make_pair(start, 1));
	visited[start] = true;

	while (!q.empty()) {
		int from, cnt;

		from = q.front().first;
		cnt = q.front().second;
		q.pop();


		for (int i = 0; i < contact[from].size(); i++) {
			if (visited[contact[from][i]] == true) continue;
			
			if (stage != cnt) {
				stage = cnt;
				answer = contact[from][i];
			}
			else {
				if (answer < contact[from][i]) {
					answer = contact[from][i];
				}
			}
			
			visited[contact[from][i]] = true;
			
			if (contact.find(contact[from][i]) != contact.end()) {
				q.push(make_pair(contact[from][i], cnt + 1));
			}
		}

		
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();

		// 연락 돌리기
		BFS();

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}