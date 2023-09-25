## 문제 요약

**임스와 함께하는 미니게임**
1. 윷놀이 Y, 같은 그림 찾기 F, 원카드 O
- 2, 3, 4 명이서 플레이하는 게임
- 인원수가 부족하면 게임을 시작할 수 없음

3. 임스와 같이 플레이하기를 신청한 횟수 N, 임스가 플레이할 게임의 종류
- 최대 몇 번이나 임스와 함께 게임을 플레이할 수 있는지 구하기

4. 한번 플레이한 사람과는 다시 플레이하지 않음
- 동명이인은 없음



## 입력
1. 플레이 신청 횟수 N, 플레이할 게임의 종류

2. 플레이하고자 하는 사람들의 이름이 문자열로 주어짐
- 숫자, 영문 대소문자로 구성

## 출력
1. 최대 몇번이나 게임을 플레이할 수 있는지 구하기

## 코드

### ( 정답 ) : 시간 88ms

```python
import sys

input = sys.stdin.readline

n,m = input().strip().split()

n_set = set()

for i in range(int(n)):
    n_set.add(input().strip())

if m == 'Y':
    print(len(n_set))
elif m == 'F':
    print(len(n_set) // 2)
elif m == 'O':
    print(len(n_set) // 3)
```