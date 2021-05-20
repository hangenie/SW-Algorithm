#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> a, const vector<int> b) {
    return a[2] < b[2];

}

int getRoot(vector<int> check, int x) {
    if (check[x] == x)
        return x;
    return check[x] = getRoot(check, check[x]);
}

void unionRoot(vector<int>& check, int x, int y) {
    int rx = getRoot(check, x);
    int ry = getRoot(check, y);

    if (rx < ry)
        check[ry] = rx;
    else check[rx] = ry;
}

bool find(vector<int> check, int x, int y) {
    int rx = getRoot(check, x);
    int ry = getRoot(check, y);

    if (rx == ry)
        return true;
    else return false;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    int bridge = 0, i = 0;
    vector<int> check(n, 0);

    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0; i < n; i++) {
        check[i] = i;
    }

    while (bridge < n - 1) {
        if (find(check, costs[i][0], costs[i][1])) {
            i++;
        }
        else {
            answer += costs[i][2];
            unionRoot(check, costs[i][0], costs[i][1]);
            i++;
            bridge++;
        }
    }


    return answer;
}