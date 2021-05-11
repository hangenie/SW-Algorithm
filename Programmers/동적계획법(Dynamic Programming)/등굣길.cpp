#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int arr[101][101];

    // 격자 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = 0;
        }
    }

    // 물 잠긴 지역 표시
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

                // 왼쪽, 위쪽 모두 격자 밖이거나 물 웅덩이일 경우
                if ((lx <= 0 || arr[ly][lx] == -1) && (uy <= 0 || arr[uy][ux] == -1)) {
                    arr[i][j] = 0;
                }
                // 왼쪽이 격자 밖이거나 물 웅덩이일 경우
                else if (lx <= 0 || arr[ly][lx] == -1) {
                    arr[i][j] = arr[uy][ux] % 1000000007;
                }
                // 위쪽이 격자 밖이거나 물 웅덩이일 경우
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