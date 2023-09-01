## 문제 요약

**숨바꼭질 4 ( 골드 4 )**

1. 수빈 : 현재 위치 n
- 걷거나 순간이동 가능
- 걷기 : x-1, x+1 이동
- 순간이동 : 2 * x 위치로 이동

2. 동생 : 현재 위치 k

3. 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는
가장 빠른 시간이 몇 초 후인지 구하는 프로그램 작성하기

## 입력
1. 수빈위치 n, 동생위치 k

## 출력
1. 수빈이가 동생을 찾는 가장 빠른 시간 출력

2. 어떻게 이동해야하는지 공백으로 구분해 출력

## 풀이
1. bfs 탐색

## 코드

### 정답 : 시간 192ms

```python
import sys
from collections import deque

input = sys.stdin.readline

# 수빈 : n, 동생 : k
n, k = map(int, input().split())

# 방문 위치
parent = [-1] * 100001

queue = deque()
# 수빈의 처음 위치, 시간
queue.append((n,0))

# 방문 처리
parent[n] = 0
res = [k]
while queue:
    # 현 위치
    cur, time = queue.popleft()

    if cur == k:
        print(time)
        for i in range(time):
            res.append(parent[res[-1]])
        print(*reversed(res))
        break

    for i in (cur-1, cur+1, cur * 2):
        # 예외 처리
        if 0 <= i <= 100000:
            # 방문하지 않은 위치일 경우
            if parent[i] == -1:
                queue.append((i, time+1))
                parent[i] = cur

```
