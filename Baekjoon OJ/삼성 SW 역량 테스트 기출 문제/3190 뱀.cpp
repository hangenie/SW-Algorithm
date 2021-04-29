//#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
	int N, K, L, X;
	char C;
	int second = 0;

	queue<pair<int, char>> turn;
	vector<pair<int, int>> snake;
	char snake_way = 'D';
	map<char, pair<int, int>> m;
	pair<int, int> position;
	int flag = 0;

	// �Է� �� ����
	//freopen("input.txt", "r", stdin);

	// ���� �ʱ�ȭ
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));

	// ���忡 ��� ��ġ ǥ��
	cin >> K;
	for (int i = 0; i < K; i++) {
		int row, col;

		cin >> row >> col;
		board[row - 1][col - 1] = 1;
	}

	// ���� ��ȯ ���� ����
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		turn.push(make_pair(X, C));
	}

	// ���� �Ӹ� ��ġ �ʱ�ȭ
	snake.push_back(make_pair(0, 0));

	// ���� ���� ����
	m['U'] = make_pair(0, -1);
	m['B'] = make_pair(0, 1);
	m['L'] = make_pair(-1, 0);
	m['D'] = make_pair(1, 0);

	while (1) {
		flag = 0;
		second++;

		// �� �̵�
		position = snake.front();
		position.first += m[snake_way].first;
		position.second += m[snake_way].second;

		// ���� ���� ���� Ȯ��
		if (position.first == N || position.second == N || position.first < 0 || position.second < 0) {
			break;
		}
		for (int i = 1; i < snake.size(); i++) {
			if (position.first == snake[i].first && position.second == snake[i].second) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

		// ���� �̵��� ĭ�� ����� �ִ��� Ȯ��
		if (board[position.second][position.first] == 1) {
			board[position.second][position.first] = 0;
			snake.insert(snake.begin(), position);
		}
		else {
			snake.insert(snake.begin(), position);
			snake.erase(snake.end() - 1);
		}

		// ���� ��ȯ ���� Ȯ��
		if (!turn.empty()) {
			int sec = turn.front().first;
			int way = turn.front().second;

			if (sec == second) {
				if (way == 'D') {
					switch (snake_way) {
					case 'U':
						snake_way = 'D';
						break;
					case 'B':
						snake_way = 'L';
						break;
					case 'L':
						snake_way = 'U';
						break;
					case 'D':
						snake_way = 'B';
						break;
					}
				}
				else if (way == 'L') {
					switch (snake_way) {
					case 'U':
						snake_way = 'L';
						break;
					case 'B':
						snake_way = 'D';
						break;
					case 'L':
						snake_way = 'B';
						break;
					case 'D':
						snake_way = 'U';
						break;
					}
				}

				turn.pop();
			}
		}
	}

	cout << second;

	return 0;
}