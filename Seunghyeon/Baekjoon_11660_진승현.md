## 문제 요약

**구간 합 구하기 5 ( 실버 1 )**

1. 표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램 작성하기

## 입력
1. 표의 크기 : N
2. 합을 구해야하는 횟수 M
3. 둘째 줄 ~ N 개의 줄 : 표에 채워져 있는 수
4. M 개의 줄 : 4개의 정수 x1, y1, x2, y2
5. (x1, y1) ~ (x2,y2) 의 합을 구해 출력하기

## 출력
1. (x1, y1) ~ (x2,y2) 의 합을 구해 출력하기
## 코드

### 내가 푼 코드 ( 정답 ) : 시간 1048ms

```python
import sys

input = sys.stdin.readline

n,m = map(int, input().split())

n_list = []
for _ in range(n):
    n_list.append(list(map(int, input().split())))

dp = [[0] * (n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + n_list[i-1][j-1]

for k in range(m):
    x1,y1,x2,y2 = map(int, input().split())

    ans = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]
    print(ans)

```

1. 직사각형을 구하기 위한 방법 생각