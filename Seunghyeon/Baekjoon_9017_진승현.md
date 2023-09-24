## 문제 요약

**크로스 컨트리**
1. 한 팀 - 여섯 명의 선수로 구성
- 팀 점수 : 상위 4명의 주자의 점수를 합해서 계산
- 점수는 자격을 갖춘 팀의 주자들에게만 주어짐
- 결승점을 통과한 순서대로 점수를 받음

2. 이 점수를 더하여 가장 낮은 점수를 얻는 팀이 우승함
- 여섯 명의 주자가 참가하지 못한 팀 : 점수 계산에서 제외
- 동점의 경우, 다섯번째 주자가 가장 빨리 들어온 팀이 우승함

3. 모든 선수들의 등수가 주어질 때, 우승팀을 구하는 프로그램 작성
- 각 팀의 참가 선수 < 6 : 점수 계산에서 제외됨
- 여섯 명 보다 많은 선수가 참가 X
- 적어도 한 팀은 참가 선수가 6
- 모든 선수는 끝까지 완주를 한다고 가정

## 입력
1. t개의 테스트 케이스

2. 두번째줄부터 하나의 테스트케이스에 해당하는 데이터가 주어짐

3. 팀 번호를 나타내는 n 개의 정수
- 각 팀은 1과 m 사이의 정수로 표현됨

## 출력
1. 하나의 테스트 케이스에 대한 우승팀의 번호를 한 줄에 출력

## 코드

### ( 정답 ) : 시간 52ms

```python
import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    n_list = list(map(int, input().split()))

    n_dict = dict()

    for i in n_list:
        if i not in n_dict:
            n_dict[i] = 1
        else:
            n_dict[i] += 1

    # 6 미만 인 팀
    n_checkTeam = []
    for k, v in n_dict.items():
        if v < 6:
            n_checkTeam.append(k)

    cnt = 1

    n_team = [0 for i in range(len(n_dict)+1)]
    n_teamCheckNum = [0 for i in range(len(n_dict)+1)]
    n_teamCheckFirst = [0 for i in range(len(n_dict)+1)]

    for i in range(n):
        n_teamCheckNum[n_list[i]] += 1

        # 처음으로 팀의 5번째 주자가 통과했을 떄 ( 동점 주자 체크 )
        if n_teamCheckNum[n_list[i]] == 5:
            n_teamCheckFirst[n_list[i]] = cnt

        if n_list[i] in n_checkTeam:
            continue

        if n_teamCheckNum[n_list[i]] > 4:
            cnt += 1
            continue

        n_team[n_list[i]] += cnt
        cnt += 1

    # 정답 인덱스, 숫자
    ansIndex, ansNum = 0, 1000000000

    for i in range(1, len(n_dict)+1):
        if n_team[i] == 0:
            continue

        if n_team[i] < ansNum:
            ansNum = n_team[i]
            ansIndex = i
        # 5번째 주자 비교
        if n_team[i] == ansNum:
            if n_teamCheckFirst[i] < n_teamCheckFirst[ansIndex]:
                ansIndex = i

    print(ansIndex)
```