//#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int lab[8][8];
int lab_w[8][8];	// 벽 세울 때 표시할 배열
int lab_v[8][8];	// 바이러스 퍼뜨릴 때 표시할 배열

vector<pair<int, int>> virus;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> safe;	// 벽 세운 경우마다 계산한 안전영역 수 저장 배열

void copymap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			lab_w[i][j] = lab[i][j];
		}
	}
}

void counting() {
	int cnt = 0, max;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab_v[i][j] == 0) {
				cnt++;
			}
		}
	}

	if (!safe.empty()) {
		max = *max_element(safe.begin(), safe.end());
		if (cnt > max) {
			safe.push_back(cnt);
		}
	}
	else {
		safe.push_back(cnt);
	}
}

// 바이러스 퍼뜨리기
void BFS() {
	queue<pair<int, int>> q;
	int max;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			lab_v[i][j] = lab_w[i][j];
		}
	}

	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (lab_v[nx][ny] == 0) {
				lab_v[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	// 안전 영역 세기
	counting();

}

// 벽 3개 세우기
void DFS(int cnt) {
	if (cnt == 3) {
		// 바이러스 퍼뜨리기
		BFS();

		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab_w[i][j] == 0) {
				lab_w[i][j] = 1;
				DFS(cnt + 1);
				lab_w[i][j] = 0;
			}
		}
	}
}

int main() {
	int answer = 0;

	int cnt = 0;

	// 입력 값 저장
	//freopen("input.txt", "r", stdin);

	// 능력치 배열 초기화
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];

			if (lab[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 0) {
				copymap();

				lab_w[i][j] = 1;
				DFS(cnt + 1);
				lab_w[i][j] = 0;
			}
		}
	}

	answer = *max_element(safe.begin(), safe.end());

	cout << answer;

	return 0;
}