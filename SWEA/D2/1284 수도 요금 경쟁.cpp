#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int P, Q, R, S, W, answer = 0;
		cin >> P >> Q >> R >> S >> W;

		int A, B;

		A = P * W;

		if (W <= R) {
			B = Q;
		}
		else {
			B = Q + (W - R) * S;
		}

		answer = min(A, B);
		

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}