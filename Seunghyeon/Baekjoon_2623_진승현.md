## 문제 요약

**음악프로그램 ( 골드 3 )**
1. 보조 PD 3명에게 각자 담당한 가수의 출연 순서를 정해오게 했음

2. 이 순서들을 모아서 전체 가수의 순서를 정해야 함

3. 6 2 1 5 4 3 -> 위상정렬 문제

4. 보조 PD 들이 만든 순서들이 입력으로 주어질 때, 전체 가수의 순서를 정하는 프로그램 작성하기



## 입력
1. 가수의 수 N, 보조 PD 의 수 M
2. 각 보조 PD 가 정한 순서
- 담당한 가수의 수, 가수의 순서


## 출력
1. N 개의 줄로 이뤄지며, 한 줄에 하나의 번호씩 출력 ( 출연 순서 )

2. 답이 여러개일 경우, 아무거나 하나 출력

3. 만약 순서 정하기가 불가능할 경우, 0 출력

## 풀이
1. 위상정렬
2. 중복이 없어야함
3. 순서 정하기가 불가능할 경우 생각하기

## 코드

### 위상 정렬 ( 정답 ) : 시간 64ms

```python
import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

# 위상 정렬
graph = [[] for _ in range(n+1)]
indegree = [0] * (n+1)

for _ in range(m):
    # 덱으로 입력받기
    lst = deque(map(int, input().split()))
    # 반복
    k = lst.popleft()

    for i in range(k-1):
        graph[lst[i]].append(lst[i+1])
        indegree[lst[i+1]] += 1

queue = deque()
res = []
for i in range(1, n+1):
    if indegree[i] == 0:
        queue.append(i)

while queue:
    cur = queue.popleft()
    res.append(cur)

    for v in graph[cur]:
        indegree[v] -= 1

        if indegree[v] == 0:
            queue.append(v)

if len(res) != n:
    print(0)
else:
    for ans in res:
        print(ans)
```
