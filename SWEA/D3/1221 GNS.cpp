#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string num_s[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, index;
		int num[10] = { 0 };
		char sharp;

		cin >> sharp >> testcase;
		getchar();
		cin>> N;

		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;

			index = find(num_s, num_s + 10, s) - num_s;
			num[index]++;
		}

		cout << '#' << testcase << endl;
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < num[i]; j++) {
				cout << num_s[i] << ' ';
			}
		}
	}

	return 0;
}