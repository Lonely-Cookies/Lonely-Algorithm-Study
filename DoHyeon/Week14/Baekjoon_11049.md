```python
import sys

N = int(sys.stdin.readline())

matrix_list = []

for _ in range(N):
    a, b = map(int, sys.stdin.readline().split())
    matrix_list.append((a, b))

dp = [([-1] * N) for _ in range(N)]

# dp = [[-1] * N] * N 하면 각 행들이 서로 같은 주소를 공유하게 된다;;;


def print_matrix(dp, N):
    for i in range(N):
        print(dp[i])


for i in range(N):
    dp[i][i] = 0

# i 는 문제의 크기
for i in range(1, N):
    for j in range(N-i):
        temp = -1
        for k in range(j, j+i):
            val = dp[j][k] + dp[k+1][j+i] + matrix_list[j][0]*matrix_list[k][1]*matrix_list[j+i][1]
            if temp == -1 or temp > val:
                temp = val
        dp[j][j+i] = temp


print(dp[0][N-1])


```
