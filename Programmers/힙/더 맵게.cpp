#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    int m[2];

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (pq.top() < K) {
        for (int i = 0; i < 2; i++) {
            if (!pq.empty()) {
                m[i] = pq.top();
                pq.pop();
            }
            else {
                answer = -1;
            }
        }

        if (m[0] == 0 && m[1] == 0) {
            answer = -1;
        }

        if (answer == -1) break;

        pq.push(m[0] + m[1] * 2);
        answer++;
    }

    return answer;
}