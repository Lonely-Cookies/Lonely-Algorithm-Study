## 문제 요약

**진우의 달 여행 ( small )**
1. 지구와 우주 사이 : N * M 행렬로 표현할 수 있음
- 각 원소의 값 : 우주선이 그 공간을 지날 때 소모되는 연료의 양

2. 여행 경비를 아끼기 위한 특이한 우주선 선택
- 방향 : 왼쪽 아래, 아래, 오른쪽 아래
- 전에 움직인 방향으로 움직일 수 없음

3. 목표 : 연료를 최대한 아끼며 지구의 어느위치에서든 출발하여 달의 어느 위치든 착륙하는 것
- 연료의 최소값 계산하기


## 입력
1. 행렬의 크기 N, M

2. 원소의 값

## 출력
1. 최소 연료의 값 출력

## 풀이
1. dfs

## 코드

### ( 정답 ) : 시간 44ms

```python
import sys

# 방향
direction = [-1,0,1]
def dfs(x, y, d, num):
    if y == n-1:
        ans_list.append(num)

    for i in direction:
        if i != d:
            if 0 <= x + i < m and 0 <= y + 1 < n:
                dfs(x + i, y + 1, i, num + board[y+1][x+i])

input = sys.stdin.readline

n, m = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]

ans_list = []

for i in range(m):
    dfs(i, 0, 222, board[0][i])

print(min(ans_list))
```