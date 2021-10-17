#include <iostream>
#include <string.h>
#define SIZE 100

using namespace std;

int answer, start;
int ladder[SIZE][SIZE];
int dx[] = { 0, -1, 1 };		// 0: À§, 1: ¿Þ, 2: ¿À¸¥
int dy[] = { -1, 0, 0 };

void initialize() {
	answer = -1;
	memset(ladder, 0, sizeof(ladder));
}

void input() {
	int N;

	cin >> N;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> ladder[i][j];

			if (i == SIZE - 1 && ladder[i][j] == 2) {
				start = j;
			}
		}
	}
}

void calculation(int start) {
	int x = start;
	int y = SIZE - 1;
	int way = 0;

	while (y >= 0) {
		if (way == 0) {
			if (x < SIZE - 1 && ladder[y][x + 1] == 1) {
				way = 2;
			}
			
			if (x > 0 && ladder[y][x - 1] == 1) {
				way = 1;
			}
		}
		else if (way == 1) {
			if (ladder[y][x - 1] == 0 || x - 1 < 0) {
				way = 0;
			}
		}
		else {
			if (ladder[y][x + 1] == 0 || x + 1 >= SIZE) {
				way = 0;
			}
		}


		x += dx[way];
		y += dy[way];
	}

	answer = x;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();
		input();

		calculation(start);

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}