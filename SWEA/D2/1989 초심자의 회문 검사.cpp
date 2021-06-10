#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int answer = 1, length;
		string word;

		cin >> word;
		length = word.size();

		for (int i = 0; i < length - length / 2; i++) {
			if (word[i] != word[length - i - 1]) {
				answer = 0;
				break;
			}
		}		

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}