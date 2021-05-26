#include <iostream>
#include <vector>

using namespace std;

int main() {
	int testcase, N;

	//freopen("input.txt", "r", stdin);

	vector<int> buildings;
	int answer = 0;

	for (testcase = 1; testcase <= 10; testcase++) {
		cin >> N;

		buildings.clear();
		answer = 0;

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			buildings.push_back(temp);
		}

		for (int i = 2; i <= N - 3; i++) {
			for (int j = buildings[i]; j >= 1; j--) {
				if (j > buildings[i - 1] && j > buildings[i + 1]) {
					if (j > buildings[i - 2] && j > buildings[i + 2]) {
						answer++;
					}
					else break;
				}
				else break;
			}
		}

		
		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}