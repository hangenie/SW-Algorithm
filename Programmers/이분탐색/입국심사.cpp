#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long int start, end, mid;
    long long int cnt = 0;

    start = 1;
    end = static_cast<long long int>(n) * static_cast<long long int>(*max_element(times.begin(), times.end()));
    answer = end;

    while (start <= end) {
        mid = (start + end) / 2;
        cnt = 0;

        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }

        if (cnt < n) {
            start = mid + 1;
        }
        else {
            if (answer > mid) {
                answer = mid;
            }
            end = mid - 1;
        }
    }

    return answer;
}