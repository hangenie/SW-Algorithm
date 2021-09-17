#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N = 100;
int answer, answer_x;
int ladder[100][100];
int dx[] = { 0, -1, 1};		// 0: ¾Æ·¡, 1: ¿Þ, 2: ¿À¸¥
int dy[] = { 1, 0, 0 };
queue<int> start;


void initialize() {
	answer = 9901;
	answer_x = -1;
	memset(ladder, 0, sizeof(ladder));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;

			ladder[i][j] = tmp;

			if (i == 0 && tmp == 1) {
				start.push(j);
			}
		}
	}
}

void calculate() {
	int x, y, way, dist;

	while (!start.empty()) {
		int nx;

		x = start.front();
		start.pop();

		nx = x;
		y = 0;
		way = 0;
		dist = 0;


		while (y < N - 1) {
			if (y == 0) {
				nx += dx[way];
				y += dy[way];
				dist++;
				continue;
			}


			if (way == 0) {
				if (nx == 0) {
					if (ladder[y][nx + 1] == 1) {
						way = 2;
					}
				}
				else if (nx == N - 1) {
					if (ladder[y][nx - 1] == 1) {
						way = 1;
					}
				}
				else {
					if (ladder[y][nx - 1] == 1) {
						way = 1;
					}
					else if (ladder[y][nx + 1] == 1) {
						way = 2;
					}
				}
			}
			else {
				if (nx + dx[way] < 0 || y + dy[way] < 0 || nx + dx[way] >= N || y + dy[way] >= N) {
					way = 0;
				}
				else if (ladder[y + dy[way]][nx + dx[way]] == 0) {
					way = 0;
				}
			}
			
			nx += dx[way];
			y += dy[way];
			dist++;
		}

		if (answer > dist) {
			answer = dist;
			answer_x = x;
		}
		else if (answer == dist) {
			if (answer_x < x) {
				answer = dist;
				answer_x = x;
			}
		}

		
	}	
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> testcase;
		initialize();

		calculate();
		
		printf("#%d %d\n", testcase, answer_x);
	}

	return 0;
}