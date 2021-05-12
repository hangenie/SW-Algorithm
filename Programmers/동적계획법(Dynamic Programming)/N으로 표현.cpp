#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int solution(int N, int number) {
	int answer = -1;

	vector<set<int>> arr(8);

	if (N == number) {
		answer = 1;
		return answer;
	}

	for (int i = 0; i < 8; i++) {
		int n = 0;
		int digit = i + 1;
		while (digit > 0) {
			digit--;
			n += N * pow(10, digit);
		}
		arr[i].insert(n);
	}

	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			for (auto& x : arr[j]) {
				for (auto& y : arr[i - j - 1]) {
					arr[i].insert(x + y);
					arr[i].insert(x - y);
					arr[i].insert(x * y);
					if (y != 0) {
						arr[i].insert(x / y);
					}
				}
			}
		}

		if (arr[i].find(number) != arr[i].end()) {
			answer = i + 1;
			break;
		}
	}

	return answer;
}