#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int temp, cnt = 0;
    int size = progresses.size();
    stack<int> s;

    for (int i = 0; i < size; i++) {
        temp = 100 - progresses[size - 1 - i];
        cnt = 0;
        while (temp > 0) {
            temp -= speeds[size - 1 - i];
            cnt++;
        }
        s.push(cnt);
    }

    while (!s.empty()) {
        temp = s.top();
        s.pop();
        cnt = 1;

        if (s.empty()) {
            answer.push_back(cnt);
            break;
        }

        while (temp >= s.top()) {
            s.pop();
            cnt++;
            if (s.empty()) break;
        }
        answer.push_back(cnt);
    }

    return answer;
}