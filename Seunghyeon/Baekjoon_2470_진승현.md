## 문제 요약

**두 용액 ( 골드 5 )**

1. 산성, 알칼리성
- 그 용액의 특성을 나타내는 하나의 정수가 주어짐
- 산성 : 1 ~ 10000000000 ( 10억 )
- 알칼리성 : -1 ~ -1000000000 ( -10억 )

2. 같은 양의 두 용액을 혼합한 용액의 특성값
- 혼합에 사용된 각 용액의 특성값의 합으로 정의
- 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 함

3. 같은 종류만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재함

## 입력
1. 전체 용액의 수 n
2. 용액의 특성값 리스트

## 출력
1. 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 122ms

```python
import sys

input = sys.stdin.readline

n = int(input())

n_list = list(map(int, input().split()))

n_list.sort()

left, right = 0, len(n_list)-1
mm = 2000000001
ans = [n_list[left], n_list[right]]

while left < right:
    tmp = n_list[left]+n_list[right]

    if abs(tmp) < abs(mm):
        ans[0] = n_list[left]
        ans[1] = n_list[right]
        mm = tmp

    if tmp < 0:
        left += 1
    elif tmp > 0:
        right -= 1
    else:
        break

print(*ans)
```

1. 이분탐색
