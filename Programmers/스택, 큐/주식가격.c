#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len�� �迭 prices�� �����Դϴ�.
int* solution(int prices[], size_t prices_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    int cnt = 0;

    for (int i = 0; i < prices_len; i++) {
        for (int j = i + 1; j < prices_len; j++) {
            if (prices[i] <= prices[j]) {
                cnt++;
            }
            else {
                cnt++;
                break;
            }
        }
        answer[i] = cnt;
        cnt = 0;
    }

    return answer;
}