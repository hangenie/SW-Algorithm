#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int P, answer;
		vector<int> divisor;

		cin >> P;
		

		for (int i = 0; i < P; i++) {
			int num;

			cin >> num;

			divisor.push_back(num);
		}

		sort(divisor.begin(), divisor.end());
		answer = divisor.front() * divisor.back();
		

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}