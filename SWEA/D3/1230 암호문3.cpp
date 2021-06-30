#include <iostream>
#include <vector>

using namespace std;

void insert(vector<string>& cipher) {
	int x, y;
	vector<string> s;

	cin >> x >> y;

	for (int i = 0; i < y; i++) {
		string temp;
		cin >> temp;
		s.push_back(temp);
	}

	for (int i = 0; i < y; i++) {
		cipher.insert(cipher.begin() + x + i, s[i]);
	}
}

void erase(vector<string>& cipher) {
	int x, y;

	cin >> x >> y;

	for (int i = 0; i < y; i++) {
		cipher.erase(cipher.begin() + x);
	}
}

void add(vector<string>& cipher) {
	int y;
	vector<string> s;

	cin >> y;

	for (int i = 0; i < y; i++) {
		string temp;
		cin >> temp;
		s.push_back(temp);
	}

	for (int i = 0; i < y; i++) {
		cipher.push_back(s[i]);
	}
}

void print(string s[]) {
	for (int i = 0; i < 10;i++) {
		cout << s[i] << ' ';
	}
	cout << endl;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, M;
		vector<string> cipher;
		string answer[10];

		cin >> N;

		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			cipher.push_back(temp);
		}

		cin >> M;

		for (int i = 0; i < M; i++) {
			char m;
			cin >> m;

			if (m == 'I') {
				insert(cipher);
			}
			else if (m == 'D') {
				erase(cipher);
			}
			else {
				add(cipher);
			}
		}

		for (int i = 0; i < 10; i++) {
			answer[i] = cipher[i];
		}
	

		printf("#%d ", testcase);
		print(answer);
	}

	return 0;
}