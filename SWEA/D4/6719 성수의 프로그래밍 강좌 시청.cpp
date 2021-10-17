#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, K;
double answer;
int M[200];

void initialize() {
	answer = 0.0;
	memset(M, 0, sizeof(M));
}

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> M[i];
	}
}

void calculation() {
	sort(M, M + N);

	for (int i = N - K ; i < N; i++) {
		answer = (answer + M[i]) / 2;
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();
		calculation();
		
		printf("#%d %lf\n", testcase, answer);
	}

	return 0;
}