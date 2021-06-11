#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 0, state = 0;
		cin >> N;

		int table[100][100];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> table[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			state = 0;
			for (int j = 0; j < N; j++) {
				if (state == 0) {
					if (table[j][i] == 1) {
						state = 1;
					}
				}
				else if (state == 1) {
					if (table[j][i] == 2) {
						answer++;
						state = 0;
					}
				}
				
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}