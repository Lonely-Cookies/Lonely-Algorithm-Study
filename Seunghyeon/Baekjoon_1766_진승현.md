## 문제 요약

**문제집 ( 골드 2 )**
1. 1 ~ n번까지 총 n개의 문제로 되어있는 문제집
- 문제는 난이도 순서
- 1번이 제일 쉽고, n번이 제일 어려움

2. 먼저 푸는 것이 좋은 문제가 존재함
- 문제 푸는 순서
- n 개의 문제는 모두 풀어야함
- 먼저 푸는 것이 좋은 문제가 있는 문제는, 먼저 푸는 것이 좋은 문제를 먼저 풀어야 함
-> 위상 정렬
- 가능하면 쉬운 문제부터 풀어야 함
-> 우선순위 큐 ( 최소 힙 )

3. 예시 ( 4개의 문제 )
- 4번 문제는 2번 문제보다 먼저 푸는 것이 좋음
- 3번 문제는 1번 문제보다 먼저 푸는 것이 좋음
- 쉬운 문제부터 풀어야 하기 때문에, 순서는 3 - 1 - 4 - 2

4.주어진 조건을 만족하면서 민오가 풀 문제의 순서를 결정해주는 프로그램 작성하기


## 입력
1. 문제의 수 n, 문제에 대한 정보의 개수 m
- a, b : a 가 b 보다 먼저 풀어야 하는 문제



## 출력
1. 문제를 풀어야하는 순서대로 빈칸을 사이에 두고 출력하기


## 풀이
1. 위상 정렬
- 진입차수가 0 인 노드들을 먼저 큐에 담기
- 큐를 왼쪽부터 pop 하면서 진입차수 1씩 줄이기
- 반복문 안에서 진입차수가 0이 되었을 경우, queue 에 다시 넣기
- 여기서 queue 는 heapq ( 최소 힙 )
- 그래야 최솟값부터 출력할 수 있음
- 큐에 담으면서 동시에 출력해야할 리스트에 목록을 담기

## 코드

### 위상 정렬 ( 정답 ) : 시간 228ms

```python
import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())

# 위상 정렬
queue = []
indegree = [0] * (n+1)
# 마지막에 출력해야할 리스트
res = []
# 그래프
graph = [[] for _ in range(n+1)]

for _ in range(m):
    # a 를 b 보다 먼저 풀어야 함
    a,b = map(int, input().split())
    # 그래프에 넣기
    graph[a].append(b)
    # 진입차수 설정
    indegree[b] += 1
# 진입차수가 0 인 노드들을 큐에 넣기
for i in range(1, n+1):
    if indegree[i] == 0:
        heapq.heappush(queue, i)


while queue:
    cur = heapq.heappop(queue)
    res.append(cur)

    for v in graph[cur]:
        indegree[v] -= 1

        if indegree[v] == 0:
            heapq.heappush(queue, v)

print(*res)
```
