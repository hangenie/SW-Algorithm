#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T, testcase, N;
	int height[100], answer;
	int max, min;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> N;
		for (int i = 0; i < 100; i++) {
			cin >> height[i];
		}
		
		for (int i = 0; i < N; i++) {
			max = max_element(height, height + 100) - height;
			min = min_element(height, height + 100) - height;
			
			if (height[max] - height[min] <= 1) {
				break;
			}

			height[max]--;
			height[min]++;
		}

		max = max_element(height, height + 100) - height;
		min = min_element(height, height + 100) - height;
		answer = height[max] - height[min];
		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}