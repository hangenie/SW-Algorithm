# DFS, BFS

## DFS (Depth-First Search)

![DFS](https://media.vlpt.us/images/sukong/post/b9042f15-fb5b-4272-abe7-8cdeb3f0f22f/DFS.png)

* **깊이 우선 탐색**
* **스택, 재귀함수** 이용
* 구현 과정 (스택)

```
1. 탐색 시작 노드를 스택에 삽입, 방문 처리
2. 스택의 최상단 노드에 방문하지 않은 인접한 노드가 하나라도 있으면, 그 노드를 스택에 넣고 방문 처리
   방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼냄
3. 더 이상 2번 과정을 수행할 수 없을 때 까지 반복
```

* 구현 과정 (재귀함수)

```
1. 파라미터로 넘어온 노드가 방문한 노드일 경우, return 하도록 조건 설정
2. 파라미터로 넘어온 노드가 방문하지 않은 노드일 경우, 방문 처리
3. 인접한 노드에 대해 재귀적으로 함수 호출
```

* 소스 코드 (재귀함수)

```c++
#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector<int> graph[9];

// DFS 함수 정의
void dfs(int x) {
    // 현재 노드를 방문 처리
    visited[x] = true;
    cout << x << ' ';
    // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) dfs(y);
    }
}

int main(void) {
    // 노드 1에 연결된 노드 정보 저장 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    // 노드 2에 연결된 노드 정보 저장 
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    // 노드 3에 연결된 노드 정보 저장 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);
    
    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);
    
    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    
    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    dfs(1);
    
    return 0;
}
```



## BFS(Breadth-First Search)

![BFS](https://media.vlpt.us/images/sukong/post/103fbeed-3f70-4074-9a7d-76915a7764f2/BFS.png)

* **너비 우선 탐색**
* **큐** 이용
* 구현 과정

```
1. 탐색 시작 노드를 큐에 삽입, 방문 처리
2. 큐에서 노드를 꺼낸 뒤에
   해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입, 방문처리
3. 더 이상 2번 과정을 수행할 수 없을 때 까지 반복
```

* 소스 코드

```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[9];
vector<int> graph[9];

// BFS 함수 정의
void bfs(int start) {
    queue<int> q;
    q.push(start);
    // 현재 노드를 방문 처리
    visited[start] = true;
    // 큐가 빌 때까지 반복
    while(!q.empty()) {
    	// 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        cout << x << ' ';
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for(int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(void) {
    // 노드 1에 연결된 노드 정보 저장 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    // 노드 2에 연결된 노드 정보 저장 
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    // 노드 3에 연결된 노드 정보 저장 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);
    
    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);
    
    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    
    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    bfs(1);
    
    return 0;
}
```
