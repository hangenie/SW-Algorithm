//#pragma warning (disable:4996)
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	vector<int> arr;
	int answer = 0;

	long long int start, end, mid;
	long long int cnt = 0;
	int max = 0;

	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;

		cin >> num;
		arr.push_back(num);

		if (max < num) {
			max = num;
		}
	}


	start = 0;
	end = max;
	
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 0;

		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				cnt += arr[i] - mid;
			}
 		}

		if (cnt < M) {
			end = mid - 1;
		}
		else {
			if (answer < mid) {
				answer = mid;
			}
			start = mid + 1;
		}
	}


	cout << answer << endl;

	return 0;
}