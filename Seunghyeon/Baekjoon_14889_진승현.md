## 문제 요약

**스타트와 링크 ( 실버 2 )**

1. 축구 : 평일 오후, 의무 참석 x

2. 축구를 하기 위해 모인 사람 : n 명 ( n은 짝수 )
- n / 2 명으로 이루어진 스타트 팀과 링크 팀

3. 1 ~ n 까지 번호 부여, 능력치 조사
- 능력치 S : i번 사람과 j 번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치
- 팀의 능력치 : 팀에 속한 모든 쌍의 능력치 Sij 의 합
- Sij 와 Sji 는 다를 수 있음
- i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치 : Sij, Sji

4. 스타트 팀의 능력치와 리크 팀의 능력차 차이 최소화

## 입력
1. n
2. n 개의 줄의 s

## 출력
1. 스타트 팀과 링크 팀의 능력치 차이의 최솟값 출력하기

## 풀이
1. 123 나머지 / 124 나머지 ... 이렇게 계속 팀을 나눠서 계산해야함
2. 백트래킹 활용해서 팀 나누기
3. 각 팀 능력치 계산
4. 팀 능력치의 차이를 리스트에 저장

## 코드

### 실패 : 시간초과

```python
import sys

def back():
    if len(start_team) == n / 2:
        # 스타트팀에 인원수를 다 넣었을 때
        link_team = []
        for i in range(1, n+1):
            # 스타트팀에 넣은 인원일 경우
            if visited[i]:
                continue
            link_team.append(i)

        # 만들어둔 맵의 가중치를 더하는 작업
        start_num = 0
        link_num = 0
        # 지점 설정
        t = n // 2

        # 스타트팀 값 더하기
        for y in range(t):
            for x in range(y+1, t):
                # 스타트 팀
                start_i = start_team[y] - 1
                start_j = start_team[x] - 1

                start_num += (board[start_i][start_j] + board[start_j][start_i] )

                # 링크 팀
                link_i = link_team[y] - 1
                link_j = link_team[x] - 1

                link_num += ( board[link_i][link_j] + board[link_j][link_i] )

        return ans_list.append(abs(start_num-link_num))

    for i in range(1, n+1):
        # 아직 방문하지 않았을 경우
        if not visited[i]:
            start_team.append(i)
            # 방문 처리
            visited[i] = True
            back()
            start_team.pop()
            # 방문 해제
            visited[i] = False



input = sys.stdin.readline

n = int(input())
# 맵 만들기
board = []

for _ in range(n):
    board.append(list(map(int, input().split())))

visited = [False] * (n+1)

# 팀 나누기
start_team = []
link_team = []

ans_list = []

back()

print(min(ans_list))
```

### 정답 : 시간 1460ms

```python
import sys
def back(cnt, idx):
    global min_num
    # 스타트팀에 인원수를 다 넣었을 때
    if cnt == n // 2:
        # 만들어둔 맵의 가중치를 더하는 작업
        start_num = 0
        link_num = 0

        # 팀 값 더하기
        for y in range(n):
            for x in range(n):
                if visited[y] and visited[x]:
                    start_num += board[y][x]
                elif not visited[y] and not visited[x]:
                    link_num += board[y][x]
        min_num = min(min_num, abs(start_num - link_num))
        return

    for i in range(idx, n):
        # 아직 방문하지 않았을 경우
        if not visited[i]:
            if cnt <= n // 2:
                # 방문 처리
                visited[i] = True
                back(cnt + 1, i + 1)
                # 방문 해제
                visited[i] = False

input = sys.stdin.readline

n = int(input())
# 맵 만들기
board = []

for _ in range(n):
    board.append(list(map(int, input().split())))

# 방문처리
visited = [False] * n

# 최솟값 설정
min_num = int(1e9)

back(0, 0)

print(min_num)
```
