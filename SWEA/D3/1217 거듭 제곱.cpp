#include <iostream>

using namespace std;

int pow(int N, int M) {
	if (M == 1)
		return N;
	else
		return N * pow(N, M - 1);
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, M, answer = 0;
		
		cin >> testcase;

		cin >> N >> M;

		answer = pow(N, M);

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}