
<img width="892" alt="image" src="https://github.com/latteisacat/Lonely-Algorithm-Study/assets/114455070/b1f0dccc-3dc5-4eda-bada-11ada791c2bb">
>- 실행 시간을 매우 많이 개선시켜서 중복문제이지만 올려봤습니다.

>- 방향성이 있는 그래프 내에서 다익스트라를 적용 시킬 때, 시작점과 끝점을 거꾸로 넣게 되면 역으로 해당 점에 도착할 때 드는 최단 비용을 구할 수 있다는 점을 이용했습니다.

```python
import sys
from heapq import *

INF = 999999999
N, M, X = map(int, sys.stdin.readline().split())

adj_list = [[]for _ in range(N+1)]
reverse_adj_list = [[]for _ in range(N+1)]
for _ in range(M):
    s, e, w = map(int, sys.stdin.readline().split())

    adj_list[s].append((w, e))
    reverse_adj_list[e].append((w, s))


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


distance_list = []
reverse_distance_list = []
distance_list = dijkstra(adj_list, X)
reverse_distance_list = dijkstra(reverse_adj_list, X)

distance_sum = []
for i in range(1, N+1):
    distance_sum.append(distance_list[i] + reverse_distance_list[i])

print(max(distance_sum))

```
