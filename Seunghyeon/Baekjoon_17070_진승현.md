## 문제 요약

**파이프 옮기기 1 ( 골드 5 )**

1. 새 집의 크기 : N * N
2. r : 행의 번호, c : 열의 번호
3. 파이프의 회전 방향 : 3가지
- 가로, 세로, 대각선
4. 파이프 이동 방향 : 3가지
- 가로, 세로, 대각선

주의점) 대각선의 경우 2*2 칸을 차지함

5. 처음 위치 : (1,2), 방향 : 가로

## 입력
1. 집의 크기 N ( 3 <= N  <= 16 )
2. 빈칸 : 0, 벽 : 1
3. (1,1), (1,2) 는 항상 빈칸

## 출력
1. 파이프의 한쪽 끝을 (N, N)으로 이동시키는 방법의 수 출력
2. 이동시킬 수 없는 경우 0

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 524ms

```python
import sys

ans = 0
def dfs(x,y,d):
    global ans
    if x == n-1 and y == n-1:
        ans += 1
        return
    else:
        if d == 0 or d == 2:
            dx = x + 1
            # 그 다음위치를 갈 수 있는 경우
            if dx < n and board[y][dx] == 0:
                dfs(dx, y, 0)
        if d == 1 or d == 2:
            dy = y + 1
            if dy < n and board[dy][x] == 0:
                dfs(x, dy, 1)

        dx = x + 1
        dy = y + 1
        if dx < n and dy < n:
            if board[dy-1][dx] == 0 and board[dy][dx-1] == 0 and board[dy][dx] == 0:
                dfs(dx,dy,2)


input = sys.stdin.readline

n = int(input())
board = []
# map 만들기
for _ in range(n):
    board.append(list(map(int, input().split())))

if (board[0][2] == 1 and board[1][1] == 1) or (board[n-1][n-2] == 1 and board[n-2][n-1] == 1) or board[n-1][n-1] == 1:
    print(0)
else:
    dfs(1,0,0)
    print(ans)

```

1. 맵 만들기
2. 아예 도착지점까지 갈 수 없는 경우 제외하기
3. DFS 호출
- 도착지점에 도착하면 변수에 1 더하기
- 현재 방향이 가로일 때 -> 가로, 대각선 이동 가능
- 현재 방향이 세로일 때 -> 세로, 대각선 이동 가능
- 현재 방향이 대각선일 때 -> 가로, 세로, 대각선 이동 가능
4. 정답 호출

### 더 빠른 코드 : 시간 36ms

```python
import sys

n = int(input())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

# 직전 위치가 가로 / 세로 / 대각선
dp = [[[0, 0, 0] for _ in range(n)]  for _ in range(n)]

dp[0][1][0] = 1 # 시작점

for r in range(n):
    for c in range(n):
        if arr[r][c] != 1:
            # 가로 방향으로 오는 경우
            if c-1 >= 0:
                dp[r][c][0] += dp[r][c-1][0]
                dp[r][c][0] += dp[r][c-1][2]
            # 세로 방향으로 오는 경우
            if r-1 >= 0:
                dp[r][c][1] += dp[r-1][c][1]
                dp[r][c][1] += dp[r-1][c][2]

            # 대각선 방향으로 오는 경우
            if r-1 >= 0 and c-1 >= 0 and arr[r-1][c] != 1 and arr[r][c-1] != 1:
                dp[r][c][2] += dp[r-1][c-1][0]
                dp[r][c][2] += dp[r-1][c-1][1]
                dp[r][c][2] += dp[r-1][c-1][2]
# pp(dp)
print(sum(dp[n-1][n-1]))
```

차이점
- DP
