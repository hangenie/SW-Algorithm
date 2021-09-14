#include <iostream>
#include <string.h>

using namespace std;

int tree[1001][3];

int operation(int node) {
	if (tree[node][0] == -1) {
		return operation(tree[node][1]) + operation(tree[node][2]);
	}
	else if (tree[node][0] == -2) {
		return operation(tree[node][1]) - operation(tree[node][2]);
	}
	else if (tree[node][0] == -3) {
		return operation(tree[node][1]) * operation(tree[node][2]);
	}
	else if (tree[node][0] == -4) {
		return operation(tree[node][1]) / operation(tree[node][2]);

	}
	else {
		return tree[node][0];
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 0;

		cin >> N;

		memset(tree, 0, sizeof(tree));

		for (int i = 1; i <= N; i++) {
			int n;
			char ch;

			cin >> n >> ch;


			if (ch >= '0' && ch <= '9') {
				tree[i][0] = 0;

				while (ch != '\n') {
					tree[i][0] = tree[i][0] * 10 + ch - '0';
					ch = cin.get();
				}
			}
			else {
				if (ch == '+') tree[i][0] = -1;
				else if (ch == '-') tree[i][0] = -2;
				else if (ch == '*') tree[i][0] = -3;
				else tree[i][0] = -4;

				cin >> tree[i][1] >> tree[i][2];
			}
		}

		answer = operation(1);


		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}