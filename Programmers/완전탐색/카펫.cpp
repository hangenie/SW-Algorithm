#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int a, b;
    int n = 1;

    while (n * n <= yellow) {
        n++;
    }

    do {
        n--;
        if (yellow == n * n) {
            a = b = n + 2;
        }
        else {
            a = yellow / n + 2;
            b = n + 2;
        }
    } while (a + b - 2 != brown / 2);

    answer = { a,b };

    return answer;
}