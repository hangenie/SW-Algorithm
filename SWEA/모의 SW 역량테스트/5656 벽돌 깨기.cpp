#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int N, W, H;
int answer;
int brick[15][12];
int brick_c[15][12];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
vector<vector<int>> start;

void initialize() {
	answer = 987654321;
	memset(brick, 0, sizeof(brick));
	memset(brick_c, 0, sizeof(brick_c));
	start.clear();
}

void input() {
	cin >> N >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> brick[i][j];
		}
	}
}

void save(vector<int> v, int cnt) {
	if (cnt == N) {
		start.push_back(v);
		return;
	}

	for (int i = 0; i < W; i++) {
		v.push_back(i);
		save(v, cnt + 1);
		v.pop_back();
	}
}

void copy_arr() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			brick_c[i][j] = brick[i][j];
		}
	}
}

void BFS(int r, int c) {
	queue<pair<int, int>> q;

	q.push(make_pair(r, c));

	while (!q.empty()) {
		int r, c, cnt;

		r = q.front().first;
		c = q.front().second;
		q.pop();

		cnt = brick_c[r][c];
		brick_c[r][c] = 0;

		if (cnt == 1) continue;

		for (int i = 0; i < 4; i++) {
			int nr, nc;

			for (int j = 0; j < cnt - 1; j++) {
				if (j == 0) {
					nr = r + dr[i];
					nc = c + dc[i];
				}
				else {
					nr += dr[i];
					nc += dc[i];
				}

				if (nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
				if (brick_c[nr][nc] == 0) continue;
				
				q.push(make_pair(nr, nc));
			}
		}
	}
}

void sort_arr() {
	queue<int> q;

	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (brick_c[j][i]) {
				q.push(brick_c[j][i]);
			}
		}

		int r = H - 1;
		while (!q.empty()) {
			brick_c[r--][i] = q.front();
			q.pop();
		}
		for (int j = r; j >= 0; j--) {
			brick_c[j][i] = 0;
		}
	}
}

void count_arr() {
	int cnt = 0;

	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (brick_c[j][i]) cnt++;
			else break;
		}
	}

	if (answer > cnt) {
		answer = cnt;
	}
}

void solve() {
	for (int i = 0; i < start.size(); i++) {
		copy_arr();
		for (int j = 0; j < N; j++) {
			int r;
			for (r = 0; r < H; r++) {
				if (brick_c[r][start[i][j]]) {
					BFS(r, start[i][j]);
					break;
				}
			}
			
			sort_arr();
		}
		count_arr();

		if (answer == 0) break;
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (testcase = 1; testcase <= T; testcase++) {
		vector<int> temp;

		initialize();
		input();
		save(temp, 0);
		solve();

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}