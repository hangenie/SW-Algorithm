#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N;
		string X;
		long long int answer = 0, x = 0;
		cin >> N >> X;

		for (int i = X.size() - 1; i >= 0; i--) {
			x += (X[i] - '0') % (N - 1);
		}		
		
		answer = x % (N - 1);

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}