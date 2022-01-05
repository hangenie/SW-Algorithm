#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cal_divisor(int num, vector<int>& v) {
	for (int i = 1; i <= num; i++) {
		if (num % i == 0)
			v.push_back(i);
	}

	return;
}

int cal_max(vector<int> a, vector<int> b) {
	int divisor = 1;

	for (int i = 1; i < a.size(); i++) {
		if (find(b.begin(), b.end(), a[i]) != b.end()) {
			if (a[i] > divisor) {
				divisor = a[i];
			}
		}
	}

	return divisor;
}

int main() {
	int n, m;
	int divisor, multiple;
	vector<int> nd, md;

	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	if (m < n) {
		swap(n, m);
	}
	
	// 약수 구하기
	cal_divisor(n, nd);
	cal_divisor(m, md);

	// 최대공약수 구하기
	if (nd.size() <= md.size()) divisor = cal_max(nd, md);
	else divisor = cal_max(md, nd);

	multiple = divisor * (n / divisor) * (m / divisor);

	cout << divisor << endl;
	cout << multiple << endl;


	return 0;
}