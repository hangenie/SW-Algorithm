#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long count[2001];

    count[1] = 1;
    count[2] = 2;

    for (int i = 3; i <= n; i++) {
        count[i] = (count[i - 1] + count[i - 2]) % 1234567;
    }


    answer = count[n];

    return answer;
}