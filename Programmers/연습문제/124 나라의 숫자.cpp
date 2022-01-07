#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> remains;

    remains.push_back("4");
    remains.push_back("1");
    remains.push_back("2");

    while (n > 0) {
        int remain;

        remain = n % 3;
        n /= 3;

        if (remain == 0) n--;

        answer.insert(0, remains[remain]);
    }

    return answer;
}