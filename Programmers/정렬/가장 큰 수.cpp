#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& a, int& b) {
    string temp;

    if (stoi(to_string(a) + to_string(b)) > stoi(to_string(b) + to_string(a))) {
        return true;
    }
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    if (numbers[0] == 0) {
        answer = "0";
        return answer;
    }

    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }

    return answer;
}