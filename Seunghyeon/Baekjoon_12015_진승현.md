## 문제 요약

**가장 긴 증가하는 부분 수열 2 ( 골드 2 )**

1. 수열이 주어졌을 때, 가장 긴 증가하는 부분 수열 구하기

## 입력
1. 수열의 크기
2. 수열 a

## 출력
1. 수열 a 의 가장 긴 증가하는 부분 수열의 길이 출력

## 풀이
1. 수열의 가장 긴 증가하는 부분 수열 길이 출력
- 이분탐색 ( LIS )
- 현재 리스트의 가장 큰 값과 비교 했을 때 클 경우 -> 추가
- 아닐 경우 이분탐색 진행해서 값 업데이트 하기
- 마지막으로 리스트의 길이 출력

## 코드

### 정답 : 시간 968ms

```python
import sys
import bisect

input = sys.stdin.readline

n = int(input())
n_list = list(map(int, input().split()))

# 큰 값만 넣을 리스트
ans_list=[n_list[0]]

for i in range(1, n):
    target = n_list[i]

    # 리스트 값 비교
    if ans_list[-1] < target:
        ans_list.append(target)
    else:
        # 이분탐색 진행
        idx = bisect.bisect_left(ans_list, target)
        ans_list[idx] = target

print(len(ans_list))

```

LIS 와 DP 를 많이 참고했음