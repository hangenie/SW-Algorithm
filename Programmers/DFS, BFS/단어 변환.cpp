#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> selected;
vector<int> stage;
int cnt = 0;

void DFS(vector<string> words, string begin, string target) {
    int flag = 0;
    string temp;

    if (begin == target) {
        stage.push_back(cnt);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (selected[i] == true) continue;

        temp = words[i];
        flag = 0;

        for (int j = 0; j < temp.size(); j++) {
            if (begin[j] != temp[j]) {
                flag++;
            }
        }

        if (flag == 1) {
            selected[i] = true;
            cnt++;
            DFS(words, words[i], target);
            cnt--;
            selected[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    sort(words.begin(), words.end());
    if (find(words.begin(), words.end(), target) == words.end()) {
        answer = 0;
        return 0;
    }

    for (int i = 0; i < words.size(); i++) {
        selected.push_back(false);
    }

    DFS(words, begin, target);
    answer = *min(stage.begin(), stage.end());

    return answer;
}