## 문제 요약

**도시 분할 계획 ( 골드 4 )**
1. 마을 : n개의 집과 그 집들을 연결하는 m개의 길
- 그래프 문제
- 길은 어느 방향으로든지 다닐 수 있는 편리한 길
- 각 길마다 길을 유지하는데 드는 유지비가 있음 ( 비용 )
- 임의의 두 집사이에 경로가 항상 존재 ( 연결되어있음 )

2. 마을을 두 개의 분리된 마을로 분할할 계획을 가지고 있음
- 마을을 분할할 때는 각 분리된 마을 안에 집들이 서로 연결되도록 분할해야 함
- 마을에는 집이 하나 이상 있어야 함

3. 길이 너무 많으니, 길을 줄여야 함
- 분리된 두 마을 사이에 있는 길들은 필요가 없음
- 각 분리된 마을 안에서도 임의의 두 집 사이에 경로가 항상 존재하게 하면서 길을 더 없앨 수 있음

4. 위 조건들을 만족하면서 나머지 길의 유지비의 합을 최소로 하는 프로그램 작성하기


## 입력
1. 집의 개수 n, 길의 개수 m
2. m 줄에 걸쳐 길의 정보가 a,b,c 로 주어짐
- a,b : 서로 연결할 집
- c : 유지비



## 출력
1. 남은 길 유지비의 합의 최솟값 출력하기


## 풀이
1. 최소 신장 트리 활용 ( 크루스칼 알고리즘 )
- 가중치 순으로 정렬
- 연결해보고, 사이클이 발생하는지 체크하기
2. 마지막 비용 빼버리기

## 코드

### 최소 스패닝 트리 ( 정답 ) : 시간 3824ms

```python
import sys
def find(parent, x):
    # 자기자신일 때 ( 루트 노드일 때 )
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

n, m = map(int, input().split())
# 노드
parent = [0] * (n+1)
# 번호
for i in range(1, n+1):
    parent[i] = i
# 간선
edges = []

for _ in range(m):
    a,b,cost = map(int, input().split())

    edges.append((cost, a, b))

# 비용을 기준으로 정렬
edges.sort()

# 총 비용
ans = 0
# 마지막 비용 기억하기
lastNum = 0
for edge in edges:
    cost, a, b = edge

    if find(parent, a) != find(parent, b):
        union(parent, a, b)
        ans += cost
        lastNum = cost

print(ans - lastNum)
```

### 더 빠른 코드 ( 최적화 ) : 시간 3340 ms
```python
import sys
def find(parent, x):
    # 자기자신일 때 ( 루트 노드일 때 )
    if parent[x] == x:
        return x
    parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, rootA, rootB):
    if rootA < rootB:
        parent[rootB] = rootA
    else:
        parent[rootA] = rootB

input = sys.stdin.readline

n, m = map(int, input().split())
# 노드
parent = [0] * (n+1)
# 번호
for i in range(1, n+1):
    parent[i] = i
# 간선
edges = []

for _ in range(m):
    a,b,cost = map(int, input().split())

    edges.append((cost, a, b))

# 비용을 기준으로 정렬
edges.sort()

# 총 비용
ans = 0
# 마지막 비용 기억하기
lastNum = 0
# 연결 횟수 체크
cnt = 0
for edge in edges:
    cost, a, b = edge

    rootA = find(parent, a)
    rootB = find(parent, b)
    # 루트노드가 같을 경우 그래프가 사이클이 발생함
    if rootA == rootB:
        continue

    union(parent, rootA, rootB)
    ans += cost
    lastNum = cost
    cnt += 1

    if cnt == (n-1):
        break


print(ans - lastNum)

```

1. 함수 호출 최소화
2. 반복문 호출 최소화