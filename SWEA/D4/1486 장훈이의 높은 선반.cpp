#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, B, answer;
int clerk[20];
bool visited[20];

void initialize() {
	answer = 987654321;
	memset(clerk, 0, sizeof(clerk));
	memset(visited, false, sizeof(visited));

	cin >> N >> B;
}

void DFS(int index, int sum) {
	if (sum >= B) {
		if (sum - B < answer) {
			answer = sum - B;
			return;
		}
	}

	for (int i = index; i < N; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		DFS(i, sum + clerk[i]);
		visited[i] = false;
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();

		for (int i = 0; i < N; i++) {
			cin >> clerk[i];
		}

		sort(clerk, clerk + N);

		DFS(0, 0);

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}