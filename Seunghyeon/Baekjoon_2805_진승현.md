## 문제 요약

**나무 자르기 ( 실버 2 )**

1. 나무 m미터 필요

2. 목재절단기를 이용해서 나무를 구할 예정
- 절단기 높이 h 지정
- 높이가 h보다 큰 나무는 h 위의 부분이 잘림
- 낮은 나무는 잘리지 않음

3. 적어도 m미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램 작성하기

## 입력
1. 나무의 수 : n, 집으로 가져가려는 나무의 길이 : m
2. 나무의 높이
## 출력
1. 적어도 m 미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값 출력하기
## 코드

### 내가 푼 코드 ( 정답 ) : 시간 540ms

```python
import sys

input = sys.stdin.readline

n,m = map(int, input().split())

n_list = list(map(int, input().split()))

left, right = 1, max(n_list)
# 결과를 담는 변수
res = 0
while left <= right:
    mid = (left+right)//2
    num = 0
    for i in range(n):
        # 현재 절단기 값보다 작을경우
        if mid > n_list[i]:
            continue
        num += (n_list[i]-mid)

    # 만약 현재 나무토막 크기가 더 클 경우
    if num >= m:
        left = mid+1
        res = mid
    else:
        right = mid-1

print(res)

```

## 풀이

1. 중앙값 구하기
2. 중앙값을 이용해서 계산한 값과 나무의 길이 비교
3. 값을 다 더해보고, 값이 작을경우 left 이동
4. 더 클 경우, right 이동
