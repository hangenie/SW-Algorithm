#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int solution(vector<int> people, int limit) {
	int answer = 0;

	int first = 0, last = people.size() - 1;

	sort(people.begin(), people.end(), compare);

	while (first < people.size()) {
		if (people[first] > limit / 2) {
			if (people[first] + people[last] <= limit) {
				answer++;
				first++;
				last--;
			}
			else {
				answer++;
				first++;
			}
		}
		else {
			int remain = last - first + 1;
			if (remain % 2 == 0) {
				answer += remain / 2;
				break;
			}
			else {
				answer += remain / 2 + 1;
				break;
			}
		}
	}


	return answer;
}