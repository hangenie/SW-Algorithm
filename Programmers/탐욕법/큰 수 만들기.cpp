#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	stack<char> s;
	int answer_size = number.size() - k;

	s.push(number[0]);

	// 문자열 순서대로 스택에 삽입
	// 스택 상에서 삽입할 값보다 작은 수는 제거
	// 삭제할 때 마다 k 감소, 주어진 k 개만큼만 삭제하도록 조건 명시할 것
	// k가 0이 되면 삭제 불가, 삽입만 수행
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

	// 정답이 되어야 할 문자열의 길이보다 스택이 더 길게 저장된 경우, 잘라줘야 됨
	while (s.size() > answer_size) {
		s.pop();
	}

	// 스택에 저장된 값을 거꾸로 answer에 저장
	while (!s.empty()) {
		answer.insert(answer.begin(), s.top());
		s.pop();
	}


	return answer;
}