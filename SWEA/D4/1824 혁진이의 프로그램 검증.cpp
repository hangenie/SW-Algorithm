#include <iostream>
#include <string.h>

using namespace std;

int R, C, memory;
string answer;
bool flag;
char program[20][20];
bool visited[20][20][4][16];
int dr[] = { 0, 0, 1, -1 };		// µ¿¼­³²ºÏ
int dc[] = { 1, -1, 0, 0 };

void initialize() {
	memory = 0;
	answer = "NO";
	memset(program, '0', sizeof(program));
	memset(visited, false, sizeof(visited));
}

void input() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < C; j++) {
			program[i][j] = str[j];

			if (str[j] == '@') {
				flag = true;
			}
		}
	}
}

void DFS(int r, int c, int dir, int memory) {
	if (program[r][c] == '@') {
		answer = "YES";

		return;
	}


	int nr, nc, ndir, nmemory;
	ndir = dir;
	nmemory = memory;

	if (program[r][c] == '<') {
		ndir = 1;
	}
	else if (program[r][c] == '>') {
		ndir = 0;
	}
	else if (program[r][c] == '^') {
		ndir = 3;
	}
	else if (program[r][c] == 'v') {
		ndir = 2;
	}
	else if (program[r][c] == '_') {
		if (memory == 0) ndir = 0;
		else ndir = 1;
	}
	else if (program[r][c] == '|') {
		if (memory == 0) ndir = 2;
		else ndir = 3;
	}
	else if (program[r][c] == '.') {
		ndir = dir;
	}
	else if (program[r][c] >= '0' && program[r][c] <= '9') {
		nmemory = program[r][c] - '0';
	}
	else if (program[r][c] == '+') {
		if (memory == 15) nmemory = 0;
		else nmemory = memory + 1;
	}
	else if (program[r][c] == '-') {
		if (memory == 0) nmemory = 15;
		else nmemory = memory - 1;
	}
	
	if (program[r][c] == '?') {
		for (int i = 0; i < 4; i++) {
			nr = r + dr[i];
			nc = c + dc[i];

			if (nr < 0) nr = R - 1;
			else if (nr >= R) nr = 0;
			else if (nc < 0) nc = C - 1;
			else if (nc >= C) nc = 0;

			if (visited[nr][nc][i][memory]) return;

			visited[nr][nc][i][memory] = true;
			DFS(nr, nc, i, memory);


			if (answer == "YES") return;
		}
	}
	else {
		nr = r + dr[ndir];
		nc = c + dc[ndir];


		if (nr < 0) nr = R - 1;
		else if (nr >= R) nr = 0;
		else if (nc < 0) nc = C - 1;
		else if (nc >= C) nc = 0;

		if (visited[nr][nc][ndir][nmemory]) return;

		visited[nr][nc][ndir][nmemory] = true;
		DFS(nr, nc, ndir, nmemory);
	}

}

void solve() {
	if (!flag) return;

	visited[0][0][0][0] = true;
	DFS(0, 0, 0, 0);
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();
		solve();

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}