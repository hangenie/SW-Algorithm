#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;

	//freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string s = to_string(i);
		string cnt;

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '3' || s[j] == '6' || s[j] == '9') {
				cnt.push_back('-');
			}
		}

		if (cnt.size() == 0) {
			cout << i << ' ';
		}
		else {
			cout << cnt << ' ';
		}
	}

	cout << endl;

	return 0;
}