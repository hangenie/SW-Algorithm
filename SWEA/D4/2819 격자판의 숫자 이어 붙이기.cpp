#include <iostream>
#include <string.h>
#include <set>
#define SIZE 4

using namespace std;

int answer;
char map[SIZE][SIZE];
set<string> number;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void initialize() {
	answer = 0;
	memset(map, 0, sizeof(map));
	number.clear();
}

void input() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> map[i][j];
		}
	}
}

void DFS(int x, int y, string num, int cnt) {
	if (cnt == 7) {
		number.insert(num);

		return;
	}

	for (int i = 0; i < SIZE; i++) {
		int nx, ny;

		nx = x + dx[i];
		ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE) continue;

		num.push_back(map[ny][nx]);
		DFS(nx, ny, num, cnt + 1);
		num.pop_back();
	}
}

void solve() {
	string num = "";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			DFS(i, j, num, 0);
		}
	}

	answer = number.size();
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