#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[]) {
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (testcase = 1; testcase <= T; testcase++) {
		cin >> testcase;

		int data[8], answer[8];
		int index = 0, num = 1, j = 0;

		for (int i = 0; i < 8; i++) {
			cin >> data[i];
		}

		
		while (1) {
			data[index] -= num;
			if (data[index] <= 0) {
				data[index] = 0;
				break;
			}

			if (num == 5) num = 1;
			else num++;

			if (index == 7) index = 0;
			else index++;
		}

		index = find(data, data + 8, 0) - data;
		for (int i = index + 1; i < 8; i++) {
			answer[j++] = data[i];
		}
		for (int i = 0; i <= index; i++) {
			answer[j++] = data[i];
		}

		cout << '#' << testcase << ' ';
		print(answer);
	}

	return 0;
}