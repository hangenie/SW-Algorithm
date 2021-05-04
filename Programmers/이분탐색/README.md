# 이분탐색

* 정렬되어 있는 리스트에서 **탐색 범위를 절반씩 좁혀가며 데이터를 탐색**하는 방법
* 시작점, 끝점, 중간점을 이용하여 탐색 범위를 설정
* 구현 과정

```
1. 시작점과 끝점으로 중간점을 설정
   중간점 = (시작점 + 끝점) / 2
2. 중간점의 값과 찾고자 하는 값을 비교
   중간점의 값보다 찾고자 하는 값이 작은 경우, 왼쪽 부분을 확인 (끝점을 중간점 - 1로 설정)
   중간점의 값보다 찾고자 하는 값이 큰 경우, 오른쪽 부분을 확인 (시작점을 중간점 + 1로 설정)
3. 구하고자 하는 값을 찾을 때까지 1~3번 과정을 반복
```

* 소스 코드 (재귀함수)

```C++
#include <iostream>
#include <vector>

using namespace std;

// 이진 탐색 소스코드 구현(재귀함수)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    // 찾은 경우 중간점 인덱스 반환
    if (arr[mid] == target)
        return mid;
    // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
    else if (arr[mid] > target)
        return binarySearch(arr, target, start, mid - 1);
    // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
    else
        return binarySearch(arr, target, mid + 1, end);
}

int n, target;
vector<int> arr;

int main(void) {
    // n(원소의 개수)와 target(찾고자 하는 값)을 입력받기 
    cin >> n >> target;
    // 전체 원소 입력받기 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
    return 0;
}
```

* 소스 코드 (반복문)

```C++
#include <iostream>
#include <vector>

using namespace std;

// 이진 탐색 소스코드 구현(반복문)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 중간점 인덱스 반환
        if (arr[mid] == target)
            return mid;
        // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        else if (arr[mid] > target)
            end = mid - 1;
        // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else
            start = mid + 1; 
    }
    return -1;
}

int n, target;
vector<int> arr;

int main(void) {
    // n(원소의 개수)와 target(찾고자 하는 값)을 입력 받기 
    cin >> n >> target;
    // 전체 원소 입력 받기 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
    return 0;
}
```

* 시간복잡도
  * 단계마다 탐색 범위를 2로 나눔, 연산 횟수는 log<sub>2</sub>N에 비례
  * O(logN)



----------------

## C++ 이분 탐색 라이브러리

* lower_bound(first, last, x) : *[first, last)* 범위에서 **x가 들어갈 가장 왼쪽 위치**를 반환
* upper_bound(first, last, x) : *[first, last)* 범위에서 **x가 들어갈 가장 오른쪽 위치**를 반환

* 소스 코드

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> v = { -2, -2, -1, -1, 0, 0, 0, 1, 1 };
	
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << '\n';  // 4
    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << '\n';  // 7
    
    return 0;
}
```



----------------

## 파라메트릭 서치 (Parametric Search)

* 최적화 문제를 **결정 문제('예' 혹은 '아니오')로 바꾸어 해결**하는 기법
* 일반적으로 코딩 테스트에서 이분 탐색을 이용하여 파라메트릭 서치 문제를 해결
