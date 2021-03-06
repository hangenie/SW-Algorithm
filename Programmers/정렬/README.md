# 정렬

* 데이터를 **특정한 기준에 따라 순서대로 나열**하는 것
* 문제 상황에 따라서 적절한 정렬 알고리즘을 사용



## 선택 정렬

* 처리되지 않은 데이터 중에서 가장 작은 데이터를 **선택**해 맨 앞에 있는 데이터와 바꾸는 것을 반복
* 구현 과정

```
1. 처리되지 않은 데이터 중 최솟값을 선택
2. 처리되지 않은 데이터 중 맨 앞에 위치한 값과 교체
3. 하나의 데이터가 남을 때까지 1~2번 과정을 반복
```

* 소스 코드

```c++
#include <iostream>

using namespace std;

int n = 10;
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(void) {
    for (int i = 0; i < n; i++) {
        int min_index = i; // 가장 작은 원소의 인덱스 
        for (int j = i + 1; j < n; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); // 스와프
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
```

* 시간복잡도

  * N번 만큼 가장 작은 수를 찾아서 맨 앞으로 보내야 함
  * 전체 연산 횟수

  ```
   N + (N - 1) + (N - 2) + ... + 2 = (N^2 + N - 2) / 2
  ```

  * O(N<sup>2</sup>)



--------------

## 삽입 정렬

* 처리되지 않은 데이터를 하나씩 골라 **적절한 위치에 삽입**
* 구현 과정

```
1. 첫 번째 데이터는 정렬이 되어 있다고 판단
2. 두 번째 데이터부터 자신보다 앞에 있는 데이터들과 비교하여 삽입될 위치를 판단
3. 마지막 데이터까지 2번 과정을 반복
```

* 소스 코드

```c++
#include <iostream>

using namespace std;

int n = 10;
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(void) {
    for (int i = 1; i < n; i++) {
        // 인덱스 i부터 1까지 감소하며 반복하는 문법
        for (int j = i; j > 0; j--) {
            // 한 칸씩 왼쪽으로 이동
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
            // 자기보다 작은 데이터를 만나면 그 위치에서 멈춤
            else break;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
```

* 시간복잡도
  * 선택 정렬과 마찬가지로 반복문 2번 중첩
  * 평균이 경우, O(N<sup>2</sup>)
  * 최선의 경우(현재 리스트의 데이터가 거의 정렬되어 있을 때), O(N)



--------------------

## 퀵 정렬

* 기준 데이터(Pivot)를 설정하고 그 **기준보다 큰 데이터와 작은 데이터의 위치를 교환**
* 대부분의 프로그래밍 언어의 정렬 라이브러리의 근간이 되는 알고리즘
* 기본적인 퀵 정렬은 **첫 번째 데이터를 기준 데이터(Pivot)로 설정**
* 구현 과정

```
1. 첫 번째 데이터를 피벗으로 설정
   왼쪽에서부터 피벗보다 큰 데이터를 선택, 오른쪽에서부터 피벗보다 작은 데이터를 선택
2. 두 데이터의 위치를 서로 교환
3. 두 데이터의 위치가 엇갈리는 경우, 작은 데이터와 피벗의 위치를 서로 교환
4. 교환이 완료되면, 피벗을 기준으로 피벗보다 작은 데이터는 왼쪽, 큰 데이터는 오른쪽으로 나누어 짐 - 분할
5. 분할된 리스트에 대해서 각각 정렬을 수행
```

* 소스 코드

```C++
#include <iostream>

using namespace std;

int n = 10;
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void quickSort(int* arr, int start, int end) {
    if (start >= end) return; // 원소가 1개인 경우 종료
    int pivot = start; // 피벗은 첫 번째 원소
    int left = start + 1;
    int right = end;
    while (left <= right) {
        // 피벗보다 큰 데이터를 찾을 때까지 반복
        while (left <= end && arr[left] <= arr[pivot]) left++;
        // 피벗보다 작은 데이터를 찾을 때까지 반복
        while (right > start && arr[right] >= arr[pivot]) right--;
        // 엇갈렸다면 작은 데이터와 피벗을 교체
        if (left > right) swap(arr[pivot], arr[right]);
        // 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
        else swap(arr[left], arr[right]);
    }
    // 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
    quickSort(arr, start, right - 1);
    quickSort(arr, right + 1, end);
}

int main(void) {
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }x	c
    return 0;
}
```

* 시간복잡도
  * 평균의 경우, O(NlogN)
  * 최악의 경우(이미 정렬된 배열에서 첫 번째 원소를 피벗으로 삼을 때), O(N<sup>2</sup>)



--------------

## 계수 정렬

* 특정한 조건이 부합할 때만 사용 가능
  * 데이터의 크기 범위가 제한되어 정수 형태로 표현할 수 있을 때
  * 동일한 값을 가지는 데이터가 여러개 있을 때
* 매우 빠르게 동작하는 정렬 알고리즘
* 구현 과정

```
1. 가장 작은 데이터부터 가장 큰 데이터까지의 범위가 모두 담길 수 있는 리스트 생성
2. 데이터를 하나씩 확인하며 데이터의 값과 동일한 인덱스의 데이터를 1씩 증가
   최종 리스트에는 각 데이터가 몇 번씩 등장했는지 횟수가 저장됨
3. 저장된 리스트의 첫 번째 데이터부터 하나씩 그 값만큼 반복하여 인덱스를 출력
```

* 소스 코드

```C++
#include <iostream>
#define MAX_VALUE 9

using namespace std;

int n = 15;
// 모든 원소의 값이 0보다 크거나 같다고 가정
int arr[15] = {7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2};
// 모든 범위를 포함하는 배열 선언(모든 값은 0으로 초기화)
int cnt[MAX_VALUE + 1];

int main(void) {
    for (int i = 0; i < n; i++) {
        cnt[arr[i]] += 1; // 각 데이터에 해당하는 인덱스의 값 증가
    }
    for (int i = 0; i <= MAX_VALUE; i++) { // 배열에 기록된 정렬 정보 확인
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << ' '; // 띄어쓰기를 기준으로 등장한 횟수만큼 인덱스 출력
        }
    }
    return 0;
}
```

* 시간복잡도
  * 데이터의 개수 N, 데이터(양수) 중 최댓값 K
  * 최악의 경우에도 O(N + K) 보장



------------------------

## 정렬 알고리즘 비교

* 대부분의 프로그래밍 언어에서 지원하는 표준 정렬 라이브러리는 최악의 경우에도 O(NlogN)을 보장

* | 정렬 알고리즘 | 평균 시간 복잡도 | 특징                                                         |
  | ------------- | ---------------- | ------------------------------------------------------------ |
  | 선택 정렬     | O(N<sup>2</sup>) | 아이디어가 간단<br />구현이 쉬움                             |
  | 삽입 정렬     | O(N<sup>2</sup>) | 최선의 경우, O(N)                                            |
  | 퀵 정렬       | O(NlogN)         | 대부분의 경우에 가장 적합<br />최악의 경우, O(N<sup>2</sup>) |
  | 계수 정렬     | O(N + K)         | 데이터의 크기가 한정된 경우에만 사용 가능<br />매우 빠르게 동작 |

