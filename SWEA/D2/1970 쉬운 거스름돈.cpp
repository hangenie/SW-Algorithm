#include <iostream>

using namespace std;

void print(int arr[]) {
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N;
		int money[] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
		int count[8] = { 0 };

		cin >> N;

		for (int i = 0; i < 8; i++) {
			count[i] = N / money[i];
			N %= money[i];
		}

		cout << '#' << testcase << endl;
		print(count);
	}

	return 0;
}