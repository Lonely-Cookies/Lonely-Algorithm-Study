## 문제 요약

**가로수**
1. 가로수들이 모두 같은 간격이 되도록 가로수를 추가로 심는 작업을 추진하고 있음

2. 가능한 한 가장 적은 수의 나무를 심고싶음

3. 심어져 있는 가로수의 위치가 주어질 때, 모든 가로수가 같은 간격이 되도록 새로 심어야 하는 가로수의 최소수를 구하는 프로그램 작성하기
- 추가되는 나무는 기존의 나무들 사이에만 심을 수 있음


## 입력

1. 이미 심어져 있는 가로수의 수를 나타내는 하나의 정수 N

2. 가로수의 위치가 양의 정수로 주어짐
- 기준점으로부터 떨어진 거리가 가까운 순서대로 주어짐 ( ASC 정렬된 상태로 )

## 출력
1. 모든 가로수가 같은 간격이 되도록 새로 심어야 하는 가로수의 최소수를 첫번째 줄에 출력하기

## 풀이
1. 거리 리스트 만들기 -> 최대공약수 구하기 -> 최대공약수만큼 돌면서 없는 부분에 가로수 심기

## 코드

### ( 정답 ) : 시간 168ms

```python
import sys
import math

input = sys.stdin.readline

n = int(input())

n_list = [int(input()) for _ in range(n)]

d_list = []

for i in range(n-1):
    d_list.append(n_list[i+1] - n_list[i])

# 최대 공약수 구하기
GCD = math.gcd(*d_list)

# 정답
ans = 0

checkNum = n_list[0]

for j in range(1, n):
    checkNum += GCD
    if checkNum == n_list[j]:
        continue
    else:
        a, b = divmod(n_list[j], GCD)
        c, d = divmod(checkNum, GCD)
        ans += a - c
        checkNum = n_list[j]


print(ans)
```