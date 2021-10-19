#include <iostream>
#include <string.h>
#include <vector>
#include<algorithm>

using namespace std;

int N, K;
long long answer;
string nums;
vector<string> passwd;

void initialize() {
	answer = 0;
	nums.clear();
	passwd.clear();
}

void input() {
	cin >> N >> K >> nums;
}

int calculate(char ch) {
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'F') {
		return 10 + ch - 'A';
	}
}

void solve() {
	int M = N / 4;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j += M) {
			string str = nums.substr(j, M);
			if (find(passwd.begin(), passwd.end(), str) == passwd.end()) {
				passwd.push_back(str);
			}
		}
		nums.insert(nums.begin(), nums.back());
		nums.erase(nums.end() - 1);
	}

	sort(passwd.begin(), passwd.end(), greater<string>());

	answer = calculate(passwd[K - 1][0]);
	int i = 1;
	while (i < M) {
		answer *= 16;
		answer += calculate(passwd[K - 1][i++]);
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();
		solve();

		printf("#%d %lld\n", testcase, answer);
	}

	return 0;
}