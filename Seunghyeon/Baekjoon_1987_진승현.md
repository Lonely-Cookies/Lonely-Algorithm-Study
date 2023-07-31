## 문제 요약

**알파벳 ( 골드 4 )**

1. 세로 : r, 가로 : c
2. 말 : 좌측 상단 ( 1행 1열 ) 위치
3. 말 : 상하좌우 이동 가능
4. 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀있는 알파벳과는 달라야 함
4. 좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지 구하는 프로그램 작성하기
5. 말이 지나는 칸은 좌측 상단의 칸도 포함

## 입력
1. r, c
2. 알파벳

## 출력
1. 말이 지날 수 있는 최대 칸 수 출력하기

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 6376ms

```python
import sys
def back(x,y, cnt):
    global ans
    # 최대 깊이 계산
    ans = max(ans, cnt)

    for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
        nx = x + dx
        ny = y + dy

        # 예외 처리
        if 0 <= nx < c and 0 <= ny < r:
            # 아직 방문하지 않았을 경우
            if not visited[board[ny][nx]]:
                # 방문 처리
                visited[board[ny][nx]] = True
                back(nx,ny, cnt + 1)
                visited[board[ny][nx]] = False

input = sys.stdin.readline

r,c = map(int, input().split())
board = [list(map(lambda x: ord(x) - 65, input().strip())) for _ in range(r)]

visited = [False for _ in range(26)]

# 처음 위치 방문 처리
visited[board[0][0]] = True
ans = 1

back(0,0,1)
print(ans)

```

1. 맵 만들기, 방향 설정하기, 방문 리스트 만들기
2. 백트래킹 호출

### 더 빠른 코드 : 시간 208ms

```python
import sys
def bfs(x,y, alpha):
    global ans

    stack = [(x,y,alpha)]
    # 방문 처리
    visited[y][x] = board[y][x]

    while stack:
        x,y,alpha = stack.pop()
        # 최대 길이
        if ans < len(alpha):
            ans = len(alpha)

        # 끝값
        if ans == 26:
            return

        for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
            nx = x + dx
            ny = y + dy

            if 0 <= nx < c and 0 <= ny < r:
                if board[ny][nx] not in alpha:
                    check = alpha + board[ny][nx]
                    # 아직 가지 않았을 경우
                    if visited[ny][nx] != check:
                        # 방문 처리
                        visited[ny][nx] = check
                        stack.append((nx,ny,check))

input = sys.stdin.readline

r,c = map(int, input().split())
board = [list(input()) for _ in range(r)]
visited = [[[''] for _ in range(c)] for _ in range(r)]

ans = 0

bfs(0,0,board[0][0])
print(ans)
```

차이점
- bfs
- 방문 처리를 bfs에 맞춰 깔끔하게 해주었음
