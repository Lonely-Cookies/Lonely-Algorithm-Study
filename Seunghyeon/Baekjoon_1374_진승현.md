## 문제 요약

**강의실**
1. N 개의 강의
- 모든 강의의 시작하는 시간과 끝나는 시간을 알고있음

2. 최대한 적은 수의 강의실을 사용하여 모든 강의가 이루어지게 하고 싶음
- 한 강의실에서 동시에 2개 이상의 강의를 진행할 수 없음
- 한 강의의 종료 시간과 다른 강의의 시작 시간이 겹치는 것은 상관없음

3. 필요한 최소 강의실의 수를 출력하는 프로그램 작성하기


## 입력
1. 강의의 개수 N

2. 강의 번호, 강의 시작 시간, 강의 종료 시간
- 시작 시간은 종료 시간보다 작음

## 출력
1. 필요한 최소 강의실 개수 출력하기

## 코드

### ( 정답 ) : 시간 404ms

```python
import sys
import heapq

input = sys.stdin.readline

n = int(input())
n_list = []
heap = []

for _ in range(n):
    n_list.append(list(map(int, input().split())))

n_list.sort(key=lambda x: (x[1],x[2]))

# 강의실 갯수
cnt = 0

for idx, ft1, lt1 in n_list:

    if len(heap) == 0:
        # 강의실 추가
        heapq.heappush(heap, lt1)
        cnt += 1
        continue

    lt2 = heapq.heappop(heap)

    # 현재 끝난 시간과 다음 수업의 시작 시간 비교
    if lt2 <= ft1:
        heapq.heappush(heap, lt1)
    else:
        heapq.heappush(heap, lt2)
        heapq.heappush(heap, lt1)
        cnt += 1

print(cnt)

```