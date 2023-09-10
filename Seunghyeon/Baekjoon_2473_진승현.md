## 문제 요약

**세 용액 ( 골드 3 )**
1. 산성용액 : 1 ~ 10억, 알칼리성 용액 : -10억 ~ -1

2. 같은 양의 3가지 용액을 혼합한 용액의 특성값
- 혼합에 사용된 각 용액의 특성값의 합으로 정의
- 세가지 용액을 혼합하여 특성값이 0에 가까운 용액 만들기


## 입력
1. 전체 용액의 수 n

2. 용액의 특성값을 나타내는 n개의 정수

3. only 산성 혹은 only 알칼리성 용액만 주어질 수도 있음


## 출력
1. 특성값이 0에 가장 가까운 용액을 만들어내는 세 용액의 특성값 출력하기

2. 특성값이 0에 가장 가까운 용액을 만들어내는 경우가 2개 이상
- 아무거나 하나 출력

## 풀이
1. Left, Mid, Right ( 3개 포인터 )

## 코드

### 내가 푼 코드 ( 실패 )

```python
import sys

input = sys.stdin.readline

n = int(input())
n_list = list(map(int, input().split()))

# 정렬
n_list.sort()

left, mid, right = 0, (n-1) // 2, n-1

# 정답
ans = [n_list[left], n_list[mid], n_list[right]]

# 임시 합
mm = 2000000001
sumNum = 0
while left < right:

    for middle in range(left + 1, right):

        sumNum = n_list[left] + n_list[middle] + n_list[right]
        # 만약 더한 값의 절댓값이 mm 보다 작을 경우
        if abs(sumNum) < abs(mm):
            ans[0] = n_list[left]
            ans[1] = n_list[middle]
            ans[2] = n_list[right]
            mm = sumNum
           
    if sumNum < 0:
        left += 1
    elif sumNum == 0:
        break
    else:
        right -= 1

print(*ans)

```
아래의 테스트코드를 통과하지 못했음

5

-4 -2 -1 2 3

일 때 -2, -1, 3 을 선택해야 하는데 첫번째 탐색이 다 끝났을 때 right -= 1 이 돼버려서 제대로 된 탐색이 진행되지 않았음

---

### 정답 코드 ( 성공 ) : 속도 188ms
```python
import sys

input = sys.stdin.readline

n = int(input())
n_list = list(map(int, input().split()))

# 정렬
n_list.sort()

left, mid, right = 0, (n-1) // 2, n-1

# 정답
ans = [n_list[left], n_list[mid], n_list[right]]

# 임시 합
mm = 4000000001
sumNum = 0

for left in range(0, n-2):
    mid, right = left + 1, n - 1

    while mid < right:
        sumNum = n_list[left] + n_list[mid] + n_list[right]

        if abs(sumNum) < mm:
            mm = abs(sumNum)
            ans[0], ans[1], ans[2] = n_list[left], n_list[mid], n_list[right]

        if sumNum < 0:
            mid += 1
        elif sumNum == 0:
            break
        else:
            right -= 1

print(*ans)
```

차이점
1. 최댓값의 범위
2. 탐색 방법
- 난 처음에 왼쪽, 오른쪽을 미리 값을 정해놓고 가운데 값이 이동하면서 탐색 진행
- 하지만 제대로 탐색이 진행되지 않았고, 여기선 왼쪽만 값을 정해놓고 중간과 오른쪽을 활용해서 탐색을 진행했음