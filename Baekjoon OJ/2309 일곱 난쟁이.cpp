#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int height[9];
bool flag;
vector<int> dwarf;

void DFS(int index, int sum, int count) {
	if (count == 7) {
		if (sum == 100) {
			flag = true;
		}
		return;
	}

	for (int i = index; i < 9; i++) {
		dwarf.push_back(height[i]);
		DFS(i + 1, sum + height[i], count + 1);
		if (flag == true) {
			return;
		}
		dwarf.pop_back();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}
	flag = false;

	sort(height, height + 9);

	DFS(0, 0, 0);

	for (int i = 0; i < 7; i++) {
		cout << dwarf[i] << endl;
	}

	return 0;
}