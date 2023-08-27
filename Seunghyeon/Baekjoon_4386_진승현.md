## 문제 요약

**별자리 만들기 ( 골드 3 )**
1. n 개의 별들을 이어서 별자리 만들기
- 별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태
- 모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 함

2. 선을 하나 이을 때 마다 두 별 사이의 거리만큼의 비용이 들어감

3. 별자리를 만드는 최소 비용 구하기

## 입력
1. 별의 개수 n

2. 둘째줄부터 n개의 줄에 걸쳐 (x,y) 좌표가 주어짐 ( 실수 )

3. 최대 소수점 둘째자리까지 주어짐

4. 좌표는 1000을 넘지 않는 양의 실수


## 출력
1. 정답 출력
- 절대/상대 오차는 10^-2 까지 허용

## 풀이
1. 크루스칼 알고리즘 활용
- 가중치 값으로 정렬을 어떻게 할 것인지?
- 일단 다 구해보기

## 코드

### 크루스칼 ( 정답 ) : 시간 52ms

```python
import sys
def find(parent, x):
    # 루트노드 일 경우
    if parent[x] == x:
        return x
    parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, nodeA, nodeB):
    if nodeA < nodeB:
        parent[nodeB] = nodeA
    else:
        parent[nodeA] = nodeB


input = sys.stdin.readline

n = int(input())
xy_list = []

for _ in range(n):
    x, y = map(float, input().split())

    xy_list.append((x,y))

# 그래프
parent = [i for i in range(n+1)]

# 거리의 비용을 저장하는 리스트
di_list = []
# 마지막은 안해도 됨
for i in range(n-1):
    x1, y1 = xy_list[i]
    for j in range(i+1, n):
        x2, y2 = xy_list[j]

        cost = pow((x2 - x1) ** 2 + (y2 - y1) ** 2, 0.5)
        di_list.append((cost, i, j))
# 정렬
di_list.sort()
res = 0
for edge in di_list:
    cost, a, b = edge

    nodeA = find(parent, a)
    nodeB = find(parent, b)

    if nodeA != nodeB:
        union(parent, nodeA, nodeB)
        res += cost
        
print(round(res, 2))
```
