#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    queue<int> documents;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
    }
    
    while (!q.empty()) {
        int max_index, max_value;
        int index, value;
        
        max_index = max_element(priorities.begin(), priorities.end()) - priorities.begin();
        max_value = *max_element(priorities.begin(), priorities.end());
        
        index = q.front().first;
        value = q.front().second;
        q.pop();
        
        if (max_value == value) {
            documents.push(index);
            priorities[max_index] = -1;
        }
        else {
            q.push(make_pair(index, value));
        }
    }
    
    while (!documents.empty()) {
        int index = documents.front();
        documents.pop();
        answer++;
        
        if (index == location) {
            break;
        }
    }
    
    return answer;
}