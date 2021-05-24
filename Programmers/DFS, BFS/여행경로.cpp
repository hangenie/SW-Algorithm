#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> routes;
vector<bool> visited;

bool cmp(const vector<string>& a, const vector<string>& b) {
    return a[1] < b[1];
}

void DFS(vector<vector<string>> tickets, vector<string> temp, string departure, int cnt) {
    if (cnt == tickets.size()) {
        temp.push_back(departure);
        routes.push_back(temp);
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (visited[i] == true) continue;

        if (tickets[i][0] == departure) {
            visited[i] = true;
            temp.push_back(departure);
            DFS(tickets, temp, tickets[i][1], cnt + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    int cnt = 0;
    vector<string> temp;

    sort(tickets.begin(), tickets.end(), cmp);
    for (int i = 0; i < tickets.size(); i++) {
        visited.push_back(false);
    }

    DFS(tickets, temp, "ICN", cnt);


    sort(routes.begin(), routes.end());
    answer = routes[0];

    return answer;
}