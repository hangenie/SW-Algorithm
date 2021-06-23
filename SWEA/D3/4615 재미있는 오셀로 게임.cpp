#include <iostream>
#include <vector>

using namespace std;

int N;
int board[9][9];
vector<pair<int, int>> positions;
vector<int> colors;

void initialize() {
	positions.clear();
	colors.clear();

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			board[i][j] = 0;
		}
	}
	board[N / 2][N / 2] = 2;
	board[N / 2][N / 2 + 1] = 1;
	board[N / 2 + 1][N / 2] = 1;
	board[N / 2 + 1][N / 2 + 1] = 2;
}

void reverse(int r, int c, int color) {
	int dr[] = { -1,1,0,0,-1,1,-1,1 };
	int dc[] = { 0,0,-1,1,1,1,-1,-1 };

	for (int i = 0; i < 8; i++) {
		int nr = r, nc = c;
		while (1) {
			nr += dr[i];
			nc += dc[i];

			if (nr <= 0 || nr > N || nc <= 0 || nc > N) break;
			
			if (board[nr][nc] == 0) break;

			if (board[nr][nc] == color) {
				while (nr != r || nc != c) {
					nr -= dr[i];
					nc -= dc[i];

					board[nr][nc] = color;
				}

				break;
			}
		}
	}
	
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int M, black = 0, white = 0, r, c, color;

		cin >> N >> M;

		initialize();

		for (int i = 0; i < M; i++) {
			cin >> c >> r >> color;
			positions.push_back(make_pair(r, c));
			colors.push_back(color);
		}
		
		for (int i = 0; i < M; i++) {
			r = positions[i].first;
			c = positions[i].second;
			color = colors[i];

			board[r][c] = color;
			reverse(r, c, color);
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 1) {
					black++;
				}
				else if (board[i][j] == 2) {
					white++;
				}
			}
		}


		cout << '#' << testcase << ' ' << black << ' ' << white << endl;
	}

	return 0;
}