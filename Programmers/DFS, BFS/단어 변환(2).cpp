#include <string>
#include <vector>
#include <algorithm>

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

void DFS(string target, vector<string> words, string str, int cnt) {
    if (str == target) {
        if (answer > cnt) {
            answer = cnt;
        }

        return;
    }


    for (int i = 0; i < words.size(); i++) {
        if (visited[i]) continue;
        if (check(str, words[i]) == false) continue;

        visited[i] = true;
        DFS(target, words, words[i], cnt + 1);
        visited[i] = false;
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
        DFS(target, words, begin, 0);
    }


    if (answer == 987654321) answer = 0;


    return answer;
}