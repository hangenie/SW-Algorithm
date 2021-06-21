#include <iostream>

using namespace std;

int main() {
	bool num[1000001] = { false };
	
	for (int i = 2; i <= 1000; i++) {
		if (num[i]) continue;

		for (int j = i + i; j <= 1000000; j+=i) {
			num[j] = true;
		}
	}

	for (int i = 2; i <= 1000000; i++) {
		if (!num[i]) {
			cout << i << ' ';
		}
	}

	return 0;
}