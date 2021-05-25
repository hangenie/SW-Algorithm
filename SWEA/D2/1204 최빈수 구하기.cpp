#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int T, testcase, score;
	int count[101] = { 0 };

	//freopen("input.txt", "r", stdin);
	cin >> T;


	for (int i = 1; i <= T; i++) {
		cin >> testcase;
		memset(count, 0, sizeof(count));

		for (int j = 0; j < 1000; j++) {
			cin >> score;
			count[score]++;
		}

		int max = max_element(count, count + 101) - count;
		for (int j = max + 1; j < 100; j++) {
			if (count[max] == count[j]) {
				max = j;
			}
		}
		cout << '#' << testcase << ' ' << max << endl;
	}

	return 0;
}