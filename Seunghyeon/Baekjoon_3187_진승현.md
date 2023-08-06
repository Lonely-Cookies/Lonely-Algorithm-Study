## 문제 요약

**양치기 꿍 ( 실버 1 )**

1. 늑대 >= 양 : 늑대 win, 그렇지 않으면 양 win
2. 살아남은 늑대, 양의 갯수 출력하기

## 입력
1. 영역의 세로, 가로
2. 지도

## 출력
1. 살아남게 되는 양과 늑대의 수를 순서대로 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 188ms

```python
import sys
sys.setrecursionlimit(10**6)
D = [(1,0), (-1,0), (0,1), (0,-1)]
v1,k1 = 0,0
def dfs(x1, y1):
    global v1
    global k1
    # 늑대일 경우
    if board[y1][x1] == 'v':
        v1 += 1

    elif board[y1][x1] == 'k':
        k1 += 1

    # 방문 처리
    board[y1][x1] = '@'

    for i in D:
        dx = x1 + i[0]
        dy = y1 + i[1]

        # 예외 처리
        if 0 <= dx < c and 0 <= dy < r:
            # 갈 수 있는 경우
            if board[dy][dx] != '#' and board[dy][dx] != '@':
                dfs(dx,dy)


input = sys.stdin.readline

r,c = map(int, input().split())

board = []
ans = [0,0]
# 지도 만들기
for _ in range(r):
    s = input().strip()
    s_list = []
    for i in s:
        s_list.append(i)
    board.append(s_list)

for y in range(r):
    for x in range(c):
        # 벽이 아닐 경우
        if board[y][x] != '#':
            dfs(x,y)
            # 늑대가 더 많았을 때
            if v1 >= k1:
                ans[1] += v1
            else:
                ans[0] += k1
            v1, k1 = 0,0
print(*ans)

```

1. 맵 만들기, 방향 설정하기
2. dfs 호출 → 양과 늑대 갯수 세기
3. 늑대가 더 많을 경우, 늑대에 더하고, 그렇지 않으면 양에 더하기
4. 출력

### 더 빠른 코드 : 시간 100ms

```python
import sys
D = [(1,0), (-1,0), (0,1), (0,-1)]

def dfs(x1, y1):
    v1, k1 = 0, 0
    # 늑대일 경우
    if board[y1][x1] == 'v':
        v1 += 1

    elif board[y1][x1] == 'k':
        k1 += 1

    # 방문 처리
    board[y1][x1] = '#'

    stack = []
    stack.append((x1,y1))

    while stack:
        x2, y2 = stack.pop()

        for dx, dy in D:
            nx = x2 + dx
            ny = y2 + dy

            if 0 <= nx < c and 0 <= ny < r:
                if board[ny][nx] != '#':
                    if board[ny][nx] == 'k':
                        k1 += 1
                    if board[ny][nx] == 'v':
                        v1 += 1
                    board[ny][nx] = '#'
                    stack.append((nx,ny))
    return (k1, 0) if k1 > v1 else (0, v1)

input = sys.stdin.readline

r,c = map(int, input().split())

board = []
ans = [0,0]
# 지도 만들기
for _ in range(r):
    s = input().strip()
    s_list = []
    for i in s:
        s_list.append(i)
    board.append(s_list)

for y in range(r):
    for x in range(c):
        # 벽이 아닐 경우
        if board[y][x] != '#':
            k2, v2 = dfs(x,y)
            ans[0] += k2
            ans[1] += v2
print(*ans)
```

차이점
- 재귀 호출 X
- 전역 변수 사용 X
