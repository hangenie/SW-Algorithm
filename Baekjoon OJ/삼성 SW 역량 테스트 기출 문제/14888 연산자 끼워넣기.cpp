//#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int A[11];
vector<int> op_index;
int answer1, answer2;

vector<bool> visited;
vector<int> temp;
vector<int> result;

void print_vector(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void cal() {
	queue<int> Aq, opq;
	int res, x, op;

	for (int i = 0; i < N; i++) {
		Aq.push(A[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		opq.push(temp[i]);
	}

	res = Aq.front();
	Aq.pop();

	while (!Aq.empty()) {
		x = Aq.front();
		Aq.pop();

		op = opq.front();
		opq.pop();

		if (op == 0) res += x;
		else if (op == 1) res -= x;
		else if (op == 2) res *= x;
		else res /= x;
	}

	result.push_back(res);
}

void DFS(int cnt) {
	int i, j;

	if (cnt == N - 1) {
		cal();
		return;
	}

	for (i = 0; i < N - 1; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		temp.push_back(op_index[i]);
		DFS(cnt + 1);
		temp.pop_back();
		visited[i] = false;
	}
}

int main() {

	int cnt = 0;

	// 입력 값 저장
	//freopen("input.txt", "r", stdin);

	// 수열 초기화
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < 4; i++) {
		int t;

		cin >> t;

		for (int j = 0; j < t; j++) {
			op_index.push_back(i);
			visited.push_back(false);
		}
	}

	DFS(0);
	answer1 = *max_element(result.begin(), result.end());
	answer2 = *min_element(result.begin(), result.end());

	cout << answer1 << endl << answer2;

	return 0;
}