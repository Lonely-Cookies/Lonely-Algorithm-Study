## 문제 요약

**가장 긴 증가하는 부분 수열 5 ( 플레티넘 5 )**

1. 수열이 주어졌을 때, 가장 긴 증가하는 부분 수열 구하기

## 입력
1. 수열의 크기 n

2. 수열을 이루고 있는 숫자

## 출력
1. 수열의 가장 긴 증가하는 부분 수열의 길이 출력

2. 정답이 될 수 있는 가장 긴 증가하는 부분 수열 출력

## 풀이
1. LIS

2. 역탐색

## 코드

### 정답 : 시간 1400ms

```python
import sys
import bisect

input = sys.stdin.readline

n = int(input())
n_list = list(map(int, input().split()))

ans_list = [n_list[0]]
ans_total = [(n_list[0], 0)]

for i in range(1, n):
    target = n_list[i]

    if ans_list[-1] < target:
        ans_list.append(target)
        ans_total.append((target, len(ans_list)-1))
    else:
        # 이분 탐색
        idx = bisect.bisect_left(ans_list, target)
        ans_list[idx] = target
        ans_total.append((target, idx))

lis_len = len(ans_list)-1
res = []

# 역탐색
for i in range(len(ans_total)-1, -1, -1):
    if ans_total[i][1] == lis_len:
        res.append(ans_total[i][0])
        lis_len -= 1

print(len(ans_list))
print(*(reversed(res)))


```
