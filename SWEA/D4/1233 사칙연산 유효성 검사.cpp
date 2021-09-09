#include <iostream>

using namespace std;


bool is_operator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	else return false;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;
	
	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 1;

		cin >> N;

		for (int i = 1; i <= N; i++) {
			int n;
			char c;

			cin >> n >> c;
			
			if (n <= N / 2) {
				int left, right;

				if (n == N / 2 && N % 2 == 0) {
					cin >> left;
				}
				else {
					cin >> left >> right;
				}


				if (c >= '0' && c <= '9') {
					answer = 0;
				}
			}
			else {
				if (is_operator(c)) {
					answer = 0;
				}
			}
		}

		
		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}