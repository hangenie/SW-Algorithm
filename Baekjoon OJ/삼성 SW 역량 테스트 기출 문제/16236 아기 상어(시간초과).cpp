#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int space[20][20];
int shark_r, shark_c, shark_size, shark_cnt;

// 상하좌우 방향
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int min_distance;

vector<pair<int, pair<int, int>>> fishes;

void print(vector<pair<int, pair<int, int>>> v) {
	for (auto iter : v) {
		cout << iter.first << ' ' << iter.second.first << ' ' << iter.second.second << endl;
	}
	cout << endl;
}

void initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (space[i][j] == -1) {
				space[i][j] = 0;
			}
		}
	}

	fishes.clear();
	min_distance = 40;
}

void find() {
	int distance, r, c;
	queue<pair<int, pair<int, int>>> q;

	q.push(make_pair(0, make_pair(shark_r, shark_c)));

	while (!q.empty()) {
		distance = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			int nd = distance + 1;

			if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
				continue;
			}
			if (space[nr][nc] == -1) {
				continue;
			}

			if (space[nr][nc] == 0) {
				space[nr][nc] = -1;
				q.push(make_pair(nd, make_pair(nr, nc)));
			}
			else if (space[nr][nc] >= 1 && space[nr][nc] <= 6) {
				if (space[nr][nc] > shark_size) {
					continue;
				}
				else if (space[nr][nc] == shark_size) {
					q.push(make_pair(nd, make_pair(nr, nc)));
				}
				else {
					if (min_distance >= nd) {
						min_distance = nd;
						fishes.push_back(make_pair(nd, make_pair(nr, nc)));
					}
					
				}
			}
		}
	}
}

bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		return a.second.first < b.second.first;
	}

	return a.first < b.first;
}

int main() {
	int answer = 0;

	freopen("input.txt", "r", stdin);
	cin >> N;

	shark_size = 2;
	shark_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			space[i][j] = n;

			if (n == 9) {
				shark_r = i;
				shark_c = j;
			}
		}
	}
	min_distance = 40;

	while (1) {
		// 먹을 수 있는 물고기 찾기
		find();

		if (fishes.empty()) {
			break;
		}

		// 구한 물고기 정렬
		sort(fishes.begin(), fishes.end(), cmp);
		print(fishes);

		space[shark_r][shark_c] = -1;
		answer += fishes[0].first;
		shark_r = fishes[0].second.first;
		shark_c = fishes[0].second.second;
		space[shark_r][shark_c] = 9;
		shark_cnt++;

		if (shark_cnt == shark_size) {
			shark_size++;
			shark_cnt = 0;
		}

		initialize();
	}

	cout << answer << endl;

	return 0;
}