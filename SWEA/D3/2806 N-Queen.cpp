#include <iostream>

using namespace std;

int N, answer;
bool board[10][10];
bool visited_c[10];


void initialize() {
	for (int i = 0; i < N; i++) {
		visited_c[i] = false;

		for (int j = 0; j < N; j++) {
			board[i][j] = false;
		}
	}
}

// 왼쪽, 위 대각선 확인
bool lu_check(int r, int c) {
	int nr = r - 1, nc = c - 1;

	while (nr >= 0 && nc >= 0) {
		if (board[nr][nc] == true) {
			return false;
		}

		nr--;
		nc--;
	}
	return true;
}

// 왼쪽, 아래 대각선 확인
bool ld_check(int r, int c) {
	int nr = r + 1, nc = c - 1;

	while (nr < N && nc >= 0) {
		if (board[nr][nc] == true) {
			return false;
		}

		nr++;
		nc--;
	}
	return true;
}

// 오른쪽, 위 대각선 확인
bool ru_check(int r, int c) {
	int nr = r - 1, nc = c + 1;

	while (nr >= 0 && nc < N) {
		if (board[nr][nc] == true) {
			return false;
		}

		nr--;
		nc++;
	}
	return true;
}

// 오른쪽, 아래 대각선 확인
bool rd_check(int r, int c) {
	int nr = r + 1, nc = c + 1;

	while (nr < N && nc < N) {
		if (board[nr][nc] == true) {
			return false;
		}

		nr++;
		nc++;
	}
	return true;
}

void DFS(int r, int cnt) {
	if (r == N && cnt == N) {
		answer++;
		return;
	}

	if (r == N && cnt < N) {
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited_c[i] == true) continue;

		if (lu_check(r, i) && ld_check(r, i) && ru_check(r, i) && rd_check(r, i)) {
			visited_c[i] = true;
			board[r][i] = true;
			DFS(r + 1, cnt + 1);
			visited_c[i] = false;
			board[r][i] = false;
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N;
		
		answer = 0;
		initialize();

		DFS(0, 0);

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}