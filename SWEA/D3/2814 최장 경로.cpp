#include <iostream>

using namespace std;

int N, M, answer;
int graph[11][11];
bool visited[11];

void DFS(int node, int length) {
	if (answer < length) {
		answer = length;
	}

	for (int i = 1; i <= N; i++) {
		if (graph[node][i] == 1 && !visited[i]) {
			visited[i] = true;
			DFS(i, length + 1);
			visited[i] = false;
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N >> M;

		answer = 0;
		for (int i = 0; i < 11; i++) {
			visited[i] = false;
			for (int j = 0; j < 11; j++) {
				graph[i][j] = 0;
			}
		}

		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;

			graph[x][y] = 1;
			graph[y][x] = 1;
		}

		for (int i = 1; i <= N; i++) {
			visited[i] = true;
			DFS(i, 1);
			visited[i] = false;
		}
		

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}