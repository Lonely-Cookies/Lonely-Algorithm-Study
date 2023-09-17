```python
import sys
# min max 알고리즘의 대표 예시
# 내 턴에는 최선의 선택지를, 상대 턴에는 최악의 선택지를 고르도록 하는 것이 포인트.

def solution(arr, dp_table, turn, left, right):
    if left > right:
        return 0
    else:
        if dp[left][right] != -1:
            return dp[left][right]
        else:
            if turn%2 == 1:
                dp[left][right] = max(arr[left] + solution(arr, dp_table, turn+1, left+1, right), arr[right] + solution(arr, dp_table, turn+1, left, right-1))
            else:
                dp[left][right] = min(solution(arr, dp_table, turn + 1, left + 1, right), solution(arr, dp_table, turn + 1, left, right - 1))
            return dp[left][right]


T = int(sys.stdin.readline())
for i in range(T):
    N = int(sys.stdin.readline())
    test_case = list(map(int, sys.stdin.readline().split()))
    dp = [[-1 for _ in range(N)] for _ in range(N)]

    # print(dp)
    solution(test_case, dp, 1, 0, N-1)
    # print(dp)
    print(dp[0][N-1])


```
