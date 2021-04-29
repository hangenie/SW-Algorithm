#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> map;

    for (string name : completion) {
        map[name]++;
    }
    for (string name : participant) {
        map[name]--;
    }

    for (auto iter : map) {
        if (iter.second < 0) {
            answer = iter.first;
            return answer;
        }
    }
}