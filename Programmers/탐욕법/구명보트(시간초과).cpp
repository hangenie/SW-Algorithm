#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int solution(vector<int> people, int limit) {
	int answer = 0;

	vector<int> check;
	int sum = 0;
	int i = 0;

	for (int i = 0; i < people.size(); i++) {
		check.push_back(1);
	}

	sort(people.begin(), people.end(), compare);

	for (int i = 0; i < people.size(); i++) {
		int j;
		if (check[i] == -1) continue;

		if (people[i] > limit / 2) {
			for (j = i + 1; j < people.size(); j++) {
				if (check[j] == -1) continue;

				if (people[j] <= limit - people[i]) {
					answer++;
					check[i] = -1;
					check[j] = -1;
					break;
				}
			}
			if (j == people.size()) {
				answer++;
				check[i] = -1;
			}
		}
		else {
			if (i == people.size() - 1) {
				answer++;
				break;
			}
			else {
				for (j = i + 1; j < people.size(); j++) {
					if (check[j] != -1) {
						check[j] = -1;
						break;
					}
				}
				answer++;
				check[i] = -1;

			}
		}
	}

	return answer;
}