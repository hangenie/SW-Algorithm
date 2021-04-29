#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    int cnt = 0, i;

    sort(citations.begin(), citations.end(), greater<int>());
    for (int h = citations[0]; h >= 0; h--) {
        cnt = 0;
        for (i = 0; i < citations.size(); i++) {
            if (h <= citations[i]) {
                cnt++;
            }
            else break;
        }

        if (h <= cnt) {
            answer = h;
            break;
        }
    }

    return answer;
}