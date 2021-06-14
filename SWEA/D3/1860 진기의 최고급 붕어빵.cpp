#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, M, K;
		cin >> N >> M >> K;

		string answer = "Possible";
		vector<int> customer;
		int time = M, count = K;

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			customer.push_back(temp);
		}

		sort(customer.begin(), customer.end());
	
		for (int i = 0; i < N; i++) {
			if (customer[i] < time) {
				answer = "Impossible";
				break;
			}
			else count--;

			if (count == 0) {
				time += M;
				count = K;
			}
		}


		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}