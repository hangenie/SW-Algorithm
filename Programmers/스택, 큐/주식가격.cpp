#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++) {
        int now, sec;
        
        now = prices[i];
        sec = 0;
        
        for (int j = i + 1; j < prices.size(); j++) {
            sec++;
            
            if (now <= prices[j]) {
                continue;
            }
            else {
                break;
            }
        }
        
        answer.push_back(sec);
    }
    
    return answer;
}