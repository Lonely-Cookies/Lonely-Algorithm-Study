```python
import sys
from heapq import *
# 프림의 알고리즘 최소 힙 사용 버전

N = int(sys.stdin.readline())

adj_list = [[]for _ in range(N+1)]

M = int(sys.stdin.readline())

vertex_list = list()

for _ in range(M):
    s, e, w = map(int, sys.stdin.readline().split())

    adj_list[s].append((w, e))
    adj_list[e].append((w, s))

S = set()
total = 0

heap = [(0, 1)]

while heap:
    weight, node = heappop(heap)

    if node not in S:
        total += weight
        S.add(node)

        for w, n in adj_list[node]:
            heappush(heap, (w, n))

print(total)






```
