#include <iostream>
#include <cstring>

using namespace std;

void print(int arr[][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	int T, testcase, N;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	int snail[10][10] = { 0 };
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };


	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N;

		int x = -1, y = 0;
		int way = 0;
		int t = 0, cnt = 0, turn = N;

		memset(snail, 0, sizeof(snail));

		for (int i = 0; i < N * N; i++) {
			x += dx[way];
			y += dy[way];
			
			snail[y][x] = i + 1;
			t++;

			if (i == N - 1) {
				way = (way + 1) % 4;
				t = 0;
				turn--;

			}

			if (t == turn) {
				way = (way + 1) % 4;
				t = 0;
				cnt++;
			}
			if (cnt == 2) {
				cnt = 0;
				t = 0;
				turn--;
			}
		}
		
		cout << '#' << testcase << endl;
		print(snail, N);
	}

	return 0;
}