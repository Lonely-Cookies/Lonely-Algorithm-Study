```python
import sys

N, K = map(int, sys.stdin.readline().split())

obj_list = []
obj_list.append((0, 0))

for _ in range(N):
    W, V = map(int, sys.stdin.readline().split())

    obj_list.append((W, V))

dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, K+1):
        weight = obj_list[i][0]
        value = obj_list[i][1]

        if weight > j:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j - weight] + value, dp[i-1][j])

print(dp[N][K])

```
