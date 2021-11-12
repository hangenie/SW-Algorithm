#include <string>
#include <vector>
#include <queue>

using namespace std;

long long work(int n, priority_queue<int> pq) {
    long long answer = 0;

    while (n > 0) {
        int top;

        top = pq.top();
        pq.pop();

        pq.push(--top);
        n--;

    }


    while (!pq.empty()) {
        int top;

        top = pq.top();
        pq.pop();

        answer += (top * top);
    }

    return answer;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    priority_queue<int> pq;

    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
        sum += works[i];
    }


    if (sum < n) {
        answer = 0;
    }
    else {
        answer = work(n, pq);
    }


    return answer;
}