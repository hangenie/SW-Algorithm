#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int win, lose, kyu_score, in_score;
vector<int> kyu_card, in_card;
vector<bool> visited;

void initialize() {
	win = 0;
	lose = 0;
	kyu_score = 0;
	in_score = 0;

	kyu_card.clear();
	in_card.clear();
	visited.clear();

	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;

		kyu_card.push_back(temp);
		visited.push_back(false);
	}

	for (int i = 1; i <= 18; i++) {
		if (find(kyu_card.begin(), kyu_card.end(), i) == kyu_card.end()) {
			in_card.push_back(i);
		}
	}

	sort(in_card.begin(), in_card.end());
}

void DFS(int kyu_score, int in_score, int kyu_index, int cnt) {
	if (cnt == 9) {
		if (kyu_score > in_score) win++;
		else if (kyu_score < in_score) lose++;

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