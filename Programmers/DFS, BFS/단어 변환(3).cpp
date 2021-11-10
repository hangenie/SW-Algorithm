#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 987654321;
vector<bool> visited;

bool check(string str1, string str2) {
    int cnt = 0;

    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            cnt++;
        }
    }

    if (cnt == 1) return true;
    else return false;
}

void BFS(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;

    q.push(make_pair(begin, 0));

    while (!q.empty()) {
        string str;
        int cnt;

        str = q.front().first;
        cnt = q.front().second;
        q.pop();


        if (str == target) {
            answer = cnt;
            break;
        }


        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;

            if (check(str, words[i])) {
                visited[i] = true;
                q.push(make_pair(words[i], cnt + 1));
            }
        }

    }
}

int solution(string begin, string target, vector<string> words) {
    for (int i = 0; i < words.size(); i++) {
        visited.push_back(false);
    }


    if (find(words.begin(), words.end(), target) == words.end()) {
        answer = 0;
    }
    else {
        BFS(begin, target, words);
    }


    if (answer == 987654321) answer = 0;


    return answer;
}