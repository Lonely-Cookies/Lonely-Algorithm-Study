## 문제 요약

**크리스마스 선물 ( 실버 3 )**

1. 선물 나눠주기
- 거점들을 세워 그 곳을 방문하며 선물 충전
- 착한 아이들을 만날 때 마다 자신이 들고있는 가장 가치가 큰 선물 하나 주기

2. 차례대로 방문한 아이들과 거점지의 정보들이 주어짐
- 아이드링 준 선물들의 가치 출력하기
- 아이들에게 줄 선물이 없다면 -1 출력하기

## 입력
1. 아이들과 거점지를 방문한 횟수 n

2. 0 일경우, 아이들을 만난 것
- 그렇지 않으면 선물 충전 ( < 100000 )

## 출력
1. a 가 0 일 때마다, 아이들에게 준 선무르이 가치 출력하기

2. 줄 선물이 없다면 -1 출력하기

## 풀이
1. 최대 힙

## 코드

### 정답 : 시간 136ms

```python
import sys
import heapq

input = sys.stdin.readline

n = int(input())
heap = []
for i in range(n):
    a_list = list(map(int, input().split()))

    # a 가 0 일경우
    if a_list[0] == 0:
        if len(heap) == 0:
            print(-1)
        else:
            print(-heapq.heappop(heap))
    else:
        for j in range(1, len(a_list)):
            heapq.heappush(heap, -a_list[j])


```
