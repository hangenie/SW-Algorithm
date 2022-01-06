#include <iostream>
#include <string.h>

using namespace std;

bool block[500][500];
bool check[500][500];
int left_block = -1, right_block = -1;

void to_left(int r, int c) {
	int dr, dc;

	dr = r;
	dc = c - 1;

	if (dc < 0) return;

	if (block[dr][dc] == false) {
		check[dr][dc] = true;
		to_left(dr, dc);
	}
	else {
		left_block = dc;
		return;
	}
}

void to_right(int r, int c, int W) {
	int dr, dc;

	dr = r;
	dc = c + 1;

	if (dc >= W) return;

	if (block[dr][dc] == false) {
		check[dr][dc] = true;
		to_right(dr, dc, W);
	}
	else {
		right_block = dc;
		return;
	}
}

int main() {
	int H, W;
	int answer = 0;

	//freopen("input.txt", "r", stdin);
	cin >> H >> W;

	memset(block, false, sizeof(block));
	memset(check, false, sizeof(check));

	for (int i = 0; i < W; i++) {
		int height, cnt = 0;

		cin >> height;

		for (int j = H - 1; cnt < height; j--) {
			block[j][i] = true;
			cnt++;
		}
	}

	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			left_block = -1, right_block = -1;

			if (block[j][i] == false) {
				if (check[j][i] == true) continue;

				check[j][i] = true;

				// 왼쪽으로 벽 확인
				to_left(j, i);
				//오른쪽으로 벽 확인
				to_right(j, i, W);

				if (left_block != -1 && right_block != -1) {
					answer += right_block - left_block - 1;
				}
			}
		}
	}
	
	
	cout << answer << endl;

	return 0;
}