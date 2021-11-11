#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt_r, cnt_c;
vector<pair<int, int>> answer;
int map[100][100];
bool visited[100][100];

void initialize() {
	cnt_r = cnt_c = 0;
	answer.clear();
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

void count_r(int r, int c, int cnt) {
	if (map[r][c] == 0) {
		cnt_r = cnt;
		return;
	}

	visited[r + 1][c] = true;
	count_r(r + 1, c, cnt + 1);
}

void count_c(int r, int c, int cnt) {
	if (map[r][c] == 0) {
		cnt_c = cnt;
		return;
	}

	visited[r][c + 1] = true;
	count_c(r, c + 1, cnt + 1);
}

void check(int r, int c) {
	for (int i = 0; i < cnt_r; i++) {
		for (int j = 0; j < cnt_c; j++) {
			visited[r + i][c + j] = true;
		}
	}
}

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first * p1.second == p2.first * p2.second) {
		return p1.first < p2.first;
	}
	else return p1.first * p1.second < p2.first* p2.second;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0 && !visited[i][j]) {
				visited[i][j] = true;
				count_r(i, j, 0);
				count_c(i, j, 0);
				answer.push_back(make_pair(cnt_r, cnt_c));

				// visited 표시
				check(i, j);
			}
		}
	}

	// answer 정렬
	sort(answer.begin(), answer.end(), cmp);
	
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();
		solve();

		printf("#%d %d", testcase, answer.size());
		for (int i = 0; i < answer.size(); i++) {
			printf(" %d %d", answer[i].first, answer[i].second);
		}
		printf("\n");
	}

	return 0;
}