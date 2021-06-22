#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;

bool cmp(const int& a, const int& b) {
	return a > b;
}

void DFS(int num[], int sum, int start, int cnt) {
	if (cnt == 3) {
		if (find(s.begin(), s.end(), sum) == s.end()) {
			s.push_back(sum);
		}
		return;
	}

	for (int i = start; i < 7; i++) {
		DFS(num, sum + num[i], i + 1, cnt + 1);
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int num[7], answer = 0, order = 1;

		for (int i = 0; i < 7; i++) {
			cin >> num[i];
		}
		s.clear();

		DFS(num, 0, 0, 0);
		
		sort(s.begin(), s.end(), cmp);

		answer = s[4];

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}