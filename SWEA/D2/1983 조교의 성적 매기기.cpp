#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string grade[] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

bool cmp(const pair<int, float>& a, const pair<int, float>& b) {
	return a.second > b.second;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, K;
		cin >> N >> K;

		string answer;
		int index;
		vector<pair<int, float>> score;

		for (int i = 0; i < N; i++) {
			int mid, final, assignment;
			cin >> mid >> final >> assignment;

			score.push_back(make_pair(i + 1, mid * 0.35 + final * 0.45 + assignment * 0.20));
		}

		sort(score.begin(), score.end(), cmp);
		for (int i = 0; i < N; i++) {
			if (score[i].first == K) {
				index = i;
				break;
			}
		}

		answer = grade[index / (N / 10)];

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}