#include <iostream>
#include <string>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		string s, word;
		int answer = 0, index = 0;

		cin >> testcase;
		cin >> word >> s;

		index = s.find(word, index);
		while (index != string::npos) {
			answer++;
			index = s.find(word, index + 1);
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}