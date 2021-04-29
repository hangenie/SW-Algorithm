#include <string>
#include <vector>
#include <queue>

using namespace std;

int check(queue<int> q, int target) {
    int answer = 0;
    int n;

    while (!q.empty()) {
        n = q.front();
        q.pop();

        if (n == target) {
            answer++;
        }
    }

    return answer;
}

void BFS(vector<int> numbers, int target, int& answer) {
    queue<int> q;
    int cnt = 2, n;

    q.push(1 * numbers[0]);
    q.push(-1 * numbers[0]);

    for (int i = 1; i < numbers.size(); i++) {
        for (int j = 0; j < cnt; j++) {
            n = q.front();
            q.pop();

            q.push(n + numbers[i]);
            q.push(n - numbers[i]);
        }
        cnt *= 2;
    }

    answer = check(q, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    BFS(numbers, target, answer);

    return answer;
}