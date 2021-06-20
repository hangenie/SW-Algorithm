#include <iostream>

using namespace std;

void print(int N, char C[], int K[]) {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K[i]; j++) {
			cout << C[i];
			cnt++;

			if (cnt % 10 == 0) {
				if (i == N - 1 && j == K[i] - 1) continue;
				cout << endl;
				cnt = 0;
			}
		}
		
	}

	cout << endl;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, K[10];
		char C[10];
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> C[i] >> K[i];
		}

		cout << '#' << testcase << endl;
		print(N, C, K);
	}

	return 0;
}