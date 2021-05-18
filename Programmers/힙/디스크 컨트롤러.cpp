#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int time = -1, state = -1, cnt = 0;
    int i = 0, sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    sort(jobs.begin(), jobs.end());

    while (1) {
        time++;
        cnt++;

        // 작업 완료 확인
        if (state != -1 && cnt == jobs[state][1]) {
            sum += time - jobs[state][0];
            state = -1;

            if (pq.empty() && i == jobs.size()) {
                break;
            }
        }

        if (state == -1) {
            if (pq.empty()) {
                if (jobs[i][0] <= time) {
                    state = i++;
                    cnt = 0;
                }
                else {
                    continue;
                }
            }
            else {
                state = pq.top().second;
                cnt = 0;
                pq.pop();
            }
        }
        else {
            if (i < jobs.size() && jobs[i][0] <= time) {
                pq.push(make_pair(jobs[i][1], i));
                i++;
            }
        }


    }

    answer = sum / jobs.size();


    return answer;
}