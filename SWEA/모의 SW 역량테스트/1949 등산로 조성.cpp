#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int answer;
int map[8][8];
int map_c[8][8];
bool visited[8][8];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
vector<pair<int, int>> start;

void initialize() {
	answer = 0;
	memset(map, 0, sizeof(map));
	memset(map_c, 0, sizeof(map_c));
	memset(visited, false, sizeof(visited));
	start.clear();
}

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

void copy_arr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map_c[i][j] = map[i][j];
		}
	}
}

void save() {
	int max = 0;

	for (int i = 0; i < N; i++) {
		if(max < *max_element(map[i], map[i] + N))
			max = *max_element(map[i], map[i] + N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max == map[i][j]) {
				start.push_back(make_pair(i, j));
			}
		}
	}
}

void DFS(int r, int c, int cnt) {
	if (answer < cnt) answer = cnt;
	if (map[r][c] == 0) return;

	for (int i = 0; i < 4; i++) {
		int nr, nc;

		nr = r + dr[i];
		nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		if (map_c[nr][nc] >= map_c[r][c]) continue;
		if (visited[nr][nc]) continue;

		visited[nr][nc] = true;
		DFS(nr, nc, cnt + 1);
		visited[nr][nc] = false;
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_arr();
			start.clear();

			for (int k = 0; k <= K; k++) {
				map_c[i][j] = map[i][j] - k;

				if (map_c[i][j] < 0) map_c[i][j] = 0;

				// 시작점 구하기
				save();

				// 등산로 만들기
				for (int l = 0; l < start.size(); l++) {
					memset(visited, false, sizeof(visited));

					visited[start[l].first][start[l].second] = true;
					DFS(start[l].first, start[l].second, 1);
				}
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
		input();
		solve();

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}