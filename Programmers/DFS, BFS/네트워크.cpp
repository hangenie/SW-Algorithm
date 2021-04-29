#include <string>
#include <vector>

using namespace std;

vector<bool> nodes;

void DFS(int n, vector<vector<int>> computers, int i) {
    nodes[i] = true;
    for (int j = 0; j < n; j++) {
        if (nodes[j] == false && computers[i][j] == 1) {
            DFS(n, computers, j);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        nodes.push_back(false);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] == false) {
            answer++;
            DFS(n, computers, i);
        }
    }

    return answer;
}