#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N, M, R, C, L;
int answer;
int map[50][50];
bool visited[50][50];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void initialize() {
	answer = 0;
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
}

void input() {
	cin >> N >> M >> R >> C >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

bool connect(int dir, int npipe) {
	if (dir == 0) {
		if (npipe == 3 || npipe == 4 || npipe == 7) return false;
		else return true;
	}
	else if (dir == 1) {
		if (npipe == 3 || npipe == 5 || npipe == 6) return false;
		else return true;
	}
	else if (dir == 2) {
		if (npipe == 2 || npipe == 6 || npipe == 7) return false;
		else return true;
	}
	else {
		if (npipe == 2 || npipe == 4 || npipe == 5) return false;
		else return true;
	}
}

void solve() {
	queue<pair<pair<int, int>, int>> q;

	q.push(make_pair(make_pair(R, C), 1));
	visited[R][C] = true;

	while (!q.empty()) {
		int r, c, cnt, pipe;

		r = q.front().first.first;
		c = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		answer++;

		pipe = map[r][c];

		if (cnt == L) continue;	

		for (int i = 0; i < 4; i++) {
			int nr, nc, npipe;

			if (i == 0) {
				if (pipe == 3 || pipe == 5 || pipe == 6) continue;
			}
			else if (i == 1) {
				if (pipe == 3 || pipe == 4 || pipe == 7) continue;
			}
			else if (i == 2) {
				if (pipe == 2 || pipe == 4 || pipe == 5) continue;
			}
			else {
				if (pipe == 2 || pipe == 6 || pipe == 7) continue;
			}

			nr = r + dr[i];
			nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (map[nr][nc] == 0) continue;
			if (visited[nr][nc]) continue;

			if (connect(i, map[nr][nc])) {
				visited[nr][nc] = true;
				q.push(make_pair(make_pair(nr, nc), cnt + 1));
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