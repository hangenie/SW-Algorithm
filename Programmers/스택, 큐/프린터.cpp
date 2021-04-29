#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;

    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push(make_pair(i, priorities[i]));
    }

    while (!q.empty()) {
        int index = q.front().first;
        int temp = q.front().second;
        q.pop();

        int max = pq.top();

        if (temp != max) {
            q.push(make_pair(index, temp));
        }
        else {
            if (index != location) {
                answer++;
                pq.pop();
            }
            else {
                break;
            }
        }

    }
    return answer;
}