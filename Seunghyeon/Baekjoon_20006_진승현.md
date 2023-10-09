## 문제 요약

**랭킹전 대기열**
1. 랭킹전 기능 추가
- 입장 신청시, 매칭이 가능한 방이 없다면 새로운 방을 생성, 입장 ( -10 ~ +10 )
- 입장 가능한 방이 있다면 입장시킨 후 방의 정원이 모두 찰 때 까지 대기
- 이때 입장 가능한 방이 여러 개라면 먼저 생성된 방에 입장
- 방의 정원이 모두 차면 게임을 시작함
2. 플레이어의 수 p, 플레이어의 닉네임 n, 플레이어의 레벨 l, 방 한개의 정원 m
3. 최종적으로 만들어진 방의 상태와 입장 플레이어들을 출력하는 프로그램 작성하기


## 입력

1. 플레이어의 수 p, 방의 정원 m
2. 레벨 l, 닉네임 n 이 공백을 두고 주어짐
3. 입력된 순서대로 게임을 시작함
- 닉네임 중복 X, 길이는 < 16

## 출력
1. 모든 생성된 방에 대해 게임의 시작 유무와 방에 들어있는 플레이어들의 레벨과 아이디를 출력함
2. 방은 생성된 순서대로 출력함
- 방에 있는 플레이어들의 정보는 닉네임이 사전순으로 앞서는 플레이어부터 출력함
- 방이 시작되었으면 Started!, 대기중이면 Waiting! 을 출력하기

## 코드

### ( 정답 ) : 시간 44ms

```python
import sys

input = sys.stdin.readline

# 플레이어의 수 p, 방의 정원 m
p, m = map(int, input().split())

# 방
rooms = []
# 플레이어의 수 만큼 반복
for i in range(p):
    # 방에 들어갔는지 체크
    check = False
    # 첫번째 플레이어
    l, n = input().split()
    if i == 0:
        rooms.append([(int(l), n)])
    else:
        # room 을 차례대로 돌면서 가장 첫번째 값과 비교하기
        for j in range(len(rooms)):
            # 아직 정원이 덜 찬경우
            if len(rooms[j]) < m:
                if rooms[j][0][0] - 10 <= int(l) <= rooms[j][0][0] + 10:
                    rooms[j].append((int(l), n))
                    check = True
                    break
            # 방을 다 돌았는데도 들어갈 수 있는 방이 없을 경우 새로운 방 만들기
            elif j == len(rooms)-1:
                rooms.append([(int(l), n)])
                check = True
                break
        # 들어갈 수 있는 방이 없는 경우 새로운 방 만들기
        if check == False:
            rooms.append([(int(l), n)])

for room in rooms:
    room.sort(key=lambda x : x[1])

    # 방이 다 찬 경우
    if len(room) == m:
        print("Started!")
        for r in room:
            print(*r)
    else:
        print("Waiting!")
        for r in room:
            print(*r)
```