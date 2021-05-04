# 스택, 큐

## 스택 (Stack)

![스택](https://media.vlpt.us/images/sbinha/post/17a3cf61-fb95-4970-b66c-92a71b99846b/Screenshot%202020-04-20%2019.07.55.png)

* 먼저 들어 온 데이터가 나중에 나가는 형식(**선입후출**)의 자료구조
* 입구와 출구가 동일한 형태
* 소스 코드

```c++
#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(void) {
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(7);
    s.pop();
    s.push(1);
    s.push(4);
    s.pop();
    // 스택의 최상단 원소부터 출력
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}
```



-------------

## 큐 (Queue)

![큐](https://media.vlpt.us/images/sbinha/post/dbc199b3-6959-464e-872d-39c503fa0b1b/Screenshot%202020-04-20%2019.19.59.png)

* 먼저 들어 온 데이터가 먼저 나가는 형식(**선입선출**)의 자료구조
* 입구와 출구가 모두 뚫려 있는 터널과 같은 형태
* 소스 코드

```C++
#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(void) {
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(7);
    q.pop();
    q.push(1);
    q.push(4);
    q.pop();
    // 먼저 들어온 원소부터 추출
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
}
```
