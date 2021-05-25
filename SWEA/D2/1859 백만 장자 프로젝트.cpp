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
		int i, j;

		for (i = 0; i < N; i++) {
			int p;
			cin >> p;
			price.push_back(p);
		}

		for (i = 0; i < N;) {
			int max = max_element(price.begin() + i, price.end()) - price.begin();
			for (j = i; j <= max; j++) {
				answer += price[max] - price[j];
			}
			i = j;
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}