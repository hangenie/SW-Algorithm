#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

vector<char> formula;
map<char, int> priority;
stack<char> ts;
stack<int> cs;

void transform(int len) {
	char c;

	for (int i = 0; i < len; i++) {
		cin >> c;

		if (c >= '0' && c <= '9') {
			formula.push_back(c);
		}
		else {
			if (ts.empty()) {
				ts.push(c);
			}
			else {
				while (!ts.empty()) {
					if (priority[c] >= priority[ts.top()]) {
						formula.push_back(ts.top());
						ts.pop();
					}
					else break;
				}
				ts.push(c);
			}
		}

	}

	while (!ts.empty()) {
		formula.push_back(ts.top());
		ts.pop();
	}
}

int calculate() {
	int answer, n1, n2;
	char c;

	for (int i = 0; i < formula.size(); i++) {
		c = formula[i];

		if (c >= '0' && c <= '9') {
			cs.push(c - '0');
		}
		else if (c == '+') {
			n2 = cs.top();
			cs.pop();
			n1 = cs.top();
			cs.pop();

			cs.push(n1 + n2);
		}
		else {
			n2 = cs.top();
			cs.pop();
			n1 = cs.top();
			cs.pop();

			cs.push(n1 * n2);
		}
	}

	answer = cs.top();
	cs.pop();

	return answer;
}

int main() {
	int T, testcase, answer;

	//freopen("input.txt", "r", stdin);
	T = 10;
	
	priority.insert(make_pair('+', 2));
	priority.insert(make_pair('*', 1));

	for (testcase = 1; testcase <= T; testcase++) {
		int len, answer;
		formula.clear();

		cin >> len;

		transform(len);
		answer = calculate();


		printf("#%d %d\n", testcase, answer);
	}

	return 0;
}


