#include <iostream>
#include <algorithm>

using namespace std;

void initialize(bool check[]) {
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			check[i] = true;
		}
		else {
			check[i] = false;
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int answer = 1;
		int board[9][9];
		bool check[10];

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			}
		}
		initialize(check);

		//가로 검사
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				check[board[i][j]] = true;
			}

			if (find(check, check + 9, false) != check + 9) {
				answer = 0;
			}
			initialize(check);
		}


		//세로 검사
		if (answer != 0) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					check[board[j][i]] = true;
				}

				if (find(check, check + 10, false) != check + 10) {
					answer = 0;
				}
				initialize(check);
			}
		}


		//3x3 격자 검사
		if (answer != 0) {
			int r_start = 0, c_start = 0;
			for (int i = 0; i < 9; i++) {			
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						check[board[r_start + j][c_start + k]] = true;
					}
				}

				if (find(check, check + 9, false) != check + 9) {
					answer = 0;
				}
				initialize(check);

				c_start += 3;
				if ((i + 1) % 3 == 0) {
					r_start += 3;
					c_start = 0;
				}
			}
			
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}