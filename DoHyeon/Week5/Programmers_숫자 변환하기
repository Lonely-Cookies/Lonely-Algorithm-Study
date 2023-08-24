```python
# 동적계획법을 이용한 문제인데 오늘 머리가 안돌아간다
# 특정 y에 도달할 때 필요한 최소 연산 횟수를 저장하는 방식으로 풀었다.
# 겨우 2레벨인데 꽤 고민했다.
def solution(x, y, n):
    dp = [0] * (y+1)
    for i in range(x, y+1):
        if x != i and dp[i] == 0:
            dp[i] = -1
            continue
        if i * 3 <= y:
            dp[i*3] = dp[i] + 1 if dp[i*3] == 0 else min(dp[i] + 1, dp[i*3])
        if i * 2 <= y:
            dp[i*2] = dp[i] + 1 if dp[i*2] == 0 else min(dp[i] + 1, dp[i*2])
        if i + n <= y:
            dp[i+n] = dp[i] + 1 if dp[i+n] == 0 else min(dp[i] + 1, dp[i+n])
    answer = dp[y] 
    return answer
```
