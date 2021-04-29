#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> temp;

    for (int t = 0; t < commands.size(); t++) {
        int i = commands[t][0];
        int j = commands[t][1];
        int k = commands[t][2];

        for (int r = i - 1; r <= j - 1; r++) {
            temp.push_back(array[r]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
        temp.clear();
    }

    return answer;
}