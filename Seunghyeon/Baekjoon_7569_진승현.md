## 문제 요약

** 토마토 ( 골드 5 )**

1. 토마토 창고 : 익은 토마토 ( 1 ), 안익은 토마토 ( 0 )
- 3차원 공간

2. 현재 칸이 익은 토마토일 경우, 인접한 6개의 칸 ( 동, 서, 남, 북, 상, 하 ) 에 존재하는 안익은 토마토를 하루만에 익은 토마토로 바꿔버림
- 0 -> 1
- 대각선 이동은 불가능

3. 며칠이 지나면 토마토들이 전부 다 익는지 최소 일수 구하기

## 입력
1. 상자의 크기 ( m * n), 상자의 수 ( h )

2. 둘째 줄 부터 상자에 저장된 토마토들의 정보가 주어짐
- 익은 토마토 : 1
- 안익은 토마토 : 0
- 토마토가 들어있지 않은 칸 : -1

3. 토마토가 하나 이상 있는 경우에만 입력으로 주어짐

## 출력
1. 토마토가 모두 익을 때 까지 최소 며칠이 걸리는지 계산하기
2. 토마토가 모두 익지 못하는 상황일 경우, -1 출력


## 코드

### 내가 푼 코드 ( 정답 ) : 시간 812ms

```python
import sys
from collections import deque

D = [(-1,0,0),(1,0,0),(0,-1,0),(0,1,0),(0,0,-1),(0,0,1)]

def bfs(temp):
    queue = deque()
    cnt = 0
    for temps in temp:
        queue.append(temps)

    while queue:
        x3,y3,z3,d3 = queue.popleft()

        for dx,dy,dz in D:
            nx = x3 + dx
            ny = y3 + dy
            nz = z3 + dz
            dd = d3

            # 예외 처리
            if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h:
                # 다음 위치가 익지 않은 토마토일 경우
                if board[nz][ny][nx] == 0:
                    queue.append((nx,ny,nz,dd+1))
                    # 방문 처리
                    board[nz][ny][nx] = 1
            if cnt < dd:
                cnt = dd
    return cnt
def solve():
    temp = []
    for z1 in range(h):
        for y1 in range(n):
            for x1 in range(m):
                if board[z1][y1][x1] == 1:
                    temp.append((x1,y1,z1,0))

    return bfs(temp)


def minus():
    for z1 in range(h):
        for y1 in range(n):
            for x1 in range(m):
                if board[z1][y1][x1] == 0:
                    return -1
    return 0
input = sys.stdin.readline

m,n,h = map(int, input().split())

board = []

for z in range(h):
    z_list = []
    for y in range(n):
        z_list.append(list(map(int,input().split())))

    board.append(z_list)


ans1 = solve()
ans2 = minus()

if ans2 == -1:
    print(ans2)
else:
    print(ans1)


```

1. 현재 익은 토마토가 존재하는 저장공간 생성
2. bfs 탐색 진행
3. bfs 탐색 후 안익은 토마토가 존재하면 -1 출력
4. 그렇지않으면 걸린 일수 출력

### 더 빠른 코드 : 시간 668ms

```python
import sys
from collections import deque

D = [(-1,0,0),(1,0,0),(0,-1,0),(0,1,0),(0,0,-1),(0,0,1)]

def minus():
    for z1 in range(h):
        for y1 in range(n):
            for x1 in range(m):
                if board[z1][y1][x1] == 0:
                    return -1
    return 0

input = sys.stdin.readline

m,n,h = map(int, input().split())
cnt = 0
board = [[] for _ in range(h)]

queue = deque()

for z in range(h):
    for y in range(n):
        board[z].append(list(map(int, input().split())))
        for x in range(m):
            if board[z][y][x] == 1:
                queue.append((x,y,z,0))

while queue:
    x3,y3,z3,d3 = queue.popleft()

    for dx,dy,dz in D:
        nx = x3 + dx
        ny = y3 + dy
        nz = z3 + dz
        dd = d3

        # 예외 처리
        if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h:
            # 다음 위치가 익지 않은 토마토일 경우
            if board[nz][ny][nx] == 0:
                queue.append((nx,ny,nz,dd+1))
                # 방문 처리
                board[nz][ny][nx] = 1
        if cnt < dd:
            cnt = dd

ans2 = minus()

if ans2 == -1:
    print(ans2)
else:
    print(cnt)



```

차이점
- bfs 를 함수로 진행하지 않았음
- board 에 토마토 층을 넣을 때, 한방에 넣었음
    - 불필요한 함수 제거 가능
    - 코드가 더 깔끔해짐

아쉬운 점
- bfs 진행 후 안익은 토마토가 존재하는 부분을 체크하는 과정에서 걸리는 시간을 줄이지 못했음
- 변수 하나로 출력할 수 있을 것 같은데, 방법을 잘 모르겠음