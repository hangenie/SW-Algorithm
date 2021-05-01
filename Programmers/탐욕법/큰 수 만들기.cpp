#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	stack<char> s;
	int answer_size = number.size() - k;

	s.push(number[0]);

	// ���ڿ� ������� ���ÿ� ����
	// ���� �󿡼� ������ ������ ���� ���� ����
	// ������ �� ���� k ����, �־��� k ����ŭ�� �����ϵ��� ���� ����� ��
	// k�� 0�� �Ǹ� ���� �Ұ�, ���Ը� ����
	for (int i = 1; i < number.size(); i++) {
		if (s.top() < number[i] && k > 0) {
			while (!s.empty() && s.top() < number[i]) {
				s.pop();
				k--;

				if (k == 0) {
					break;
				}
			}
			s.push(number[i]);
		}
		else {
			s.push(number[i]);
		}
	}

	// ������ �Ǿ�� �� ���ڿ��� ���̺��� ������ �� ��� ����� ���, �߶���� ��
	while (s.size() > answer_size) {
		s.pop();
	}

	// ���ÿ� ����� ���� �Ųٷ� answer�� ����
	while (!s.empty()) {
		answer.insert(answer.begin(), s.top());
		s.pop();
	}


	return answer;
}