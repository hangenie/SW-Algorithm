#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string str)
{
    bool answer = true;
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            if (s.empty()) {
                answer = false;
                break;
            }
            else {
                s.pop();
            }
        }
        else {
            s.push(str[i]);
        }
    }

    if (!s.empty()) answer = false;

    return answer;
}