#include <string>
#include <vector>

using namespace std;

int count_ones(int num) {
    int count = 0;

    while (num > 0) {
        if (num % 2 == 1) count++;
        num /= 2;
    }

    return count;
}

int solution(int n) {
    int answer = 0;
    int n_cnt;

    n_cnt = count_ones(n);

    while (1) {
        int cnt;

        n += 1;
        cnt = count_ones(n);

        if (cnt == n_cnt) {
            answer = n;
            break;
        }
    }

    return answer;
}