
```python
# 길이 n-1개 존재한다..? 트리?
# 리프노드가 존재하는 부모노드라면? 자식들이 켜져있을 경우 -> 부모는 키지 않아도 된다.
# 자식들이 꺼져있다면 부모노드는 반드시 켜져야 한다.
# 부모가 켜져있다면 자식노드들은 켜져있든 말던 상관 없다.
# 따라서 on, off로 본인이 켜져있을 경우 최소 점등 등대 개수와
# 꺼져있을 경우 최소 점등 등대 개수 이 두가지를 반환하도록 한다.
# 런타임 에러 때문에 화가 잔뜩 났는데 setrecursionlimit를 설정해주면 된다고 한다.
# 단방향 트리로 풀다가 해결이 되지 않아 양방향트리로 풀었더니 된다...?
import sys
sys.setrecursionlimit(10**6)


def solution(n, lighthouse):
    tree_list = [[] for _ in range(n+1)] # index가 1부터 시작하므로 n+1을 해준다
    
    for u, v in lighthouse:
        tree_list[u].append(v)
        tree_list[v].append(u)
    
    visit = [False for _ in range(n+1)]
    
    on, off = dfs(tree_list,visit,1) # 1번 노드를 루트노드라고 생각하고 시작
    answer = min(on, off)
    return answer


def dfs(tree_list, visit, a):
    visit[a] = True
    on = 1
    off = 0
    
    n_child = [ i for i in tree_list[a] if not visit[i]] # 현재 노드에서 방문해야 할 노드들의 리스트
    
    for v in n_child:
        child_on, child_off = dfs(tree_list, visit, v)
        
        # 현재 등대가 켜져있을 경우는 자식들이 켜져있을 경우, 꺼져있을 경우 중 가장 작은 값을 취한다.
        on += min(child_on, child_off)
        # 현재 등대가 켜져있다면 자식들이 켜져있을 경우만 취한다.
        off += child_on
        
    return on, off
```

        
        
