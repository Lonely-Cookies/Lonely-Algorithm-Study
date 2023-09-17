## 문제 요약

**부분수열의 합 ( 실버 2 )**
1. n개의 정수로 이루어진 수열
- 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S 가 되는
경우의 수를 구하는 프로그램을 작성

## 입력
1. 정수의 개수를 나타내는 n, s

2. n개의 정수가 빈 칸을 사이에 두고 주어짐

## 출력
1. 합이 s가 되는 부분수열의 개수 출력하기

## 풀이
1. 백트래킹
2. 백트래킹으로 탐색하면서, 값이 s 가 되는 케이스 찾기

## 코드

### 풀이 ( 정답 ) : 시간 484ms

```python
import sys
def back(start):
    global cnt
    if sum(back_list) == s and len(back_list) > 0:
        cnt += 1

    for i in range(start, n):
        back_list.append(n_list[i])

        back(i + 1)

        back_list.pop()

cnt = 0

input = sys.stdin.readline

n, s = map(int, input().split())
n_list = list(map(int, input().split()))

# 백트래킹 값을 저장할 리스트
back_list = []

back(0)

print(cnt)
```