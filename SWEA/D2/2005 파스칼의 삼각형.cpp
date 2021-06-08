#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> v) {
	for (int i = 0; i < v.size();i++) {
		for (int j = 0; j <= i; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N;
		cin >> N;

		vector<vector<int>> triangle(N, vector<int>(N, 0));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) {
					triangle[i][j] = 1;
				}
				else {
					triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
				}

			}
		}

		cout << '#' << testcase << ' ' << endl;
		print(triangle);
	}

	return 0;
}