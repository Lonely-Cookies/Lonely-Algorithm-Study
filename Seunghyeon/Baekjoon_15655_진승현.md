## 문제 요약

**n 과 m ( 6 ) ( 실버 3 )**
1. n개의 자연수와 자연수 m 이 주어졌을 때
- 아래 조건을 만족하는 길이가 m인 수열을 모두 구하는 프로그램 작성하기
- n 개의 자연수 중에서 m개를 고른 수열
- 고른 수열은 오름차순



## 입력
1. n, m
2. n개의 수


## 출력
1. 문제의 조건을 만족하는 수열 출력하기

## 풀이
1. 조합
2. 백트래킹

## 코드

### ( 정답 ) : 시간 52ms

```python
import sys

def back(list, back_list, level, depth):
    if len(back_list) == m:
        print(*back_list)
        return

    for i in range(level, depth):
        back_list.append(list[i])
        back(list, back_list, i+1, depth)
        back_list.pop()

input = sys.stdin.readline

n, m = map(int, input().split())
n_list = list(map(int, input().split()))

n_list.sort() # 오름차순 정렬
back_list = [] # 백트래킹 원소를 저장할 리스트
# back : list, back_list, level, depth
back(n_list, back_list, 0, n)

```