## 문제 요약

**열쇠 ( 골드 1 )**
1. 평먼도 : 문서의 위치가 모두 나타나 있음

2. 빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 필요함

3. 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있음

4. 상하좌우로 이동 가능

5. 훔칠 수 있는 문서의 최대 개수를 구하는 프로그램 작성하기


## 입력
1. 테스트 케이스의 개수 ( < 100 )

2. 지도의 높이 h, 너비 w

3. h 개의 줄에는 빌딩을 나타내는 w 개의 문자가 주어짐
- . : 빈 공간
- * : 벽 ( 통과 X )
- $ : 훔쳐야하는 문서
- 알파벳 대문자 : 문
- 알파벳 소문자 : 열쇠 -> 대문자인 모든 문을 열 수 있음

4. 마지막 줄 : 이미 가지고 있는 열쇠가 공백없이 주어짐
- 열쇠를 하나도 가지고 있지 않는 경우, 0 이 주어짐

5. 처음 위치 : 빌딩 밖
- 빌딩 가장자리의 벽이 아닌 곳을 통해 빌딩 안팎을 드나들 수 있음
- 각각의 문에 대해서, 그 문을 열 수 있는 열쇠는 0개, 1개 또는 그 이상


## 출력
1. 각 테스트 케이스 마다, 상근이가 훔칠 수 있는 문서의 최대 개수 출력하기

## 풀이
1. bfs 탐색 진행
- . 일 경우 탐색 진행
- 소문자 upper 해버려서 대문자로 만들고, 대문자로 만든 리스트 안에 필요한 원소가 존재하는지 체크
- 존재하면 문 열고 열쇠 가져오기
- 열쇠 가져오면 해당 위치는 . 으로 표시하고, 열쇠 챙기고 다시 처음부터 탐색 진행하기 ( 재귀함수 )


## 코드

### 내가 푼 코드 ( 실패 )

```python
import sys
from collections import deque

def check():
    for y in range(h):
        for x in range(w):
            if visited[y][x] == True:
                visited[y][x] = False

input = sys.stdin.readline
# testCase
t = int(input())

for _ in range(t):
    # 높이, 너비
    h, w = map(int, input().split())

    # 맵 만들기
    board = []

    # 방문 처리
    visited = [[False] * w for _ in range(h)]

    for y in range(h):
        s = input().strip()
        s_list = []
        for i in s:
            s_list.append(i)
        board.append(s_list)

    # 키 리스트 만들기 ( 소문자 -> 대문자 )
    k = input().strip()
    k_list = []
    for key in k:
        if key == '0':
            continue
        k_list.append(key.upper())

    # 문서 갯수
    cnt = 0

    # 외벽 입구
    entry_list = deque()

    # 가장자리로만 들어갈 수 있음
    for y in range(h):
        for x in range(w):
            # 가장 윗줄 / 아랫 줄
            if y == 0 or y == h-1 or x == 0 or x == w-1:
                if board[y][x] == '$':
                    cnt += 1
                    board[y][x] = '.'
                    entry_list.append((x,y,0))
                elif board[y][x] != '*':
                    # 문일경우
                    if 65 <= ord(board[y][x]) <= 90:
                        entry_list.append((x,y,1))
                    # 열쇠일 경우
                    elif 97 <= ord(board[y][x]) <= 122:
                        k_list.append(board[y][x].upper())
                        board[y][x] = '.'
                        entry_list.append((x,y,0))
                    # 빈 곳 일경우
                    else:
                        entry_list.append((x,y,0))
    # 들어갈 수 있는 공간 리스트
    queue = deque()

    while entry_list:
        x, y, c = entry_list.popleft()

        if c == 0:
            queue.append((x,y))
        elif c == 1 and board[y][x] in k_list:
            queue.append((x,y))

    # bfs 탐색 진행
    while queue:
        x, y = queue.popleft()
        # 방문 처리
        visited[y][x] = True

        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx = x + dx
            ny = y + dy
            # bfs 탐색 진행
            if 0 <= nx < w and 0 <= ny < h:
                if not visited[ny][nx]:
                    # 문서일 경우
                    if board[ny][nx] == '$':
                        # 문서 체크 표시
                        board[ny][nx] = '.'
                        visited[ny][nx] = True
                        cnt += 1
                        queue.append((nx, ny))

                    # 열쇠일 경우
                    elif 'a' <= board[ny][nx] <= 'z':
                        # 열쇠 추가
                        if board[ny][nx] not in k_list:
                            k_list.append(board[ny][nx].upper())

                        # 열쇠 체크
                        board[ny][nx] = '.'
                        check()
                        queue.append((nx, ny))
                    # 문일경우
                    elif 'A' <= board[ny][nx] <= 'Z':
                        # 문을 열 수 있는 열쇠가 있을 경우
                        if board[ny][nx] in k_list:
                            # 방문 처리
                            visited[ny][nx] = True
                            board[ny][nx] = '.'
                            queue.append((nx, ny))
                    # 갈 수 있는 길일경우
                    elif board[ny][nx] == '.':
                        # 방문처리
                        visited[ny][nx] = True
                        queue.append((nx, ny))

    print(cnt)

```

