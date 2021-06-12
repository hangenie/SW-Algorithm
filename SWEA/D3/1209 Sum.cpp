#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int answer = 0, sum = 0;
		cin >> testcase;

		int arr[100][100];

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}


		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[i][j];
			}

			if (answer < sum) answer = sum;
		}

		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[j][i];
			}

			if (answer < sum) answer = sum;
		}

		sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += arr[i][i];
		}
		if (answer < sum) answer = sum;
		
		sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += arr[i][99 - i];
		}
		if (answer < sum) answer = sum;


		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}