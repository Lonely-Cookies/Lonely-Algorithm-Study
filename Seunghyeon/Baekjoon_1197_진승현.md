## 문제 요약

**최소 스패닝 트리 ( 골드 4 )**
1. 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리 구하기

2. 최소 스패닝 트리
- 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중 가중치의 합이 최소인 트리

## 입력
1. 정점의 개수 V, 간선의 개수 E

2. E 개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A B C
- A 번 정점과 B 번 정점이 가중치 C 인 간선으로 연결되어 있음
- C 는 음수일 수 있으며, 절댓값 1000000 을 넘지않음


## 출력
1. 최소 스패닝 트리의 가중치 출력하기

## 풀이
1. 최소 스패닝 트리
- 주어진 모든 간선 정보에 대해 간선 비용이 낮은 순서로 정렬 수행
- 사이클 발생여부 체크
- 사이클이 발생하지 않은 경우, 최소 신장 트리에 포함
- 발생한 경우엔 포함 X

## 코드

### 최소 스패닝 트리 ( 정답 ) : 시간 324ms

```python
import sys

def find(parent, x):
    # 루트를 찾았을 경우 ( 원소값이 자기 자신 )
    if parent[x] == x:
        return x
    parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    rootA = find(parent, a)
    rootB = find(parent, b)

    if rootA < rootB:
        parent[rootB] = rootA
    else:
        parent[rootA] = rootB

input = sys.stdin.readline

v, e = map(int, input().split())
# 노드의 갯수
parent = [0] * (v+1)

edges = []
res = 0
# 노드 설정
for i in range(1, v+1):
    parent[i] = i

# 간선 정보 입력받기
for _ in range(e):
    a, b, cost = map(int, input().split())

    edges.append((cost, a, b))
# 가중치 기준 정렬
edges.sort()

for edge in edges:
    cost, a, b = edge

    # 사이클이 발생하지 않을 경우 최소 스패닝 트리에 포함
    if find(parent, a) != find(parent, b):
        union(parent, a, b)
        res += cost

print(res)
```