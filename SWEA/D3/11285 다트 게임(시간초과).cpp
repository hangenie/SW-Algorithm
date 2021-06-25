#include <iostream>

using namespace std;

int score[] = { 0,  200 * 200, 180 * 180, 160 * 160, 140 * 140, 120 * 120, 100 * 100, 80 * 80, 60 * 60, 40 * 40, 20 * 20, -1 };

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 0;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int x, y, d2;

			cin >> x >> y;

			d2 = x * x + y * y;

			for (int j = 1; j <= 10; j++) {
				if (d2 <= score[j] && d2 > score[j + 1]) {
					answer += j;
					break;
				}
			}
		}

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}