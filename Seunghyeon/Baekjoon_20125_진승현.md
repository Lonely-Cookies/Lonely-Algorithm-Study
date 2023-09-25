## 문제 요약

**쿠키의 신체 측정**
1. 쿠키들의 신체 이상
- 팔 다리 길이가 임의적으로 변함

2. 신체 측정을 위해 한 변의 길이가 n인 정사각형 판 위에 누워있음
- 머리, 심장, 허리, 좌우 팔, 다리
- 머리는 심장 바로 윗칸에 1칸 크기로 존재
- 왼쪽 팔: 심장 바로 왼쪽
- 오른쪽 팔 : 심장 바로 오른쪽
- 허리 :심장의 바로 아래
- 왼쪽 다리 : 허리의 왼쪽 아래
- 오른쪽 다리 : 허리의 오른쪽 아래

3. 쿠키의 신체가 주어졌을 때 심장의 위치와 팔, 다리, 허리 길이 구하기


## 입력
1. n * n

## 출력
1. 심장이 위치한 행의 번호 x, y
2. 왼쪽 팔, 오른쪽 팔, 허리, 왼쪽 다리, 오른쪽 다리의 길이 출력
- * : 쿠키의 신체
- _ : 쿠키의 신체 아님

## 코드

### ( 정답 ) : 시간 168ms

```python
import sys

input = sys.stdin.readline

n = int(input())

board = [list(input().strip()) for _ in range(n)]

# 왼쪽 팔, 오른쪽 팔, 허리, 왼쪽 다리, 오른쪽 다리
left1, right1, mid, left2, right2 = 0,0,0,0,0
# 심장 위치 저장
heart_x, heart_y = 0, 0

for y in range(n):
    for x in range(n):
        # 머리 위치 찾기
        if board[y][x] == '*' and ( heart_x == 0 and heart_y == 0):
            # 심장 위치 설정
            heart_x = x+1
            heart_y = y+2
            # 탐색 ( 왼쪽, 오른쪽, 아래, 왼쪽 아래, 오른쪽 아래 )
            xx = x-1
            # 왼쪽
            while xx >= 0 and board[y+1][xx] == '*':
                left1 += 1
                xx -= 1

            xxx = x+1
            # 오른쪽
            while xxx < n and board[y+1][xxx] == '*':
                right1 += 1
                xxx += 1

            # 아래
            y3 = y+2
            while y3 < n and board[y3][x] == '*':
                mid += 1
                y3 += 1

            # 왼쪽, 오른쪽 아래
            x4, x5 = x-1, x+1
            y4, y5 = y3, y3
            while y4 < n and board[y4][x4] == '*':
                left2 += 1
                y4 += 1
            while y5 < n and board[y5][x5] == '*':
                right2 += 1
                y5 +=1

            print(heart_y, heart_x)
            print(left1, right1, mid, left2, right2)
            exit(0)
```