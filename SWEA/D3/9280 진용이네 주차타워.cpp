#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int n, m, x, num, answer = 0;
		int R[101] = { 0 };
		int parking[101] = { 0 };
		int W[2001] = { 0 };
		queue<int> order;
		queue<int> waiting;

		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			cin >> R[i];
		}

		for (int i = 1; i <= m; i++) {
			cin >> W[i];
		}

		for (int i = 0; i < 2 * m; i++) {
			cin >> x;
			order.push(x);
		}

		while (!order.empty()) {
			x = order.front();
			order.pop();
			if (x > 0) {
				num = find(parking + 1, parking + n + 1, 0) - parking;
				if (num != n + 1) {
					parking[num] = x;
					answer += R[num] * W[x];
				}
				else {
					waiting.push(x);
				}
			}
			else {
				x *= -1;
				num = find(parking + 1, parking + n + 1, x) - parking;
				parking[num] = 0;

				if (!waiting.empty()) {
					x = waiting.front();
					waiting.pop();

					parking[num] = x;
					answer += R[num] * W[x];
				}
			}
		}

		
		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}