// #pragma warning (disable:4996)
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, B, C;
	queue<int> A;
	long long int answer = 0;

	int a;

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push(a);
	}
	cin >> B >> C;

	while (!A.empty()) {
		a = A.front();
		A.pop();

		a -= B;
		answer++;

		if (a > 0) {
			if (a % C == 0) {
				answer += a / C;
			}
			else {
				if (a < C) {
					answer += 1;
				}
				else {
					answer += a / C + 1;
				}
			}
		}
	}

	cout << answer;

	return 0;
}