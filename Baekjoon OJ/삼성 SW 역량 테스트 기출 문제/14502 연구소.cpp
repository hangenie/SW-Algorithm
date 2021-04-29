//#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int lab[8][8];
int lab_w[8][8];	// �� ���� �� ǥ���� �迭
int lab_v[8][8];	// ���̷��� �۶߸� �� ǥ���� �迭

vector<pair<int, int>> virus;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> safe;	// �� ���� ��츶�� ����� �������� �� ���� �迭

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

// ���̷��� �۶߸���
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

	// ���� ���� ����
	counting();

}

// �� 3�� �����
void DFS(int cnt) {
	if (cnt == 3) {
		// ���̷��� �۶߸���
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

	// �Է� �� ����
	//freopen("input.txt", "r", stdin);

	// �ɷ�ġ �迭 �ʱ�ȭ
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