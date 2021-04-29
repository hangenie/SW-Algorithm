#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<vector<int>> h = { { 1,2,3,4,5 }, { 2,1,2,3,2,4,2,5 }, { 3,3,1,1,2,2,4,4,5,5 } };
    vector<int> score = { 0, 0, 0 };
    int max_index, max, temp;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < answers.size(); j++) {
            if (j >= h[i].size()) {
                if (h[i][j % h[i].size()] == answers[j]) {
                    score[i]++;
                }
            }
            else {
                if (h[i][j] == answers[j]) {
                    score[i]++;
                }
            }
        }
    }

    max_index = max_element(score.begin(), score.end()) - score.begin();
    max = *max_element(score.begin(), score.end());
    answer.push_back(max_index + 1);

    for (int i = 0; i < 3; i++) {
        if (max == score[i] && max_index != i) {
            answer.push_back(i + 1);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}