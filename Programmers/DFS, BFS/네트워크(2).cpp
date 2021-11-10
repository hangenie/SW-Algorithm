#include <string>
#include <vector>

using namespace std;

int answer;
vector<bool> visited;

void DFS(int n, vector<vector<int>> computers, int now) {
    for (int i = 0; i < n; i++) {
        if (now == i) continue;
        if (visited[i]) continue;

        if (computers[now][i] == 1) {
            visited[i] = true;
            DFS(n, computers, i);
        }

    }
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        visited.push_back(false);
    }


    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        answer++;
        visited[i] = true;
        DFS(n, computers, i);
    }


    return answer;
}