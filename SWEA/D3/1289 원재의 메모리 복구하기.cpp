#include <iostream>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		string memory;
		char state = '0';
		int answer = 0;

		cin >> memory;

		for (int i = 0; i < memory.size(); i++) {
			if (state != memory[i]) {
				answer++;
				if (state == '0') state = '1';
				else state = '0';
			}
		}

		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}