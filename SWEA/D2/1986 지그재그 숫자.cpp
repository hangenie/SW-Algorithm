#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 0;
		cin >> N;

		if (N % 2 == 0) {
			answer = -(N / 2);
		}
		else {
			answer = N - (N / 2);
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}