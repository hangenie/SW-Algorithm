#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 0;

    int end;

    sort(routes.begin(), routes.end());
    end = routes[0][1];

    for (int i = 1; i < routes.size(); i++) {
        if (end < routes[i][0]) {
            answer++;
            end = routes[i][1];
        }

        if (end >= routes[i][1]) {
            end = routes[i][1];
        }
    }

    answer++;

    return answer;
}