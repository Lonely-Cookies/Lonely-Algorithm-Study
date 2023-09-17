```python
import sys
N = int(sys.stdin.readline())
dp = [-1] * 1001

dp[1] = 1  # 상근 패
dp[2] = 0  # 창영 패
dp[3] = 1  # 상근 패

for n in range(4, N+1):
    dp[n] = min(dp[n-1], dp[n-3]) + 1

if dp[N] % 2 == 0:
    print("SK")
else:
    print("CY")


```
