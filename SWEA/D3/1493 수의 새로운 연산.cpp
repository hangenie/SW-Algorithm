#include <iostream>

using namespace std;

void to_location(int value, int& x, int& y) {
	int i = 0, sum = 0, step;
	while (sum < value) {
		i++;
		sum += i;
	}

	step = i + 1;
	y = sum - value + 1;
	x = step - y;
}

void to_value(int& value, int x, int y) {
	int sum = 0, step = x + y;

	for (int i = 1; i <= step - 2; i++) {
		sum += i;
	}

	value = sum + x;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int p, px, py;
		int q, qx, qy;
		int answer, x, y;

		cin >> p >> q;

		to_location(p, px, py);
		to_location(q, qx, qy);

		x = px + qx;
		y = py + qy;
		to_value(answer, x, y);


		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}