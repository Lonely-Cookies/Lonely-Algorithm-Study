## 문제 요약

**불! ( 골드 4 )**

1. 지훈이 불에 타기 전 탈출 여부
2. 탈출한다면 얼마나 빨리 탈출할 수 있는지
3. 지훈, 불의 방향: 상하좌우
4. 지훈 : 미로의 가장자리에 접한 공간에서 탈출 가능

## 입력
1. 정수 r, c

## 출력
1. 미로 탈출 X : IMPOSSIBLE 출력
2. 미로 탈출 O : 가장 빠른 탈출시간 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 1380ms

```python
import sys
from collections import deque
def bfs():
    while fire_queue:
        x,y = fire_queue.popleft()

        for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
            nx = x + dx
            ny = y + dy

            if 0 <= nx < c and 0 <= ny < r:
                if not fire[ny][nx] and board[ny][nx] != '#':
                    fire[ny][nx] = fire[y][x] + 1
                    fire_queue.append((nx,ny))

    while ji_queue:
        x, y = ji_queue.popleft()

        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx = x + dx
            ny = y + dy

            if 0 <= nx < c and 0 <= ny < r:
                if not ji[ny][nx] and board[ny][nx] != '#':
                    if not fire[ny][nx] or fire[ny][nx] > ji[y][x] + 1:
                        ji[ny][nx] = ji[y][x] + 1
                        ji_queue.append((nx,ny))
            else:
                return ji[y][x]

    return "IMPOSSIBLE"

input = sys.stdin.readline

r,c = map(int, input().split())
board = [list(input().strip()) for _ in range(r)]

# 불의 위치, 지훈의 위치
fire = [[0 for _ in range(c)] for _ in range(r)]
ji = [[0 for _ in range(c)] for _ in range(r)]

fire_queue = deque()
ji_queue = deque()

for y in range(r):
    for x in range(c):
        if board[y][x] == 'F':
            fire[y][x] = 1
            fire_queue.append((x,y))
        if board[y][x] == 'J':
            ji[y][x] = 1
            ji_queue.append((x,y))

print(bfs())
```

1. BFS 탐색 진행 전, 불의 위치와 지훈의 위치 탐색
2. BFS 탐색 하면서, 각 fire, ji 리스트에 숫자 체크
3. 불이 가지 않는 곳이거나, 불보다 지훈이 먼저 가는 경우 체크
