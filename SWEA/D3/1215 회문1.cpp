#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 0;
		char board[8][8];

		cin >> N;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> board[i][j];
			}
		}

		// 가로 회문 찾기
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - N; j++) {
				int len = N - 1;
				for (int k = 0; k < N / 2; k++) {
					if (board[i][j + k] == board[i][j + k + len]) {
						len -= 2;
						if (k == N / 2 - 1) {
							answer++;
						}
					}
					else {
						break;
					}
				}
			}
		}
		

		// 세로 회문 찾기
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - N; j++) {
				int len = N - 1;
				for (int k = 0; k < N / 2; k++) {
					if (board[j + k][i] == board[j + k + len][i]) {
						len -= 2;
						if (k == N / 2 - 1) {
							answer++;
						}
					}
					else {
						break;
					}
				}
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}