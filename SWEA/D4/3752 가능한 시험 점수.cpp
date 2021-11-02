#include <iostream>
#include <string.h>

using namespace std;

int N, answer;
int number[100];
bool score[10001];

void initialize() {
	answer = 0;
	memset(number, 0, sizeof(number));
	memset(score, false, sizeof(score));
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
}

void solve() {
	int max = 0;
	
	score[0] = true;

	for (int i = 0; i < N; i++) {
		max += number[i];

		for (int j = max; j >= 0; j--) {
			if (score[j]) {
				score[j + number[i]] = true;
			}
		}
	}

	for (int i = 0; i <= max; i++) {
		if (score[i]) answer++;
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

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}