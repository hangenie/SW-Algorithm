#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 1, sum = 0;

		cin >> N;

		for (int i = 1; i <= N / 2; i++) {
			sum = i;
			int j = i + 1;

			while (sum <= N) {
				sum += j++;

				if (sum == N) {
					answer++;
					break;
				}
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}