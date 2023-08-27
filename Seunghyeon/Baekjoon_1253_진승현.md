## 문제 요약

**좋다 ( 골드 4 )**

1. n 개의 수
- 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 좋다고 함
- 좋은 수의 갯수는 몇 개 인지 출력하기
- 수의 위치가 다르면 값이 같아도 다른 수 ( 인덱스 번호 )


## 입력
1. 수의 개수
2. Ai

## 출력
1. 좋은 수의 개수를 첫번쩨 줄에 출력하기

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 160ms

```python
import sys

input = sys.stdin.readline
# 입력값 받기
n = int(input())
n_list = list(map(int, input().split()))

n_list.sort()

cnt = 0
for i in range(n):
    # 투포인터
    left, right = 0, n - 1

    while left < right:
        num = n_list[left] + n_list[right]

        if num == n_list[i]:
            # 다른 수 체크
            if left != i and right != i:
                cnt += 1
                break
            # 왼쪽만 같으면
            elif left == i:
                left += 1
            else:
                right -= 1
        elif num < n_list[i]:
            left += 1
        else:
            right -= 1

print(cnt)

```

