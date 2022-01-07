#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool graph[20000][20000];
vector<int> dist;
vector<bool> visited;

void BFS(int n, int dst) {
    queue<pair<int, int>> q;

    visited[0] = true;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int from, cnt;

        from = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (from == dst) {
            dist[from] = cnt;
            break;
        }

        for (int i = 1; i < n; i++) {
            if (i == from) continue;
            if (graph[from][i] == false) continue;
            if (visited[i]) continue;

            visited[i] = true;
            q.push(make_pair(i, cnt + 1));
            visited[i] = false;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max;

    memset(graph, false, sizeof(graph));

    for (int i = 0; i < n; i++) {
        dist.push_back(20000);
        visited.push_back(false);
    }

    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0] - 1][edge[i][1] - 1] = true;
        graph[edge[i][1] - 1][edge[i][0] - 1] = true;
    }

    for (int i = 1; i < n; i++) {
        // 각 노드까지의 간선 개수 구하기
        BFS(n, i);
    }

    // 가장 멀리 떨어진 노드 수 구하기
    max = *max_element(dist.begin() + 1, dist.end());
    for (int i = 1; i < n; i++) {
        if (dist[i] == max) answer++;
    }

    return answer;
}