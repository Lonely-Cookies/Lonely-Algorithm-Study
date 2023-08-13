import sys
from collections import deque


n,m = map(int,sys.stdin.readline().split())

paper = [list(map(int,sys.stdin.readline().split())) for i in range(n)]
result = [[-1 for i in range(m)] for i in range(n) ]

dx, dy = [0,0,-1,1], [-1,1,0,0]



def bfs(i,j):
    global dx
    global dy
    queue = deque()
    queue.append((i,j))

    result[i][j] = 0

    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx,ny = dx[i] + x,dy[i]+y
            if 0<=nx<n and 0<=ny <m and result[nx][ny]==-1:
                if paper[nx][ny]==0:
                    result[nx][ny]=0
                elif paper[nx][ny]==1:
                    result[nx][ny] = result[x][y]+1
                    queue.append((nx,ny))

for i in range(n):
    for j in range(m):
        if paper[i][j] == 2 and result[i][j] == -1:
            bfs(i,j)


for i in range(n):
    for j in range(m):
        if paper[i][j] == 0:
            print(0, end=' ')
        else:
            print(result[i][j], end=' ')
    print()