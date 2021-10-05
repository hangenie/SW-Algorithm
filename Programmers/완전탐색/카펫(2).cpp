#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int carpet = brown + yellow;
    int a, b, i = 1;
    
    while (i * i < carpet) {
        i++;
    }
    
    for (a = i; a < carpet; a++) {
        if (carpet % a != 0) continue;
        else {
            b = carpet / a;
        }
        
        if((a + b - 2) * 2 == brown) {
            answer.push_back(a);
            answer.push_back(b);
        }
        
    }
    
    
    return answer;
}