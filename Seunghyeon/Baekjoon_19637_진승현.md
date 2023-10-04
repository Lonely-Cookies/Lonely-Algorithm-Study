## 문제 요약

**if문좀 대신 써줘**
1. 캐릭터의 전투력에 맞는 칭호를 출력하는 프로그램 작성하기


## 입력
1. 칭호의 개수 N, 캐릭터들의 개수 M

2. N 개의 줄에 각 칭호의 이름을 나타내닌 길이, 전투력 상한값
- 전투력 상한값은 비내림차순으로 주어짐

3. M 개의 줄에는 캐릭터의 전투력을 나타내는 음이 아닌 정수가 주어짐


## 출력
1. M 개의 줄에 걸쳐 캐릭터의 전투력에 맞는 칭호를 입력 순서대로 출력하기
- 칭호가 여러 개 일 경우, 가장 먼저 입력된 칭호 하나만 출력

## 풀이
1. 이분탐색

## 코드

### ( 정답 ) : 시간 656ms

```python
import sys

input = sys.stdin.readline

n, m = map(int, input().split())

n_numList = []
n_strList = []
m_list = []
ans_list = []

for _ in range(n):
    s, num = input().split()
    # insert after type casting the variable
    n_numList.append(int(num))
    n_strList.append(s)

for _ in range(m):
    check_num = int(input())

    # index setting
    left, right = 0, n-1

    # string
    ans = ''

    while left <= right:
        mid = (left + right) // 2

        # check -> back
        if check_num <= n_numList[mid]:
            ans = n_strList[mid]
            right = mid - 1
        else:
            left = mid + 1

    ans_list.append(ans)

for i in ans_list:
    print(i)
```