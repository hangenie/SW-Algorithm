#include <iostream>
#include <string>

using namespace std;

string convert[10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };

int main() {
	int T, testcase;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		int N, M, answer = 0;
		cin >> N >> M;

		string arr[50];


		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		//암호코드 있는 위치 찾기
		for (int i = 0; i < N; i++) {
			string code, num;
			int number[8];
			int index = 0, l = 0, sum = 0, temp = 0;
			bool flag = false;
			

			for (int j = M - 1; j >= 0; j--) {
				if (arr[i][j] == '1') {
					index = j;
					break;
				}
			}

			if (index < 55) continue;

			for (int j = index - 55; j <= index; j++) {
				code.push_back(arr[i][j]);
			}


			//7칸씩 끊어 숫자변환
			for (int j = 0; j < 56; j += 7) {
				num = code.substr(j, 7);

				for (int k = 0; k < 10; k++) {
					if (convert[k] == num) {
						number[l++] = k;
						break;
					}

					//변환되는 숫자가 없을 경우
					if (k == 9) {
						flag = true;
					}
				}

				if (flag == true) break;
			}

			if (flag == true) break;


			//정상코드인지 확인
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0) {
					temp += number[j];
				}
				else {
					sum += number[j];
				}
			}
			sum += temp * 3;

			if (sum % 10 == 0) {
				sum -= temp * 2;
				answer = sum;	
			}
			flag = true;

			if (flag == true) break;

		}
		cout << '#' << testcase << ' ' << answer << endl;
	}

	return 0;
}