---

### 정답 코드 ( 성공 ) : 속도 224ms
```python
import sys
from collections import deque
from string import ascii_uppercase
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(start):
    global answer
    queue = deque()
    queue.append(start)
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            ax = x + dx[i]
            ay = y + dy[i]
            if 0 <= ax < H and 0 <= ay < W and board[ax][ay] != "*" and not visited[ax][ay]: #방문할 수 있는 경우
                if board[ax][ay].isupper(): # 문인 경우
                    if board[ax][ay] in key: # 열쇠가 있다면 방문
                        queue.append([ax, ay])
                        visited[ax][ay] = True
                    else: # 열쇠가 없다면 미방문 좌표로 저장
                        unlocked_door[board[ax][ay]].append([ax, ay])
                else: # 통로, 문서, 열쇠인 경우
                    queue.append([ax,ay])
                    visited[ax][ay] = True
                    if board[ax][ay] == "$": # 문서인 경우
                        answer += 1
                    if board[ax][ay].islower(): # 열쇠인 경우
                        key.add(board[ax][ay].upper()) # 열쇠흘 저장
                        for x1, y1 in unlocked_door[board[ax][ay].upper()]: # 해당 열쇠로 열 수 있는 미방문 좌표를 방문
                            queue.append([x1, y1])
                            visited[x1][y1] = True


for _ in range(int(input())):
    answer = 0
    H,W = map(int,input().split())
    board = [list(input().strip()) for _ in range(H)]
    key = set()
    unlocked_door = dict()
    for alphabet in ascii_uppercase:
        unlocked_door[alphabet] = []
    start = []
    for k in input().strip():
        if k == "0":
            break
        key.add(k.upper())
    visited = [[False for _ in range(W)] for _ in range(H)]
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1: # 테투리인 경우
                if board[i][j] != "*":
                    if board[i][j].isupper(): # 문인 경우 미방문 좌표로 저장
                        unlocked_door[board[i][j]].append([i, j])
                    else: # 아닌 경우 문서, 열쇠, 통로의 경우로 나누어서 처리
                        if board[i][j] == "$":
                            answer += 1
                        elif board[i][j].islower():
                            key.add(board[i][j].upper())
                        start.append([i,j])
                        visited[i][j] = True
    for k in key: # 지금 갖고있는 열쇠로 방문할 수 있는 미방문 좌표 탐색
        for x,y in unlocked_door[k]:
            start.append([x,y])
            visited[x][y] = True
    for s in start: # 테두리의 가능한 시작좌표에 대해 탐색시작
        bfs(s)
    print(answer)
```

차이점
1. 문 탐색 방법에서 차이가 있었음
- 열쇠를 얻고나서 갈 수 있는 문 체크를 한번 더 해주었어야 했다.