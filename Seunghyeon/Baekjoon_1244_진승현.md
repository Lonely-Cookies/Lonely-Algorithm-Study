## 문제 요약

**스위치 켜고 끄기**
1. 스위치 : 켜져있거나 ( 1 ), 꺼져있거나 ( 0 )

2. 학생 몇 명을 뽑아서, 학생들에게 1 ~ 스위치 개수 이하 자연수를 하나씩 나누어주었음

3. 남학생 : 스위치 번호가 자기가 받은 수의 배수
-> 그 스위치 상태를 바꿈

- 여학생 : 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간을 찾아서, 그 구간에 속한 스위치의 상태를 모두 바꿈
- 이때 구간에 속한 스위치 개수는 항상 홀수
- 조건에 맞지 않으면 패스

## 입력
1. 스위치 개수 ( <= 100 )

2. 각 스위치의 상태
- 켜져있으면 1, 꺼져있으면 0

3. 학생 수

4. 학생의 성별, 학생이 받은 수
- 남학생 : 1, 여학생 : 2


## 출력
1. 스위치 상태 출력 ( 한 줄에 20개씩 )
- 켜진 스위치 : 1, 꺼진 스위치 : 0
- 스위치 상태 사이에 빈칸 두기

## 코드

### ( 정답 ) : 시간 44ms

```python
import sys

input = sys.stdin.readline

sw = int(input())

switches = list(map(int, input().split()))

po = int(input())
people_list = [list(map(int, input().split())) for _ in range(po)]

for i in people_list:
    # x : 성별, y : 스위치 번호
    x, y = i

    # 남자일 때
    if x == 1:
        for jump in range(y-1, sw, y):
            if switches[jump] == 1:
                switches[jump] = 0
            else:
                switches[jump] = 1
    # 여자일 때
    elif x == 2:
        # index 맞추기
        y -= 1

        # 현 위치 바꾸기
        if switches[y] == 1:
            switches[y] = 0
        else:
            switches[y] = 1

        # 좌우 비교하기
        y1, y2 = y-1, y+1

        while y1 >= 0 and y2 < sw:
            if switches[y1] == switches[y2]:
                if switches[y1] == 1:
                    switches[y1], switches[y2] = 0, 0
                else:
                    switches[y1], switches[y2] = 1, 1
            else:
                break
            y1 -= 1
            y2 += 1

cnt = 0

for i in range(sw):
    print(switches[i], end=' ')

    # 띄어쓰기 할 갯수
    cnt += 1

    if cnt == 20:
        cnt = 0
        print()
```