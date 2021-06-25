#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int win, lose, kyu_score, in_score;
int kyu_card[9], in_card[9];
bool visited[9];

void initialize() {
	int index = 0;
	bool check[19] = { false };

	win = 0;
	lose = 0;
	kyu_score = 0;
	in_score = 0;

	for (int i = 0; i < 9; i++) {
		cin >> kyu_card[i];
		check[kyu_card[i]] = true;
		visited[i] = false;
	}

	for (int i = 1; i <= 18; i++) {
		if (!check[i]) {
			in_card[index++] = i;
		}
	}

	sort(in_card, in_card + 9);
}

void DFS(int kyu_score, int in_score, int kyu_index, int cnt) {
	if (kyu_score > 85 || in_score > 85) {
		int result = 1;

		for (int i = kyu_index; i < 9; i++) {
			result *= 9 - i;
		}

		if (kyu_score > 85) {
			win += result;
		}
		else {
			lose += result;
		}

		return;
	}


	for (int i = 0; i < 9; i++) {
		int k_s, i_s;

		if (visited[i] == true) continue;

		if (kyu_card[kyu_index] > in_card[i]) {
			k_s = kyu_card[kyu_index] + in_card[i];
			i_s = 0;
		}
		else if (kyu_card[kyu_index] < in_card[i]) {
			k_s = 0;
			i_s = kyu_card[kyu_index] + in_card[i];
		}

		visited[i] = true;
		DFS(kyu_score + k_s, in_score + i_s, kyu_index + 1, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		initialize();

		DFS(0, 0, 0, 0);

		cout << '#' << testcase << ' ' << win << ' ' << lose << endl;
	}

	return 0;
}