#include <iostream>
#include <string.h>

using namespace std;

int answer;
int route[100][2];

void DFS(int index) {
	if (index == 99) {
		answer = 1;
		return;
	}

	for (int i = 0; i <= 1; i++) {
		if (route[index][i] != -1) {
			DFS(route[index][i]);
		}
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N;

		cin >> testcase >> N;

		answer = 0;
		memset(route, -1, sizeof(route));

		for (int i = 0; i < N; i++) {
			int index, dest;

			cin >> index >> dest;

			if (route[index][0] == -1) {
				route[index][0] = dest;
			}
			else {
				route[index][1] = dest;
			}
		}

		DFS(0);


		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}