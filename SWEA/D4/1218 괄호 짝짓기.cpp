#include <iostream>
#include <stack>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, answer = 1;
		string str;
		stack<char> s;

		cin >> N >> str;

		for (int i = 0; i < N; i++) {
			char ch;
			ch = str[i];

			if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
				s.push(ch);
			}
			else if (ch == ')') {
				char top;

				if (s.empty()) {
					answer = 0;
					break;
				}

				top = s.top();

				if (top != '(') {
					answer = 0;
					break;
				}

				s.pop();
			}
			else if (ch == '}') {
				char top;
				
				if (s.empty()) {
					answer = 0;
					break;
				}

				top = s.top();

				if (top != '{') {
					answer = 0;
					break;
				}

				s.pop();
			}
			else if (ch == ']') {
				char top;

				if (s.empty()) {
					answer = 0;
					break;
				}

				top = s.top();

				if (top != '[') {
					answer = 0;
					break;
				}

				s.pop();
			}
			else {
				char top;

				if (s.empty()) {
					answer = 0;
					break;
				}

				top = s.top();

				if (top != '<') {
					answer = 0;
					break;
				}

				s.pop();
			}
		}

		if (!s.empty()) {
			answer = 0;
			while (!s.empty()) {
				s.pop();
			}
		}

		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}