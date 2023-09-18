## 문제 요약

**ABCDE ( 골드 5 )**
1. N명의 사람들 ( 번호가 매겨짐 )
2. 친구 관계를 가진 사람이 존재하는지 구하는 프로그램 작성하기



## 입력
1. 사람의 수 N, 친구 관계의 수 M
2. M개의 줄에는 정수 a,b 가 주어짐
- a 와 b 는 친구
3. 같은 친구 관계가 두번 이상 주어지는 경우는 없음


## 출력
1. 문제의 조건에 맞는 A,B,C,D,E 가 존재하면 1, 없으면 0 출력

## 풀이
1. Graph
- 차례대로 위로 올라갔을 때 ( 반복했을 때 )
- 끊어지지 않고 5번 출력되면 1 출력
- 아니면 0 출력

## 코드

### ( 정답 ) : 시간 704ms

```python
import sys
def dfs(start ,cnt):
    if cnt == 4:
        print(1)
        exit(0)

    visited[start] = True

    for i in graph[start]:
        # 아직 방문하지 않은 노드일 경우
        if not visited[i]:
            # 방문처리
            dfs(i, cnt + 1)
    visited[start] = False


input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a+1].append(b+1)
    graph[b+1].append(a+1)

visited = [False] * (n+1)

for i in range(1, n+1):
    dfs(i, 0)

print(0)
```