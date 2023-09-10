## 문제 요약

**사탕 게임 ( 실버 2 )**

1. N * N 크기에 사탕을 채워 넣음
- 사탕의 색은 모두 같지 않을 수 있음
- 사탕의 색이 다른 인접한 두칸을 고름
- 고른 칸에 들어있는 사탕을 서로 교환함
- 모든 같은 색으로 이루어져 있는 가장 긴 연속 부분을 고른 다음 사탕을 모두 먹음

2. 사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램 작성하기


## 입력
1. 보드의 크기 N

2. 사탕의 색상이 주어짐
- 빨간색 : C, 파란색 : P, 초록색 : Z, 노란색 : Y

## 출력
1. 상근이가 먹을 수 있는 사탕의 최대 개수 출력

## 풀이
1. Board 입력받기

2. 현재 상태일 때 사탕 갯수 체크하기

3. 상 / 하 / 좌 / 우 에서 만약 바꿀 수 있는 경우, 바꾸고 나서 사탕 갯수 체크하기

## 코드

### 정답 : 시간 328ms

```python
import sys

input = sys.stdin.readline

n = int(input())
# 지도 만들기
board = []

for _ in range(n):
    board.append(list(input().strip()))

# 최댓값을 저장하는 리스트
cnt_list = []

# 가장 위에서부터 탐색 진행
for y in range(n):
    for x in range(n):
        # 안바꾼 상태도 체크하기
        # 가로 체크
        x_cnt = 0
        # 왼쪽 체크
        for i in range(x, n):
            if board[y][x] == board[y][i]:
                x_cnt += 1
            else:
                break
        # 오른쪽 체크
        for i in range(x - 1, -1, -1):
            if board[y][x] == board[y][i]:
                x_cnt += 1
            else:
                break

        # 세로 체크
        y_cnt = 0
        # 윗 부분 체크
        for j in range(y, n):
            if board[y][x] == board[j][x]:
                y_cnt += 1
            else:
                break
        # 아랫부분 체크
        for j in range(y - 1, -1, -1):
            if board[y][x] == board[j][x]:
                y_cnt += 1
            else:
                break
        cnt_list.append(max(x_cnt, y_cnt))

        # 아랫부분과 자리 바꾸기
        if y != n-1 and (board[y][x] != board[y+1][x]):
            # 자리 바꾸기
            board[y][x], board[y+1][x] = board[y+1][x], board[y][x]
            # 가로 체크
            x_cnt = 0
            # 왼쪽 체크
            for i in range(x, n):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break
            # 오른쪽 체크
            for i in range(x-1, -1, -1):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break

            # 세로 체크
            y_cnt = 0
            # 윗 부분 체크
            for j in range(y, n):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break
            # 아랫부분 체크
            for j in range(y-1, -1, -1):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break

            # 원래대로 돌리기
            board[y][x], board[y + 1][x] = board[y + 1][x], board[y][x]
            cnt_list.append(max(x_cnt, y_cnt))

        # 윗부분과 자리 바꾸기
        if (y != 0) and (board[y][x] != board[y-1][x]):
            # 자리 바꾸기
            board[y][x], board[y -1][x] = board[y -1][x], board[y][x]
            # 가로 체크
            x_cnt = 0
            # 왼쪽 체크
            for i in range(x, n):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break
            # 오른쪽 체크
            for i in range(x - 1, -1, -1):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break

            # 세로 체크
            y_cnt = 0
            # 윗 부분 체크
            for j in range(y, n):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break
            # 아랫부분 체크
            for j in range(y - 1, -1, -1):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break

            # 원래대로 돌리기
            board[y][x], board[y -1][x] = board[y -1][x], board[y][x]
            cnt_list.append(max(x_cnt, y_cnt))

        # 왼쪽 부분과 자리 바꾸기
        if x != 0 and board[y][x] != board[y][x-1]:
            # 자리 바꾸기
            board[y][x], board[y][x-1] = board[y][x-1], board[y][x]
            # 가로 체크
            x_cnt = 0
            # 왼쪽 체크
            for i in range(x, n):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break
            # 오른쪽 체크
            for i in range(x - 1, -1, -1):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break

            # 세로 체크
            y_cnt = 0
            # 윗 부분 체크
            for j in range(y, n):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break
            # 아랫부분 체크
            for j in range(y - 1, -1, -1):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break

            # 원래대로 돌리기
            board[y][x], board[y][x - 1] = board[y][x - 1], board[y][x]
            cnt_list.append(max(x_cnt, y_cnt))

        # 오른쪽 부분과 자리 바꾸기
        if x != n-1 and (board[y][x] != board[y][x+1]):
            # 자리 바꾸기
            board[y][x], board[y][x + 1] = board[y][x + 1], board[y][x]
            # 가로 체크
            x_cnt = 0
            # 왼쪽 체크
            for i in range(x, n):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break
            # 오른쪽 체크
            for i in range(x - 1, -1, -1):
                if board[y][x] == board[y][i]:
                    x_cnt += 1
                else:
                    break

            # 세로 체크
            y_cnt = 0
            # 윗 부분 체크
            for j in range(y, n):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break
            # 아랫부분 체크
            for j in range(y - 1, -1, -1):
                if board[y][x] == board[j][x]:
                    y_cnt += 1
                else:
                    break

            # 원래대로 돌리기
            board[y][x], board[y][x + 1] = board[y][x + 1], board[y][x]
            cnt_list.append(max(x_cnt, y_cnt))

print(max(cnt_list))

```
