## 문제 요약

**RGB 거리 ( 실버 1 )**

1. N개의 집
- 빨강, 초록, 파랑 중 하나의 색으로 칠해야 함
- 각 비용이 주어졌을 때, 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값 구하기
- 이웃 집간 색이 달라야 함

## 입력
1. 집의 수 N

## 출력
1. 첫째 줄에 모든 집을 칠하는 비용의 최솟값 출력하기

## 코드

### 정답 : 시간 48ms

```python
import sys

input = sys.stdin.readline

n = int(input())

n_list = []
# 집 비용 넣기
for _ in range(n):
    n_list.append(list(map(int, input().split())))

# 최소 비용을 저장하는 리스트
dp = [[0] * 3 for _ in range(n+1)]

for i in range(1, n+1):
    # 이전까지 더했던 최솟값 + 그 다음 값
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + n_list[i-1][0]
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + n_list[i-1][1]
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + n_list[i-1][2]

print(min(dp[-1]))

```
