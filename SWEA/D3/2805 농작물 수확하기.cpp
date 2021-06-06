#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 0;
		cin >> N;

		vector<vector<int>> farm(N, vector<int>(N, 0));
		int start = N / 2, end = N / 2;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &farm[i][j]);
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = start; j <= end; j++) {
				answer += farm[i][j];
			}

			if (i < N / 2) {
				start--;
				end++;
			}
			else {
				start++;
				end--;
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}