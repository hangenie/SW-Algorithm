#include <iostream>
#include <vector>

using namespace std;

void print(string s[]) {
	for (int i = 0; i < 10; i++) {
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
			int x, y;
			vector<string> s;

			cin >> m >> x >> y;

			for (int i = 0; i < y; i++) {
				string temp;
				cin >> temp;
				s.push_back(temp);
			}

			if (x > 10) continue;
			else {
				for (int i = 0; i < y && x + i <= 10; i++) {
					cipher.insert(cipher.begin() + x + i, s[i]);
				}
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