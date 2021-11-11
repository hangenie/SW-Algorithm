#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
vector<string> route;
vector<bool> visited;

bool check(vector<string> v1, vector<string> v2) {
    if (v1.empty()) {
        return true;
    }

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] > v2[i]) {
            return true;
        }
        else if (v1[i] < v2[i]) {
            return false;
        }
    }

    return false;
}

void DFS(vector<vector<string>> tickets, string depart) {
    if (find(visited.begin(), visited.end(), false) == visited.end()) {
        // answer보다 route가 알파벳 순으로 빠르면 answer 업데이트
        if (check(answer, route)) {
            answer.clear();

            for (int i = 0; i < route.size(); i++) {
                answer.push_back(route[i]);
            }
        }


        return;
    }


    for (int i = 0; i < tickets.size(); i++) {
        if (visited[i]) continue;

        if (tickets[i][0] == depart) {
            visited[i] = true;
            route.push_back(tickets[i][1]);
            DFS(tickets, tickets[i][1]);
            route.pop_back();
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (int i = 0; i < tickets.size(); i++) {
        visited.push_back(false);
    }

    sort(tickets.begin(), tickets.end());

    route.push_back("ICN");

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            visited[i] = true;
            route.push_back(tickets[i][1]);
            DFS(tickets, tickets[i][1]);
            route.pop_back();
            visited[i] = false;
        }
    }


    return answer;
}