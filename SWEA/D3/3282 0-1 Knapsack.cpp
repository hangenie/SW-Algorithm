#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, K, answer;
		int dp[101][1001];
		int v[101], c[101];

		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> v[i] >> c[i];
		}

		for (int i = 0; i <= N; i++) {
			dp[i][0] = 0;
		}

		for (int i = 1; i <= K; i++) {
			dp[0][i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				if (v[i] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(c[i] + dp[i - 1][j - v[i]], dp[i - 1][j]);
			}
		}

		answer = dp[N][K];
		
		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}