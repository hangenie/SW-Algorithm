#include <iostream>
#include <string>
using namespace std;

int check(string s, int left, int right, int len) {
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
            len += 2;
        }
        else return 0;
    }

    if (left == right) len++;

    return len;
}

int solution(string s)
{
    int answer = 1;
    int len = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = s.size() - 1; j > i; j--) {
            if (s[i] == s[j]) {
                if (len > j - i + 1) continue;

                len = check(s, i + 1, j - 1, 2);
                if (answer < len) answer = len;
            }
        }
    }

    return answer;
}