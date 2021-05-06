//#pragma warning (disable:4996)
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int K, N;
	vector<int> arr;
	long long int answer = 0;

	long long int start, end, mid;
	long long int cnt = 0;
	long long int max = 0;

	//freopen("input.txt", "r", stdin);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long int num;

		cin >> num;
		arr.push_back(num);

		if (max < num) {
			max = num;
		}
	}


	start = 1;
	end = max;
	
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 0;

		for (int i = 0; i < K; i++) {
			cnt += arr[i] / mid;
 		}

		if (cnt < N) {
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