#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge;
    int i, sum = 0;

    for (i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }

    i = 0;
    while (!bridge.empty()) {
        if (i < truck_weights.size()) {
            if (bridge.front() != 0) {
                sum -= bridge.front();
            }

            if (truck_weights[i] + sum <= weight) {
                sum += truck_weights[i];
                bridge.push(truck_weights[i]);
                i++;
            }
            else {
                bridge.push(0);
            }

            bridge.pop();
            answer++;
        }
        else {
            bridge.pop();
            answer++;
        }
    }

    return answer;
}