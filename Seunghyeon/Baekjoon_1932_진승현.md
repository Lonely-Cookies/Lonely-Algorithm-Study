## 문제 요약

**정수 삼각형 ( 실버 1 )**

1. 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램 작성
- 수 : 대각선 왼쪽, 대각선 오른쪽 중에 있는 것만 선택 가능

2. 삼각형의 크기 : 1 ~ 500
- 삼각형을 이루고 있는 수 : 모두 정수
- 범위는 0 이상 9999 이하

## 입력
1. 삼각형의 크기 n
2. 둘째줄 ~ n+1번째 줄 : 정수 삼각형

## 출력
1. 합이 최대가 되는 경로에 있는 수의 합 출력

## 풀이
1. 아래서부터 더하면서 올라가기

## 코드

### 정답 : 시간 132ms

```python
import sys

input = sys.stdin.readline

n = int(input())
n_list = []
# 삼각형 채우기
for _ in range(n):
    n_list.append(list(map(int, input().split())))

dp = []

for i in range(n+1):
    zero_list = [0] * (i+1)

    dp.append(zero_list)
# 뒤집기 ( 끝부터 더하기 위해 )
n_list.reverse()
dp.reverse()

for j in range(1, n+1):
    for k in range(len(dp[j])):
        dp[j][k] = max(dp[j-1][k], dp[j-1][k+1]) + n_list[j-1][k]

print(*dp[-1])

```
