#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, testcase, N;

	//freopen("input.txt", "r", stdin);
	cin >> T;


	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N;
		vector<int> price;
		long long int answer = 0;

		for (int i = 0; i < N; i++) {
			int p;
			cin >> p;
			price.push_back(p);
		}

		int max = price.back();
		for (int i = price.size() - 2; i >= 0; i--) {
			if (price[i] <= max) {
				answer += max - price[i];
			}
			else {
				max = price[i];
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}