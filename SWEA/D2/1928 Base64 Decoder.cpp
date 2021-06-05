#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		string encoded, decoded;
		vector<int> temp;

		cin >> encoded;

		// Encoding 된 문자열에서 문자마다 값으로 변환
		for (int i = 0; i < encoded.size(); i++) {
			char c = encoded[i];
			char filter = 0x20;
			int t;

			if (c >= 'A' && c <= 'Z') {
				c -= 'A';
				t = 0 + c;
			}
			else if (c >= 'a' && c <= 'z') {
				c -= 'a';
				t = 26 + c;
			}
			else if (c >= '0' && c <= '9') {
				c -= '0';
				t = 52 + c;
			}
			else if (c == '+') {
				t = 62;
			}
			else {
				t = 63;
			}

			// 6비트씩 temp 벡터에 비트값 저장
			for (int j = 0; j < 6; j++) {
				if (t & filter) {
					temp.push_back(1);
				}
				else {
					temp.push_back(0);
				}
				filter >>= 1;
			}

			
		}

		// 8비트씩 읽어 원문 복원
		int dec = 0;
		int hex = 128;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 1) {
				dec += hex * 1;
			}
			else {
				dec += hex * 0;
			}
			hex /= 2;

			if ((i + 1) % 8 == 0) {
				decoded.push_back(char(dec));
				dec = 0;
				hex = 128;
			}
		}


		cout << '#' << testcase << ' ' << decoded << endl;
	}

	return 0;
}