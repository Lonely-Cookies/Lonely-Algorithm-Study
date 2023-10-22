```python
import sys

# 크루스칼 알고리즘

N = int(sys.stdin.readline())

M = int(sys.stdin.readline())


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x]) # 최종적으로 가장 상위에 있는 조상을 찾음.
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    # 더 노드 번호가 작은 쪽에 병합
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

result = 0
parent = [0]*(N+1)

for i in range(N+1):
    parent[i] = i

vertex = []
for _ in range(M):
    s, e, w = map(int, sys.stdin.readline().split())
    vertex.append((w, s, e))

vertex.sort()

for val in vertex:
    w, s, e = val
    if find_parent(parent, s) != find_parent(parent, e):
        union_parent(parent, s, e)
        result += w

print(result)

```
