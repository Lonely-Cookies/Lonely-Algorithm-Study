## 문제 요약

**게입 맵 최단거리 ( Lv.2 )**

1. map : n * m

2. 처음 위치 : (1,1)
3. 상대 위치 : (n,m)

4. 검정 : 벽 (0)
5. 흰색 : 길 (1)

6. 이동 : 동,서,남,북


## 입력
1. maps

## 출력
1. 가장 빨리 상대 팀 진역으로 가는 방법 찾기
2. 도착할 수 없을 경우, -1 리턴하기

## 코드

### 내가 푼 코드 ( 정답 )

```python
from collections import deque
    
def solution(maps):
    # n, m
    n = len(maps[0])
    m = len(maps)
    
    # 갈 수 있는 경우
    queue = deque()
    
    queue.append((0,0))
    
    while queue:
        x,y = queue.popleft()
        
        for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
            nx = x + dx
            ny = y + dy
            
            if 0 <= nx < n and 0 <= ny < m:
                if maps[ny][nx] == 1:
                    queue.append((nx,ny))
                    maps[ny][nx] = maps[y][x] + 1
    
    if maps[m-1][n-1] == 1:
        return -1
    else:
        return maps[m-1][n-1]          

```
