## 문제 요약

**집합의 표현**
1. 초기 n+1 개의 집합이 존재

2. 합집합 연산 + 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산 수행하기

3. 집합을 표현하는 프로그램 작성하기


## 입력

1. n, m
- m : 입력으로 주어지는 연산의 개수

2. 합집합 : 0 a b 의 형태로 입력이 주어짐
- a 가 포함되어 있는 집합과 b 가 포함되어 있는 집합을 합친다는 의미

3. 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산 : 1 a b
- a 와 b 가 같은 집합에 포함되어 있는지를 확인하는 연산

## 출력
1. 1로 시작하는 입력에 대해 a 와 b 가 같은 집합에 포함되어 있음 - YES
- 그렇지 않으면 NO

## 풀이
1. Union - Find

## 코드

### ( 정답 ) : 시간 336ms

```python
import sys

sys.setrecursionlimit(10**5)
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(node1, node2):
    if node1 < node2:
        parent[node2] = node1
    else:
        parent[node1] = node2

input = sys.stdin.readline

n, m = map(int, input().split())

# parent
parent = [i for i in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    # b, c 의 부모 찾기
    b = find(b)
    c = find(c)

    # a == 0 일 때, 합하기
    if a == 0:
        union(b, c)
    else:
        if b == c:
            print('YES')
        else:
            print('NO')
```