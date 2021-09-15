#include <iostream>
#include <string.h>

using namespace std;

int N;
char word[102];

void in_order(int node) {
	if (word[node * 2] != '0') {
		in_order(node * 2);
	}	
	printf("%c", word[node]);
	if (word[node * 2 + 1] != '0') {
		in_order(node * 2 + 1);
	}
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N;
		memset(word, '0', sizeof(word));

		for (int i = 1; i <= N; i++) {
			char ch;

			cin >> i >> ch;

			if (i <= N / 2) {
				int left, right;

				if (i == N / 2 && N % 2 == 0) {
					cin >> left;
				}
				else {
					cin >> left >> right;
				}

				word[i] = ch;
			}
			else {
				word[i] = ch;
			}
		}

		printf("#%d ", testcase);
		in_order(1);
		printf("\n");
	}

	return 0;
}