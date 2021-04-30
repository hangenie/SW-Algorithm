#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string number = "4177252841";
	int k = 4;
	string answer;

	vector<int> num, temp;
	int max_index;


	for (int i = 0; i < number.size(); i++) {
		num.push_back(number[i] - '0');
		temp.push_back(number[i] - '0');
	}



	while (k > 0) {
		max_index = max_element(temp.begin(), temp.end()) - temp.begin();

		if (max_index > k) {
			// 최댓값 지운 배열에서 다시 최대값 찾기
			temp.erase(temp.begin() + max_index);
		}
		else {
			answer.push_back(num[max_index] + '0');
			k -= max_index;
			num.erase(num.begin(), num.begin() + max_index + 1);
			copy(num.begin(), num.end(), temp.begin());
		}

		if (num.size() == k) {
			num.erase(num.begin(), num.end());
			break;
		}

	}
	
	for (int i = 0; i < num.size(); i++) {
		answer.push_back(num[i] + '0');
	}

	cout << answer;
	return 0;
}