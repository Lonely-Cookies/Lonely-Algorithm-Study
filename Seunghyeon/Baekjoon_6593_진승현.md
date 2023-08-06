## 문제 요약

**상범 빌딩 ( 골드 5 )**

1. 상범 빌딩 : 각 변의 길이가 1인 정육면체로 이루어져 있음
- 3차원 공간

2. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나 비어있어서 지나갈 수 있게 되어있음
- 0, 1 ( 가거나, 못가거나 )

3. 각 칸에서 인접한 6개의 칸 ( 동, 서, 남, 북, 상, 하 ) 으로 1분의 시간을 들여 이동할 수 있음
- 6개의 방향, 걸리는 시간은 1분
- 대각선 이동은 불가능

4. 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출가능

## 입력
1. 여러 개의 테스트 케이스
- L : 층, R : 행, C : 열

2. 문자 표시
- 지나갈 수 없는 칸 : #
- 지나갈 수 있는 칸 : .
- 시작 지점 : S
- 탈출할 수 있는 출구 : E

3. 입력의 끝
- L,R,C 가 모두 0 으로 표현될 때 종료

4. 시작 지점과 출구는 항상 하나씩 존재

## 출력
1. 탈출할 수 있을 경우
- Escaped in x minute(s).
2. 탈출할 수 없을 경우
- Trapped!


## 코드

### 내가 푼 코드 ( 정답 ) : 시간 160ms

```python
import sys
from collections import deque

# 갈 수 있는 방향 표시
dx = [1,-1,0,0,0,0]
dy = [0,0,1,-1,0,0]
dz = [0,0,0,0,1,-1]

def bfs(x1, y1, z1):
    queue = deque()
    queue.append([x1, y1, z1])

    # 방문 표시
    board[z1][y1][x1] = 0

    while queue:
        x2,y2,z2 = queue.popleft()

        for i in range(6):
            nx = x2 + dx[i]
            ny = y2 + dy[i]
            nz = z2 + dz[i]

            # 예외처리
            if 0 <= nx < C and 0 <= ny < R and 0 <= nz < L:
                # 현 위치가 도착 지점 일 경우
                if board[nz][ny][nx] == 'E':
                    return board[z2][y2][x2] + 1
                # 갈 수 있는 길일경우
                if board[nz][ny][nx] == '.':
                    queue.append([nx,ny,nz])

                    # 방문 표시
                    board[nz][ny][nx] = board[z2][y2][x2] + 1
    return -1

input = sys.stdin.readline

# 입력 ( 층, 행, 열 )
while True:
    L,R,C = map(int, input().split())
    # 종료 조건
    if L == 0 and R == 0 and C == 0:
        break
    # 아파트
    board = []
    # 3차원 배열
    for z in range(L):
        # 한 층씩 저장
        z_list = []
        for y in range(R):
            s = input().strip()
            y_list = []
            for i in s:
                y_list.append(i)
            z_list.append(y_list)
        board.append(z_list)
        # 띄어쓰기 입력 받기
        jump = input()

    # 정답
    ans = -1

    for z in range(L):
        for y in range(R):
            for x in range(C):
                # 처음 위치 찾기
                if board[z][y][x] == 'S':
                    ans = bfs(x,y,z)

    if ans == -1:
        print("Trapped!")
    else:
        print(f"Escaped in {ans} minute(s).")
```

그래프 탐색 문제

BFS 를 통해 위, 아래 방향까지 탐색할 수 있도록 코드 작성

### 더 빠른 코드 : 시간 124ms

```python
import sys
from collections import deque

# 갈 수 있는 방향 표시
D = [(1,0,0),(0,1,0),(-1,0,0),(0,-1,0),(0,0,1),(0,0,-1)]

def bfs(x1, y1, z1):
    queue = deque()
    queue.append((x1, y1, z1))

    # 방문 표시
    board[z1][y1][x1] = 0

    while queue:
        x2,y2,z2 = queue.popleft()

        for dx,dy,dz in D:
            nx = x2 + dx
            ny = y2 + dy
            nz = z2 + dz

            # 예외처리
            if 0 <= nx < C and 0 <= ny < R and 0 <= nz < L:
                # 현 위치가 도착 지점 일 경우
                if board[nz][ny][nx] == 'E':
                    return board[z2][y2][x2] + 1
                # 갈 수 있는 길일경우
                if board[nz][ny][nx] == '.':
                    queue.append((nx,ny,nz))

                    # 방문 표시
                    board[nz][ny][nx] = board[z2][y2][x2] + 1
    return -1

def solve():
    for z in range(L):
        for y in range(R):
            for x in range(C):
                if board[z][y][x] == 'S':
                    ans = bfs(x,y,z)
                    if ans == -1:
                        return 'Trapped!'
                    else:
                        return f'Escaped in {ans} minute(s).'

input = sys.stdin.readline

# 입력 ( 층, 행, 열 )
while True:
    L,R,C = map(int, input().split())
    # 종료 조건
    if L == 0 and R == 0 and C == 0:
        break
    # 아파트
    board = []
    # 3차원 배열
    for z in range(L):
        # 한 층씩 저장
        z_list = []
        for y in range(R):
            s = input().strip()
            y_list = []
            for i in s:
                y_list.append(i)
            z_list.append(y_list)
        board.append(z_list)
        # 띄어쓰기 입력 받기
        jump = input()

    print(solve())

```

차이점
- 방향 표시를 한번에 해주었음
    - 반복문을 range() 함수를 안쓰고 for i in D 이런식으로 코드를 작성해주었음
- queue 에 값을 넣을 때 리스트가 아닌 set 으로 넣어주었음
- 정답을 출력할 때 함수로 묶어주었음