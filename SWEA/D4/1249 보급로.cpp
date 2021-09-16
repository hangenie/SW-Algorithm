#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N, answer;
int map[100][100];
int dp[100][100];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };


void initialize() {
	memset(map, 0, sizeof(map));
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			dp[i][j] = 2147483647;
		}
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			map[i][j] = s[j] - '0';
		}
	}
}

void BFS() {
	int x, y;
	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	dp[0][0] = 0;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx, ny;

			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (dp[ny][nx] > dp[y][x] + map[ny][nx]) {
				dp[ny][nx] = dp[y][x] + map[ny][nx];
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();

		BFS();
		
		answer = dp[N - 1][N - 1];
		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}