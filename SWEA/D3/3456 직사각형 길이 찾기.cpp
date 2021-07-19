#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int a, b, c, answer;
		
		cin >> a >> b >> c;

		if (a == b) {
			answer = c;
		}
		else if (a == c) {
			answer = b;
		}
		else {
			answer = a;
		}

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}