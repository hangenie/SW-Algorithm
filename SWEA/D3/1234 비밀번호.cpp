#include <iostream>
#include <string>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, i = 0;
		string password;
		cin >> N >> password;

		while (i < N - 1) {
			if (password[i] == password[i + 1]) {
				password.erase(i, 2);
				if (i - 1 >= 0) i -= 1;
				N = password.size();
			}
			else {
				i++;
			}
		}
		

		cout << '#' << testcase << ' ' << password << endl;
	}

	return 0;
}