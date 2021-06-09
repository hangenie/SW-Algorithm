#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int answer;
		bool flag = false;
		char board[100][100];

		cin >> testcase;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> board[i][j];
			}
		}

		for (int palindrome = 100; palindrome > 1; palindrome--) {
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j <= 100 - palindrome; j++) {
					int len = palindrome;
					for (int k = 0; k < palindrome / 2; k++) {
						if (board[i][j + k] == board[i][j + k + len - 1]) {
							len -= 2;
							if (k == palindrome / 2 - 1) {
								answer = palindrome;
								flag = true;
							}
						}
						else {
							break;
						}
					}
					if (flag == true) break;
				}
				if (flag == true) break;
			}
			if (flag == true) break;

			for (int i = 0; i < 100; i++) {
				for (int j = 0; j <= 100 - palindrome; j++) {
					int len = palindrome;
					for (int k = 0; k < palindrome / 2; k++) {
						if (board[j + k][i] == board[j + k + len - 1][i]) {
							len -= 2;
							if (k == palindrome / 2 - 1) {
								answer = palindrome;
								flag = true;
							}
						}
						else {
							break;
						}
					}
					if (flag == true) break;
				}
				if (flag == true) break;
			}
			if (flag == true) break;
		}
		

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}