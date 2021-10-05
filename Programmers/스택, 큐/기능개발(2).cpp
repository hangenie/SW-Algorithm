#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    vector<int> vec;
    int temp, cnt = 0;
    
    for (int i = 0; i < progresses.size(); i++) {
        int day = 0, remain;
        
        remain = 100 - progresses[i];
        
        while (remain > 0) {
            remain -= speeds[i];
            day++;
        }
        
        days.push(day);
    }
    
    while (!days.empty()) {
        temp = days.front();
        days.pop();
        
        vec.push_back(temp);
        cnt++;
        
        
        if (days.empty()) {
            answer.push_back(cnt);
            break;
        }
        
        
        if (*max_element(vec.begin(), vec.end()) >= days.front()) {
            continue;
        }
        else {
            answer.push_back(cnt);
            vec.clear();
            cnt = 0;
        }
    }    
    
    return answer;
}