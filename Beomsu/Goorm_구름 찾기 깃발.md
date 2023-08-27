## 구름 찾기 깃발
![|500](https://i.imgur.com/U25wmmw.png)


```python
N,K = map(int,input().split())

mp = [list(map(int,input().split())) for _ in range(N)]

m = [[0 for _ in range(N)] for _ in range(N)]

def check(x, y):
	global m
	for i in range(x-1,x+2,1):
		for j in range(y-1,y+2,1):
			if i<0 or j<0 or i==N or j==N:
				continue	
			if mp[i][j]==1:
				continue
			m[i][j]+=1
			
			
for i in range(N):
	for j in range(N):
		if mp[i][j]==1:
			check(i,j)
answer= 0
for i in range(N):
	for j in range(N):
		if m[i][j]==K:
			answer+=1

print(answer)
```

시간 초과 뜰 줄 알았는데 다행이 통과 했다. 구현 로직 자체는 간단하다
![|500](https://i.imgur.com/JA8IgQm.png)
문제도 위의 그림과 

내가 생각 한건,깃발을 저장한 지도와 별개로 하나의 맵을 만들어서 체크를 하는거다
구름 주위로 구름이 아니며, 맵 안에 있는 8방면에 대해서 1씩 더한다

최종적으로 K와 동일한 블록을 찾으면 끝!
