## 문제 요약

** 트리의 부모 찾기 ( 실버 2 )**

1. 트리의 루트 : 1

2. 각 노드의 부모를 구하는 프로그램 작성하기

## 입력
1. 노드의 개수 N
2. N-1 개의 줄에 트리 상에서 연결된 두 정점

## 출력
1. 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 332ms

```python
import sys
sys.setrecursionlimit(10**6)

def dfs(start_node):
    for node in tree[start_node]:
        # 만약 아직 방문하지 않은 자식 노드일 경우
        if visited[node] == 0:
            # 방문표시 ( 예를 들어 1번 노드의 경우, 자식이 6, 4 이니 6번 노드와 4번 노드가 자신의 자식이라고 표시를 남김 )
            visited[node] = start_node
            dfs(node)
            
input = sys.stdin.readline

n = int(input())

tree = [[] for _ in range(n+1)]

for _ in range(n-1):
    a,b = map(int, input().split())
    # 양방향
    tree[a].append(b)
    tree[b].append(a)

# 방문 표시
visited = [0 for _ in range(n+1)]

# dfs 호출
dfs(1)

for ans in visited[2:]:
    print(ans)

```

1. 트리 만들기
2. 트리의 부모를 표시할 리스트 만들기
3. DFS 호출
4. 정답 출력

### 더 빠른 코드 : 시간 292ms ( PyPy3 )

```python
import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

tree = [[] for _ in range(n+1)]

for _ in range(n-1):
    a,b = map(int, input().split())
    # 양방향
    tree[a].append(b)
    tree[b].append(a)

# 방문 표시
visited = [0 for _ in range(n+1)]

queue = deque()

queue.append((1))
while queue:
    node = queue.popleft()

    for next_node in tree[node]:
        if visited[next_node] == 0:
            visited[next_node] = node
            queue.append(next_node)

print(*visited[2:], sep="\n")

```

차이점
- 함수를 써서 dfs 를 표현 X
- bfs 로 접근
