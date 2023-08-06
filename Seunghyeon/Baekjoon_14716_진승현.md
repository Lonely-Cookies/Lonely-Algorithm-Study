## 문제 요약

**현수막 ( 실버 1 )**

1. 현수막에서 글자가 몇 개인지 알아보는 프로그램 만들기
2. 글자 : 1, 글자가 아닌 부분 : 0
3. 방향 : 상 하 좌 우 대각선
4. 글자의 개수 출력하기

## 입력
1. 현수막의 크기 m, n
2. 현수막의 정보가 0,1 로 주어짐

## 출력
1. 글자의 개수 출력하기

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 196ms

```python
import sys
sys.setrecursionlimit(10**6)
# 상 하 좌 우 대각선
D = ((0,1), (0,-1), (1,0), (-1,0), (1,1), (1,-1), (-1,1), (-1,-1))
def dfs(x1,y1):
    # 현재 위치 방문 처리
    board[y1][x1] = '#'

    for i in D:
        dx = x1 + i[0]
        dy = y1 + i[1]

        if 0 <= dx < m and 0 <= dy < n:
            # 글자
            if board[dy][dx] == 1:
                dfs(dx,dy)

input = sys.stdin.readline

n,m = map(int, input().split())
board = []

for _ in range(n):
    board.append(list(map(int, input().split())))

# 갯수
cnt = 0

for y in range(n):
    for x in range(m):
        if board[y][x] == 1:
            dfs(x,y)
            cnt += 1

print(cnt)
```

1. 맵 만들기, 방향 설정하기
2. dfs 호출 → 글자인 부분 체크
3. 글자 갯수 세기
