#include <iostream>
#include <vector>

using namespace std;

int N, K, answer;

void DFS(vector<int> sequence, int start, int sum) {
	if (sum > K) {
		return;
	}
	
	if (sum == K) {
		answer++;
		return;
	}

	for (int i = start; i < N; i++) {
		DFS(sequence, i + 1, sum + sequence[i]);
	}

}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N >> K;

		vector<int> sequence(N, 0);
		answer = 0;

		for (int i = 0; i < N; i++) {
			cin >> sequence[i];
		}

		DFS(sequence, 0, 0);

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}