## 문제 요약

**경쟁적 전염 ( 골드 5 )**

1. N * N 크기의 시험관
2. 바이러스 종류 : 1 ~ K
- 모든 바이러스는 1초마다 상, 하, 좌, 우의 방향으로 증식
- 매 초마다 번호가 낮은 종류의 바이러스부터 먼저 증식
- 증식 과정에서 특정한 칸에 이미 어떠한 바이러스가 존재한다면, 그 곳에는 다른 바이러스가 들어갈 수 업승ㅁ
3. S초가 지난 후, (X,Y)에 존재하는 바이러스의 종류를 출력하는 프로그램 작성하기
4. S초가 지난 후 해당 위치에 바이러스가 존재하지 않는다면, 0을 출력

## 입력
1. 첫째 줄 : N, K
2. 둘째줄 ~ N번째 줄 : 시험관의 정보
3. 각 행은 N개의 원소로 구성
4. 해당 위치에 존재하는 바이러스의 번호가 공백을 기준으로 구분되어 주어짐
5. 해당 위치에 바이러스가 존재하지 않는 경우 0이 주어짐
6. 모든 바이러스의 번호는 K이하의 자연수

## 출력
1. S초 뒤에 (X,Y)에 존재하는 바이러스의 종류를 출력
2. S초 뒤에 해당 위치에 바이러스가 존재하지 않는다면, 0을 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 400ms

```python
import sys
from collections import deque
def bfs():
    while queue:
        # x,y,바이러스,시간
        x2, y2, c2, s2 = queue.popleft()
        if s2 == s:
            return board[x - 1][y - 1]

        for i in range(4):
            nx = x2 + dx[i]
            ny = y2 + dy[i]
            # 현재 s 초에서 바이러스가 다 퍼졌을 때
            if 0 <= nx < n and 0 <= ny < n:
                # 갈 수 있을 경우
                if board[ny][nx] == 0:
                    for k1 in range(1, k+1):
                        if c2 == k1:
                            queue.append((nx,ny,c2,s2+1))
                            board[ny][nx] = k1


input = sys.stdin.readline

n,k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

# s : 시간, x,y : 좌표
s,x,y = map(int, input().split())
check_list = [i for i in range(1, k+1)]
sub_list = []
for y1 in range(n):
    for x1 in range(n):
        for c1 in range(k):
            if board[y1][x1] == check_list[c1]:
                sub_list.append([x1,y1,board[y1][x1], 0])

# 정렬
sub_list.sort(key=lambda x:x[2])

queue = deque(sub_list)

if len(queue) == 0:
    print(0)
    exit(0)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

ans = bfs()
if ans == None:
    print(board[x-1][y-1])
else:
    print(ans)
```

1. QUEUE 에 우선순위대로 담기
2. BFS 탐색 진행
3. 예외 처리
4. 다음으로 갈 수 있을경우, BFS 탐색 진행