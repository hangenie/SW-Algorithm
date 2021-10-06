#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge;
    int now_weight = 0, cnt = 0, index = 0;
    
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    while (cnt < truck_weights.size()) {
        if (bridge.front() != 0) {
            now_weight -= bridge.front();
            cnt++;
        }
        bridge.pop();
        answer++;
        
        if (now_weight + truck_weights[index] <= weight) {
            bridge.push(truck_weights[index]);
            now_weight += truck_weights[index];
            index++;
        }
        else {
            bridge.push(0);
        }
    }
    
    
    return answer;
}