#include <iostream>
#include <string.h>

using namespace std;

string bar;
int answer;

void initialize() {
	answer = 0;
}

void input() {
	cin >> bar;
}

void solve() {
	bool lazer = false;
	int cnt = 0;

	for (int i = 0; i < bar.size(); i++) {
		if (bar[i] == '(') {
			lazer = true;
			cnt++;
		}
		else {
			if (lazer == true) {
				cnt--;
				answer += cnt;
				lazer = false;
			}
			else {
				answer++;
				cnt--;
			}
		}
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

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}