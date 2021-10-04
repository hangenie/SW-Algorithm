#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> cloth;
    
    for (int i = 0; i < clothes.size(); i++) {
        if (cloth.find(clothes[i][1]) != cloth.end()) {
            cloth[clothes[i][1]]++;
        }
        else {
            cloth.insert(make_pair(clothes[i][1], 1));
        }
    }
    
    if (cloth.size() != 1) {
        for (auto iter = cloth.begin(); iter != cloth.end(); iter++) {
            answer *= iter->second + 1;
        }
        
        answer -= 1;
    }
    else {
        answer = cloth.begin()->second;
    }
    
    return answer;
}