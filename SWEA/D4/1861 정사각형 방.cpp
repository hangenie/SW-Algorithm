#include <iostream>
#include <string.h>

using namespace std;

int N, answer_num, answer_cnt, cnt;
int room[1000][1000];
int dr[] = { -1, 1, 0, 0 };		// »óÇÏÁÂ¿ì
int dc[] = { 0, 0, -1, 1 };

void initialize() {
	answer_num = 101;
	answer_cnt = -1;
	memset(room, 0, sizeof(room));
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> room[i][j];
		}
	}
}

void DFS(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr, nc;

		nr = r + dr[i];
		nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;

		if (room[nr][nc] == room[r][c] + 1) {
			cnt++;
			DFS(nr, nc);
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 1;
			DFS(i, j);
			
			if (answer_cnt < cnt) {
				answer_num = room[i][j];
				answer_cnt = cnt;
			}
			else if (answer_cnt == cnt) {
				if (answer_num > room[i][j]) {
					answer_num = room[i][j];
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

		cout << '#' << testcase << ' ' << answer_num << ' ' << answer_cnt << endl;
	}

	return 0;
}