#include <string>
#include <vector>

using namespace std;

int answer;

void DFS(vector<int> numbers, int target, int index, int sum) {
    if (index == numbers.size() - 1) {
        if (sum == target) {
            answer++;
        }

        return;
    }


    DFS(numbers, target, index + 1, sum + numbers[index + 1]);
    DFS(numbers, target, index + 1, sum - numbers[index + 1]);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, numbers[0]);
    DFS(numbers, target, 0, -numbers[0]);


    return answer;
}