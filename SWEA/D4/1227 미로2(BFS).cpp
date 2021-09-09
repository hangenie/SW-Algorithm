#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int answer;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int arr[100][100] = { 0 };
bool selected[100][100] = { false };
queue<pair<int, int>> q;


void initialize() {
	answer = 0;
	memset(arr, 0, sizeof(arr));
	memset(selected, false, sizeof(selected));
	while (!q.empty()) {
		q.pop();
	}
}

void BFS() {
	int x, y;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		selected[y][x] = true;

		if (arr[y][x] == 3) {
			answer = 1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx, ny;

			nx = x + dx[i];
			ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx >= 99 || ny >= 99) continue;
			if (arr[ny][nx] == 1) continue;
			if (selected[ny][nx] == true) continue;
			
			q.push(make_pair(nx, ny));
		}		
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

		for (int i = 0; i < 100; i++) {
			string temp;
			cin >> temp;

			for (int j = 0; j < 100; j++) {
				arr[i][j] = temp[j] - '0';

				if (temp[j] == '2') {
					x = j;
					y = i;
				}
			}
		}

		q.push(make_pair(x, y));
		BFS();


		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}