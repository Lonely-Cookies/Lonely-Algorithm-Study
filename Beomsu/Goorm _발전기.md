## 문제
![|600](https://i.imgur.com/1PfQ1la.png)


## 풀이
```Python
from collections import deque

# Python 코드로 문제 해결 알고리즘 구현 (BFS 사용)
def min_generators(n, grid):
    # 발전기 개수 초기화
    generator_count = 0

    # 전력 공급 상태를 저장할 리스트 초기화
    supplied = [[False for _ in range(n)] for _ in range(n)]

    # BFS를 위한 방향 벡터
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    # 모든 칸을 순회
    for i in range(n):
        for j in range(n):
            # 집이 있는 칸을 찾음
            if grid[i][j] == 1 and not supplied[i][j]:
                # 전력이 공급되지 않은 집에 발전기 설치
                generator_count += 1

                # BFS 시작
                queue = deque([(i, j)])
                while queue:
                    x, y = queue.popleft()
                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < n and 0 <= ny < n and not supplied[nx][ny]:
                            supplied[nx][ny] = True
                            if grid[nx][ny] == 1:
                                queue.append((nx, ny))

    return generator_count

# 동적 입력 받기
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# 결과 출력
print(min_generators(n, grid))
```
