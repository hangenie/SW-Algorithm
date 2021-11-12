#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<bool> visited;
string number;

void DFS(string numbers, int limit, int cnt) {
    if (cnt == limit) {
        int number_i = stoi(number);

        if (find(num.begin(), num.end(), number_i) == num.end()) {
            num.push_back(number_i);
        }

        return;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i]) continue;

        visited[i] = true;
        number.push_back(numbers[i]);
        DFS(numbers, limit, cnt + 1);
        number.pop_back();
        visited[i] = false;
    }
}

bool is_prime(int num) {
    if (num == 0 || num == 1) return false;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    for (int i = 0; i < numbers.size(); i++) {
        visited.push_back(false);
    }


    for (int i = 1; i <= numbers.size(); i++) {
        DFS(numbers, i, 0);
    }


    for (int i = 0; i < num.size(); i++) {
        if (is_prime(num[i])) answer++;
    }

    return answer;
}