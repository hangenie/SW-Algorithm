#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int number[10], sum = 0, answer = 0;


		for (int i = 0; i < 10; i++) {
			cin >> number[i];
		}

		sort(number, number + 10);

		for (int i = 1; i <= 8; i++) {
			sum += number[i];
		}
		answer = round(sum / 8.0);

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}