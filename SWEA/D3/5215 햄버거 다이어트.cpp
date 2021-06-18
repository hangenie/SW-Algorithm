#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, answer;
vector<pair<int, int>> ingredient;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

void DFS(int preference, int calorie, int index) {
	for (int i = index; i < N; i++) {
		if (calorie + ingredient[i].second <= L) {
			preference += ingredient[i].first;
			calorie += ingredient[i].second;

			if (answer < preference) answer = preference;

			DFS(preference, calorie, i + 1);
			preference -= ingredient[i].first;
			calorie -= ingredient[i].second;
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N >> L;
		answer = 0;
		ingredient.clear();

		for (int i = 0; i < N; i++) {
			int T, K;
			cin >> T >> K;

			ingredient.push_back(make_pair(T, K));
		}

		sort(ingredient.begin(), ingredient.end(), cmp);

		DFS(0, 0, 0);

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}