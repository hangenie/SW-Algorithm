#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, M, answer = 0, count = 0;
		cin >> N >> M;

		int arr[15][15];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i <= N - M; i++) {
			for (int j = 0; j <= N - M; j++) {
				for (int k = 0; k < M; k++) {
					for (int l = 0; l < M; l++) {
						count += arr[i + k][j + l];
					}
				}

				if (answer < count) answer = count;
				count = 0;
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}