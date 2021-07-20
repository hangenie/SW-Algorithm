#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, Q, L, R;
		int box[1001] = { 0 };

		cin >> N >> Q;

		for (int i = 1; i <= Q; i++) {
			cin >> L >> R;

			for (int j = L; j <= R; j++) {
				box[j] = i;
			}
		}

		cout << '#' << testcase << ' ';
		for (int i = 1; i <= N; i++) {
			cout << box[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}