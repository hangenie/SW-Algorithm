#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N;
		cin >> N;

		int arr[7][7];
		int j = 0, k = N - 1, l = N - 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		
		cout << '#' << testcase << endl;

		for (int n = 0; n < N; n++) {
			for (int i = N - 1; i >= 0; i--) {
				cout << arr[i][j];
			}
			j++;
			cout << ' ';
			for (int i = N - 1; i >= 0; i--) {
				cout << arr[k][i];
			}
			k--;
			cout << ' ';
			for (int i = 0; i <= N - 1; i++) {
				cout << arr[i][l];
			}
			l--;
			cout << endl;
		}
		
	}

	return 0;
}