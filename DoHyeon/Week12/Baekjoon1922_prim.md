```python
import sys

N = int(sys.stdin.readline())

adj_matrix = [[0 for _ in range(N+1)]for _ in range(N+1)]

M = int(sys.stdin.readline())

adj_list = [set() for _ in range(N+1)]

for _ in range(M):
    s, e, w = map(int, sys.stdin.readline().split())
    adj_list[s].add(e)
    adj_list[e].add(s)

    adj_matrix[s][e] = w
    adj_matrix[e][s] = w

dist = [999999 for _ in range(N+1)]
S = set()
dist[1] = 0
S.add(1)

# for adj in adj_matrix[1:]:
#     print(adj[1:])

for i in range(2, N+1):
    if adj_matrix[1][i] != 0:
        dist[i] = adj_matrix[1][i]


for i in range(1, N+1):
    now = 0
    min_dist = 999999
    for j in range(2, N+1):
        if dist[j] < min_dist and j not in S:
            min_dist = dist[j]
            now = j
    S.add(now)

    for j in range(2, N+1):
        if adj_matrix[now][j] != 0 and j not in S:
            if dist[j] > adj_matrix[now][j]:
                dist[j] = adj_matrix[now][j]
print(sum(dist[1:]))
```


