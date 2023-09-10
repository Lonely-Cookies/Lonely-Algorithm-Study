```python
import sys
N = int(sys.stdin.readline())
dp = [-1] * 1001

dp[1] = 1  # 상근 승
dp[2] = 0  # 창영 승
dp[3] = 1  # 상근 승

# 턴 수를 최소한으로 쓴다고 가정
# 마지막 돌을 가져간 사람이 이기기 때문에 홀수 턴에는 상근이가, 짝수 턴에는 창영이가 이김

for n in range(4, N+1):
    dp[n] = min(dp[n-1], dp[n-3]) + 1

if dp[N]%2 == 1:
    print("SK")
else:
    print("CY")
```
