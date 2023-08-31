```python
# dp 문제는 풀 때마다 느끼는 거지만 너무 어렵다...
# 틀에 정해진 방법이 없기 때문에 더욱 어렵다고 느끼는 것 같다.
import sys

N = int(sys.stdin.readline())
W = int(sys.stdin.readline())

points = [(-1,-1)]
# dp[i][j] 경찰차 1이 i번째 점에, 경찰차 2가 j번째 점에 이동했을 경우의 최소 거리
dp = [[-1 for _ in range(W+1)] for _ in range(W+1)]


for _ in range(W):
    x, y = map(int, sys.stdin.readline().split())
    points.append((x, y))
def cal_distance(point_1, point_2):
    return abs(point_1[0] - point_2[0]) + abs(point_1[1] - point_2[1])


def calc_dp(i, j):
    if i == W or j == W:
        return 0
    if dp[i][j] != -1:
        return dp[i][j]

    dist_1 = 0
    dist_2 = 0
    next_point = max(i, j) + 1
    # 다음으로 방문해야 할 점은 이전 경찰차가 간 번호 둘 중 더 큰 번호 + 1이다.

    if i == 0:
        dist_1 = cal_distance((1, 1), points[next_point])
    else:
        dist_1 = cal_distance(points[i], points[next_point])

    if j == 0:
        dist_2 = cal_distance((N, N), points[next_point])
    else:
        dist_2 = cal_distance(points[j], points[next_point])

    dp[i][j] = min(calc_dp(next_point, j) + dist_1, calc_dp(i, next_point) + dist_2)
    return dp[i][j]


def print_answer(i, j):
    if i == W or j == W:
        return

    dist_1 = 0
    dist_2 = 0
    next_point = max(i, j) + 1

    if i == 0:
        dist_1 = cal_distance((1, 1), points[next_point])
    else:
        dist_1 = cal_distance(points[i], points[next_point])

    if j == 0:
        dist_2 = cal_distance((N, N), points[next_point])
    else:
        dist_2 = cal_distance(points[j], points[next_point])

    if dp[next_point][j] + dist_1 < dp[i][next_point] + dist_2:
        print(1)
        print_answer(next_point, j)
    else:
        print(2)
        print_answer(i, next_point)


answer = calc_dp(0, 0)
print(answer)
print_answer(0, 0)

```
