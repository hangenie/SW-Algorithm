#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> arr;
vector<bool> selected;
vector<char> temp;
vector<string> all;

int isprime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void permutation(int cnt, int k, int& answer) {
    string num = "";
    if (cnt == k) {
        for (int i = 0; i < temp.size(); i++) {
            num.push_back(temp[i]);
        }

        if (num[0] == '0') {
            return;
        }
        for (int i = 0; i < all.size(); i++) {
            if (all[i] == num) {
                return;
            }
        }
        all.push_back(num);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (selected[i] == true) {
            continue;
        }

        selected[i] = true;
        temp.push_back(arr[i]);
        permutation(cnt + 1, k, answer);
        temp.pop_back();
        selected[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    for (int i = 0; i < numbers.size(); i++) {
        arr.push_back(numbers[i]);
        selected.push_back(false);
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= arr.size(); i++) {
        permutation(0, i, answer);
    }

    for (int i = 0; i < all.size(); i++) {
        answer += isprime(stoi(all[i]));
    }

    return answer;
}