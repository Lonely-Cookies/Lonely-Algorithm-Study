## 문제 요약

**여행 가자**
1. n 개의 도시
- 임의의 두 도시 사이에 길이 있을수도, 없을수도 있음

2. 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 알아보기
- 중간에 다른 도시를 경유해서 여행할 수 있음

3. 도시들의 개수와 도시들 간의 연결 여부가 주어져 있음
- 여행 계획에 속한 도시들이 순서대로 주어졌을 때 가능한지 여부 판단
- 같은 도시를 여러 번 방문하는 것도 가능함


## 입력
1. 도시의 수 n ( <= 200 )

2. 여행 계획에 속한 도시들의 수 m

3. n 개의 정수
- i 번째 줄의 j번째 수 : i번 도시와 j번 도시의 연결 정보를 의미함
- 1 : 연결, 0 : 연결 x
- A 와 B 연결 -> B 와 A 도 연결 O

4. 마지막 줄 : 여행 계획이 주어짐

5. 도시의 번호 : 1 ~ N

## 출력
1. 가능하면 YES, 불가능하면 NO 출력하기

## 풀이
1. Union - Find

## 코드

### ( 정답 ) : 시간 52ms

```python
import sys

def find(node):
    if parents[node] != node:
        parents[node] = find(parents[node])
    return parents[node]

def union(nodeA, nodeB):
    nodeA = find(nodeA)
    nodeB = find(nodeB)

    if nodeA < nodeB:
        parents[nodeB] = nodeA
    else:
        parents[nodeA] = nodeB

input = sys.stdin.readline

# 도시의 수
n = int(input())
# 여행 계획에 속한 도시들의 수
m = int(input())
# node
parents = [i for i in range(n+1)]

for i in range(1, n+1):
    links = list(map(int, input().split()))

    cnt = i

    for j in range(1, n+1):
        if links[j-1] == 0: # 연결 X
            continue
        else: # 연결 O
            union(cnt, j)


checkLinks = list(map(int, input().split()))

ans_set = set()

for link in checkLinks:
    ans_set.add(find(link))

if len(ans_set) == 1:
    print('YES')
else:
    print('NO')
```