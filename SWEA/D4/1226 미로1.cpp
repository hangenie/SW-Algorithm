#include <iostream>
#include <cstring>

using namespace std;

int answer;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int arr[16][16] = { 0 };
bool selected[16][16] = { false };


void initialize() {
	memset(arr, 0, sizeof(arr));
	memset(selected, false, sizeof(selected));
	answer = 0;
}

void DFS(int x, int y) {
	if (arr[y][x] == 3) {
		answer = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx, ny;

		nx = x + dx[i];
		ny = y + dy[i];

		if (nx <= 0 || ny <= 0 || nx >= 15 || ny >= 15) continue;
		if (arr[ny][nx] == 1) continue;
		if (selected[ny][nx] == true) continue;

		selected[ny][nx] = true;
		DFS(nx, ny);
		selected[ny][nx] = false;
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int x, y;

		cin >> testcase;

		initialize();

		for (int i = 0; i < 16; i++) {
			string temp;
			cin >> temp;

			for (int j = 0; j < 16; j++) {
				arr[i][j] = temp[j] - '0';

				if (temp[j] == '2') {
					x = j;
					y = i;
				}
			}
		}

		DFS(x, y);


		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}