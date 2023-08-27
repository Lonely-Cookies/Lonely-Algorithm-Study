## 문제 요약

**줄 세우기 ( 골드 3 )**
1. n 명의 학샐들을 키 순서대로 줄 세우기
2. 일부 학생들의 키만을 비교해서 줄 세우는 프로그램 만들기


## 입력
1. n ( 학생수 ), m ( 키를 비교한 횟수 )
2. 키를 비교한 두 학생의 번호 A > B -> 학생 A 가 학생 B 의 앞에 서야 한다는 의미
3. 학생들의 번호 : 1 ~ n번


## 출력
1. 학생들을 앞에서부터 줄을 세운 결과 출력하기

## 풀이
1. 큐에 담기
2. 순서 맞추기
- 오른쪽 기준으로 바로 앞에 넣어버리기
---
1. 그래프
- 위상 정렬

## 코드

### 위상 정렬 ( 정답 ) : 시간 208ms

```python
import sys
from collections import deque

input = sys.stdin.readline

n,m = map(int, input().split())

# 위상 정렬
graph = [[] for _ in range(n+1)]
# 진입 차수
indegree = [0] * (n+1)

for _ in range(m):
    fr, se = map(int, input().split())
    # 방향이 있는 그래프
    graph[fr].append(se)
    indegree[se] += 1

queue = deque()
res = []

for i in range(1, n+1):
    # 진입차수가 0 인 원소를 큐에 담고
    if indegree[i] == 0:
        queue.append(i)
# 큐의 원소를 빼고
while queue:
    cur = queue.popleft()
    # 출력할 리스트에 담고 ( 이미 사용한 원소니 )
    res.append(cur)

    for i in graph[cur]:
        indegree[i] -= 1

        if indegree[i] == 0:
            queue.append(i)

print(*res)

```

## 더 빠른 코드 : dfs 이용 ( 시간 : 176ms )
```python
import sys
sys.setrecursionlimit(100_000)
def dfs(node):
    # 방문한 경우
    if visited[node]:
        return

    # 현 위치 방문 표시
    visited[node] = True
    # 다음 노드 탐색하기
    for v in graph[node]:
        dfs(v)
    res.append(str(node))

input = sys.stdin.readline

n,m = map(int, input().split())

# dfs
graph = [[] for _ in range(n+1)]

for _ in range(m):
    fr, se = map(int, input().split())
    # 방향이 있는 그래프
    graph[se].append(fr)

res = []
visited = [False] * (n+1)

for i in range(1, n+1):
    dfs(i)

print(' '.join(res))
```