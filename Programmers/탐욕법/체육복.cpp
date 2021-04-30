#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	answer = n - lost.size();

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int i = 0; i < reserve.size(); i++) {
		for (int j = 0; j < lost.size(); j++) {
			if (reserve[i] == lost[j]) {
				reserve[i] = -1;
				lost[j] = -1;
				answer++;
				break;
			}
			else if (reserve[i] < lost[j]) break;
		}
	}

	for (int i = 0; i < reserve.size(); i++) {
		if (reserve[i] != -1) {
			for (int j = 0; j < lost.size(); j++) {
				if (lost[j] != -1) {
					if (reserve[i] - 1 == lost[j]) {
						answer++;
						lost[j] = -1;
						break;
					}
					else if (reserve[i] + 1 == lost[j]) {
						answer++;
						lost[j] = -1;
						break;
					}
				}
			}
		}
	}

	return answer;
}