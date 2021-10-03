#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++) {        
        for (int j = 0; j < phone_book[i].size(); j++) {
            if (phone_book[i][j] != phone_book[i + 1][j]) {
                break;
            }
            
            if (j == phone_book[i].size() - 1) {
                answer = false;
            }
        }
    }
    
    
    return answer;
}