#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    vector<int> temp;

    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i];

        if (op == "D 1") {
            if (!max_pq.empty()) {
                temp.erase(find(temp.begin(), temp.end(), max_pq.top()));
                max_pq.pop();

                while (!min_pq.empty()) {
                    min_pq.pop();
                }
                for (int j = 0; j < temp.size(); j++) {
                    min_pq.push(temp[j]);
                }
            }
        }
        else if (op == "D -1") {
            if (!min_pq.empty()) {
                temp.erase(find(temp.begin(), temp.end(), min_pq.top()));
                min_pq.pop();

                while (!max_pq.empty()) {
                    max_pq.pop();
                }
                for (int j = 0; j < temp.size(); j++) {
                    max_pq.push(temp[j]);
                }
            }
        }
        else {
            int num = stoi(op.substr(2));
            max_pq.push(num);
            min_pq.push(num);
            temp.push_back(num);
        }
    }

    if (temp.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }


    return answer;
}