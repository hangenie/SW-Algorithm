#include <iostream>

using namespace std;

int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int answer = 0;
		int m1, d1, m2, d2;

		cin >> m1 >> d1 >> m2 >> d2;

		if (m1 == m2) {
			answer = d2 - d1 + 1;
		}
		else {
			answer = month[m1] - d1;
			for (int i = m1 + 1; i < m2; i++) {
				answer += month[i];
			}
			answer += (d2 + 1);
		}


		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}