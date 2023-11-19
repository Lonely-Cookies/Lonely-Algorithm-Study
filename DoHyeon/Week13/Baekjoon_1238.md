```python

import sys
from heapq import *
# 다익스트라 알고리즘 최소 힙 사용 버전

INF = 999999999
N, M, X = map(int, sys.stdin.readline().split())

adj_list = [[]for _ in range(N+1)]

for _ in range(M):
    s, e, w = map(int, sys.stdin.readline().split())

    adj_list[s].append((w, e))


def dijkstra(adj_list, start):
    heap = []

    distance = [INF for _ in range(N+1)]

    heappush(heap, (0, start))

    distance[0] = 0
    distance[start] = 0
    while heap:
        weight, now = heappop(heap)

        if distance[now] < weight:
            continue

        for adj in adj_list[now]:
            cost = weight + adj[0]
            # adj[0] 은 그래프 가중치, adj[1]은 노드
            if cost < distance[adj[1]]:
                distance[adj[1]] = cost
                heappush(heap, (cost, adj[1]))
    return distance


distance_list = [[] for _ in range(N+1)]
for i in range(1, N+1):
    distance_list[i] = dijkstra(adj_list, i)

distance_sum = distance_list[X].copy()

for i in range(1, N+1):
    distance_sum[i] += distance_list[i][X]

print(max(distance_sum))


```
