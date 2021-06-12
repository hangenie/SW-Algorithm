#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, K, answer = 0, cnt = 0;
		cin >> N >> K;

		int puzzle[15][15];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> puzzle[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (puzzle[i][j] == 1) {
					cnt++;
				}

				if (cnt != 0 && puzzle[i][j] == 0) {
					if (cnt == K) {
						answer++;
					}
					cnt = 0;
				}

				if (cnt != 0 && j == N - 1) {
					if (cnt == K) {
						answer++;
					}
					cnt = 0;
				}
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (puzzle[j][i] == 1) {
					cnt++;
				}

				if (cnt != 0 && puzzle[j][i] == 0) {
					if (cnt == K) {
						answer++;
					}
					cnt = 0;
				}

				if (cnt != 0 && j == N - 1) {
					if (cnt == K) {
						answer++;
					}
					cnt = 0;
				}
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}