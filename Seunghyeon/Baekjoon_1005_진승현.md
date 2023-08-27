## 문제 요약

**ACM Craft ( 골드 3 )**
1. 건물을 짓는 순서가 정해져 있지 않음
- 첫번째 게임과 두번째 게임이 건물을 짓는 순서가 다를 수 있음
- 매 게임시작 시 건물을 짓는 순서가 주어짐

2. 모든 건물은 각각 건설을 시작하여 완성이 될 때 까지 딜레이가 존재함
- 동시에 진행할 수 있는 건설의 경우, 동시에 진행 가능

3. 특정 건물을 가장 빨리 지을 때 까지 걸리는 최소 시간을 알아내는 프로그램 작성하기



## 입력
1. 테스트케이스의 개수 T
2. 첫번째 줄엔 건물의 개수 N, 건물간의 건설순서 규칙의 총 개수 K
- 건물의 번호 : 1 ~ N
3. 둘째 줄엔 각 건물당 건설에 걸리는 시간이 주어짐

4. 셋째줄 부터 K + 2 줄까지 건설순서 X Y 가 주어짐
- 건물 X 를 지은 다음에 건물 Y를 짓는 것이 가능

5. 마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W 가 주어짐


## 출력
1. 건물 W를 건설완료하는데 드는 최소 시간 출력하기
## 풀이
1. 위상정렬 문제
- 동시에 지을 수 있는 건물의 경우, 가장 오래걸리는 시간 적용하기

## 코드

### 위상 정렬 ( 정답 ) : 시간 1424ms

```python
import sys
from collections import deque

input = sys.stdin.readline
# testCase
t = int(input())

for _ in range(t):
    # 건물의 개수 n, 건설순서 규칙의 총 갯수 k
    n, k = map(int, input().split())

    # 위상정렬 그래프
    graph = [[] for _ in range(n)]
    indegree = [0] * n

    # 각 건물당 걸리는 시간
    n_time = list(map(int, input().split()))
    # 건설순서 x, y
    for _ in range(k):
        x,y = map(int, input().split())
        # index 맞추기
        x -= 1
        y -= 1
        # 위상정렬 설정
        graph[x].append(y)
        indegree[y] += 1
    # 찾아야할 원소
    la = int(input())
    la -= 1

    queue = deque()
    res = [0 for _ in range(n)]

    for i in range(n):
        if indegree[i] == 0:
            queue.append(i)
            res[i] = n_time[i]

    while queue:
        cur = queue.popleft()

        for v in graph[cur]:
            indegree[v] -= 1
            res[v] = max(res[cur]+n_time[v], res[v])

            if indegree[v] == 0:
                queue.append(v)

    print(res[la])
```