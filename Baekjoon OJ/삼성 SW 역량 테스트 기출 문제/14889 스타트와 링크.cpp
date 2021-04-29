//#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> diff;

int sum(vector<vector<int>> S, vector<int> arr) {
	int sum = 0;

	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			sum += S[arr[i]][arr[j]];
			sum += S[arr[j]][arr[i]];
		}
	}

	return sum;
}

void DFS(vector<vector<int>> S, vector<bool> visited, int start, int cnt, int k) {
	vector<int> true_index;
	vector<int> false_index;
	int true_sum, false_sum;

	if (cnt == k) {
		// 차이값 계산
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == true) {
				true_index.push_back(i);
			}
			else {
				false_index.push_back(i);
			}
		}
		true_sum = sum(S, true_index);
		false_sum = sum(S, false_index);
		diff.push_back(true_sum >= false_sum ? true_sum - false_sum : false_sum - true_sum);
		return;

	}

	for (int i = start; i < visited.size(); i++) {
		if (visited[i] == true) {
			continue;
		}

		visited[i] = true;
		DFS(S, visited, i, cnt + 1, k);
		visited[i] = false;
		if (i == 0) break;
	}
}

int main() {
	int N;
	int answer = 0;

	vector<bool> visited;
	int temp;

	// 입력 값 저장
	//freopen("input.txt", "r", stdin);

	// 능력치 배열 초기화
	cin >> N;
	vector<vector<int>> S(N, vector<int>(0));

	for (int i = 0; i < N; i++) {
		visited.push_back(false);
		for (int j = 0; j < N; j++) {
			cin >> temp;
			S[i].push_back(temp);
		}
	}

	DFS(S, visited, 0, 0, N / 2);
	sort(diff.begin(), diff.end());
	answer = *min(diff.begin(), diff.end());


	cout << answer;

	return 0;
}