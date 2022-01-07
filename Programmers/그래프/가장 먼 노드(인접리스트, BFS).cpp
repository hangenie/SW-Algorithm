#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(20001);
vector<int> dist(20001, 0);

void BFS(int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);

    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int from;

        from = q.front();
        q.pop();

        for (int i = 0; i < graph[from].size(); i++) {
            if (visited[graph[from][i]]) continue;

            visited[graph[from][i]] = true;
            dist[graph[from][i]] = dist[from] + 1;
            q.push(graph[from][i]);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max;

    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    // 각 노드까지의 간선 개수 구하기
    BFS(n);

    // 가장 멀리 떨어진 노드 수 구하기
    max = *max_element(dist.begin() + 2, dist.end());
    for (int i = 2; i <= n; i++) {
        if (dist[i] == max) answer++;
    }

    return answer;
}