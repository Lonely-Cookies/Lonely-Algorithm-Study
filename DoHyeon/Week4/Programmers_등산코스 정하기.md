```python
from queue import PriorityQueue
from collections import defaultdict
# 말이 어렵지 가중치 그래프에서 최대 가중치를 가진 edge가
# 최소가 되는 경로를 찾아라 이말아닌가
# 말만 어려운게 아니라 진짜 어려웠다 결국 답을 보고야말았다
# 도저히 시간 안에 해결이 안돼서 해당 답을 참고하였다.
# https://hz25.tistory.com/6

inf = 999999999

def solution(n, paths, gates, summits):
    adj_list = defaultdict(list) # 이걸 쓴다고 과연 속도가 빨라질까?

    for i, j, w in paths:
        adj_list[i].append((j, w))
        adj_list[j].append((i, w))
    answer = []
    min_val = inf
    min_summit = 0

    distance = dijkstra(gates, n, adj_list, summits)
    for summit in summits:
        if min_val > distance[summit]:
            min_val = distance[summit]
            min_summit = summit
        elif min_val == distance[summit]:
            if min_summit > summit:
                min_summit = summit
    answer.append(min_summit)
    answer.append(min_val)
    return answer

# 다익스트라 알고리즘의 비교 기준을 수정
def dijkstra(gates, n, adj_list, summits):
    distance = [inf] * (n+1)
    pq = PriorityQueue()
    for gate in gates:
        distance[gate] = 0 
        pq.put((0, gate))

    while not pq.empty():
        dis, curr = pq.get()
        if  dis > distance[curr] or curr in summits:
            continue
        for v, weight in adj_list[curr]:
            new_dis = max(weight, dis)
            if new_dis < distance[v]:
                distance[v] = new_dis
                pq.put((distance[v], v))
                
    return distance
        
    
```
