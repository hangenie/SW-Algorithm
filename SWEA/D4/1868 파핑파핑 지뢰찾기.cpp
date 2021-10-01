#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N, answer;
char arr[300][300];
int arri[300][300];
bool visited[300][300];
int dr[] = { -1, -1, -1, 0 ,0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
queue<pair<int, int>> bomb;

void initialize() {
	N = 0;
	answer = 0;
	memset(arr, '0', sizeof(arr));
	memset(arri, 0, sizeof(arri));
	memset(visited, false, sizeof(visited));
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;

		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j];

			if (str[j] == '*') {
				bomb.push(make_pair(i, j));
			}
		}		
	}
}

bool check(int r, int c) {
	int nr, nc;

	for (int i = 0; i < 8; i++) {
		nr = r + dr[i];
		nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		
		if (arr[nr][nc] == '*') return false;
	}

	return true;
}

void calculate() {
	while (!bomb.empty()) {
		int r, c;

		r = bomb.front().first;
		c = bomb.front().second;
		bomb.pop();

		arri[r][c] = -1;

		for (int i = 0; i < 8; i++) {
			int nr, nc;

			nr = r + dr[i];
			nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (arr[nr][nc] == '*') continue;
			
			arri[nr][nc]++;
		}
	}
}

void BFS(int r, int c) {
	queue<pair<int, int>> q;

	q.push(make_pair(r, c));
	
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		visited[r][c] = true;

		for (int i = 0; i < 8; i++) {
			int nr, nc;

			nr = r + dr[i];
			nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (visited[nr][nc] == true) continue;
			
			visited[nr][nc] = true;
			if (arri[nr][nc] == 0) {
				q.push(make_pair(nr, nc));
			}
		}
	}
}

void count() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arri[i][j] == 0 && !visited[i][j]) {
				answer++;
				BFS(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arri[i][j] == -1) continue;
			if (visited[i][j] == true) continue;

			answer++;
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

		calculate();
		count();

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}