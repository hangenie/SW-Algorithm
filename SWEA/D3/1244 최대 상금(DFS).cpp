#include <iostream>
#include <string>

using namespace std;

int answer;

void DFS(string num, int N, int start, int cnt) {
	if (cnt == N) {
		int temp = stoi(num);

		if (answer < temp) {
			answer = temp;
		}

		return;
	}

	for (int i = start; i < num.size() - 1; i++) {
		for (int j = i + 1; j < num.size(); j++) {
			swap(num[i], num[j]);
			DFS(num, N, i, cnt + 1);
			swap(num[i], num[j]);
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		string num;
		int N;

		answer = 0;
		cin >> num >> N;

		if (N > num.size()) {
			N = num.size();
		}
		
		DFS(num, N, 0, 0);

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}