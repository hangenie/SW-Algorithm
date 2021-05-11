#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int arr[101][101];

    // ���� �迭 �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = 0;
        }
    }

    // �� ��� ���� ǥ��
    for (int i = 0; i < puddles.size(); i++) {
        arr[puddles[i][1]][puddles[i][0]] = -1;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                arr[i][j] = 1;
            }
            else if (arr[i][j] == -1) {
                continue;
            }
            else {
                int lx = j - 1, ly = i;
                int ux = j, uy = i - 1;

                // ����, ���� ��� ���� ���̰ų� �� �������� ���
                if ((lx <= 0 || arr[ly][lx] == -1) && (uy <= 0 || arr[uy][ux] == -1)) {
                    arr[i][j] = 0;
                }
                // ������ ���� ���̰ų� �� �������� ���
                else if (lx <= 0 || arr[ly][lx] == -1) {
                    arr[i][j] = arr[uy][ux] % 1000000007;
                }
                // ������ ���� ���̰ų� �� �������� ���
                else if (uy <= 0 || arr[uy][ux] == -1) {
                    arr[i][j] = arr[ly][lx] % 1000000007;
                }
                else {
                    arr[i][j] = (arr[ly][lx] + arr[uy][ux]) % 1000000007;
                }
            }
        }
    }

    answer = arr[n][m];


    return answer;
}