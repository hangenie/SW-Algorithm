#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int r = triangle.size();
    vector<vector<int>> d(r, vector<int>(r, 0));


    d[0][0] = triangle[0][0];

    for (int i = 1; i < r; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                d[i][j] = d[i - 1][0] + triangle[i][j];
            }
            else if (j == triangle[i].size() - 1) {
                d[i][j] = d[i - 1][j - 1] + triangle[i][j];
            }
            else {
                d[i][j] = max(d[i - 1][j - 1] + triangle[i][j], d[i - 1][j] + triangle[i][j]);
            }
        }
    }

    answer = *max_element(d[r - 1].begin(), d[r - 1].end());

    return answer;
}