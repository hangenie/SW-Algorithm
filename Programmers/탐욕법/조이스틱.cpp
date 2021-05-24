#include <string>
#include <vector>

using namespace std;

int count(string& name, int i) {
    char c = name[i];

    if (c == 'A') {
        return 0;
    }
    else if (c > 'A' && c <= 'N') {
        name[i] = 'A';
        return c - 'A';
    }
    else if (c > 'N' && c <= 'Z') {
        name[i] = 'A';
        return 'Z' - c + 1;
    }
}

bool check(string name) {
    int cnt = 0;
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == 'A') {
            cnt++;
        }
    }

    if (cnt == name.size()) {
        return true;
    }
    else {
        return false;
    }
}

int solution(string name) {
    int answer = 0;

    int cnt, index = 0;

    while (1) {
        answer += count(name, index);

        if (check(name)) {
            break;
        }

        // 다음 바꿀 문자 위치 찾기
        int left, right, l_index, r_index;
        int i;

        cnt = 1;
        i = index + 1;
        if (i > name.size() - 1) {
            i = 0;
        }
        while (name[i] == 'A') {
            cnt++;
            i++;
            if (i > name.size() - 1) {
                i = 0;
            }
        }
        right = cnt;
        r_index = i;

        cnt = 1;
        i = index - 1;
        if (i < 0) {
            i = name.size() - 1;
        }
        while (name[i] == 'A') {
            cnt++;
            i--;
            if (i < 0) {
                i = name.size() - 1;
            }
        }
        left = cnt;
        l_index = i;

        if (right > left) {
            answer += left;
            index = l_index;
        }
        else {
            answer += right;
            index = r_index;
        }
    }


    return answer;
}