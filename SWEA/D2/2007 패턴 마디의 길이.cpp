#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second < b.second;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		string s;
		map<char, int> m;
		int answer = 0, count;

		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (m.find(s[i]) != m.end()) {
				m[s[i]]++;
			}
			else {
				m.insert(make_pair(s[i], 1));
			}
		}

		// value 기준으로 map 정렬
		vector<pair<char, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), cmp);
		count = v[0].second;

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			iter->second /= count;
			answer += iter->second;
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}