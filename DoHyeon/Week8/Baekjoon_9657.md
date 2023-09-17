```python
import sys
N = int(sys.stdin.readline())
dp = [-1] * 1001

dp[1] = 1 # 상근이 승
dp[2] = 0 # 창영이 승
dp[3] = 1 # 상근이 승
dp[4] = 1 # 상근이 승
dp[5] = 1 # 상근이 승
# 잘 생각해보자.
# 1개가 남았으면 상근이가 이긴다.(그냥 1개 가져가면 그만)
# 2개가 남았으면 상근이가 진다.(무조건 1개는 가져가야 하는데 그러면 창영이가 남은 1개를 가져감)
# 3개가 남았으면 상근이가 이긴다.(3개 가져가면 끝)
# 4개가 남았어도 상근이가 이긴다.(4개 가져가면 끝)
# 5개는...? 상근이가 1개를 가져갔다면 지고, 3개를 가져가면 2개를 남겨놔서 이기고, 4개를 가져가면 진다.
# 즉 5개 일때는 상근이가 최선을 다한다고 가정할 때 3개를 가져가면 무조건 이길 수 있다.
# 6개 일 때는 어떨까? dp[6] 이라 할 때 dp[5], dp[3], dp[2] 에서 4개를 가져가서 창영이 턴에 2개를 남겨놓으면?
# 즉 dp 값이 0일 경우가 존재하면? 그 다음 턴에는 자연스럽게 상근이가 이긴다.
# 따라서 dp[i]는 dp[i-1], dp[i-3], dp[i-4] 중 단 하나라도 0인 경우가 있다면 1이고 아니면 0이다.

for i in range(5, N+1):
    if dp[i-1] == 0 or dp[i-3] == 0 or dp[i-4] == 0:
        dp[i] = 1
    else:
        dp[i] = 0

if dp[N] == 0:
    print("CY")
else:
    print("SK")


```