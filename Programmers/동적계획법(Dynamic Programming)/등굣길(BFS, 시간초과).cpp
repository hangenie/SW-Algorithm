#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int arr[101][101];
    int x, y;
    queue<pair<int, int>> q;
    int dx[2] = { 1,0 };
    int dy[2] = { 0,1 };

    // �� ��� ���� ǥ��
    for (int i = 0; i < puddles.size(); i++) {
        arr[puddles[i][1]][puddles[i][0]] = -1;
    }

    // BFS
    q.push(make_pair(1, 1));

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // ���� ������ ������ �н�
            if (nx > m || ny > n) {
                continue;
            }
            // �� �����̸� �н�
            if (arr[ny][nx] == -1) {
                continue;
            }
            // �б� �����ϸ� ��� ���� �߰�
            if (nx == m && ny == n) {
                answer = (answer + 1) % 1000000007;
            }

            q.push(make_pair(nx, ny));
        }
    }

    return answer;
}