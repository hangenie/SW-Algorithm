#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int L, U, X, answer = 0;
		cin >> L >> U >> X;

		if (X < L) answer = L - X;
		else if (X > U) answer = -1;
		else answer = 0;

		

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}