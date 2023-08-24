## 문제 요약

**다각형의 면적 ( 골드 5 )**

1. 점으로 이루어진 다각형의 면적을 구하는 프로그램 구하기

## 입력
1. n ( 점의 수 )
2. x,y 좌표

## 출력
1. 면적 출력
- 소수점 아래 둘째 자리에서 반올림

## 풀이
1. 신발끈 공식

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 64ms

```python
import sys

input = sys.stdin.readline

n = int(input())
xy_list = []

for _ in range(n):
    x,y = map(int, input().split())

    xy_list.append([x,y])

xy_list.append([xy_list[0][0],xy_list[0][1]])

n1 = 0
n2 = 0

for i in range(n):
    n1 += xy_list[i][0] * xy_list[i+1][1]
    n2 += xy_list[i][1] * xy_list[i+1][0]

ans = abs(n1 - n2) / 2

print(round(ans, 1))

```

