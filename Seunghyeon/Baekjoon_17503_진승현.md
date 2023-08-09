## 문제 요약

**맥주 축제 ( 실버 1 )**

1. N일 동안 K 종류의 맥주를 무료 제공
- 참가자 : 하루에 맥주 1병만 받을 수 있음
- 이전에 받았던 종류의 맥주는 다시 받을 수 없음

2. N 일동안 맥주 N병 마시기
- 도수가 높은 맥주를 마시면 기절하는 맥주병이 있음
- 간 강화 계획

3. K 종류의 맥주 : 선호도, 도수 레벨

4. 마시는 맥주의 도수 레벨이 전씨의 간 레벨보다 높으면 맥주병이 발병해 기절해버림

5. 맥주병에 걸리지 않으면서도 자신이 좋아하는 맥주를 많이 마시고 싶어함
- 맥주 N개의 선호도 합이 M 이상이 되게 해야 함

## 입력
1. N : 기간, M : 선호도 합, K : 맥주 종류 수

2. K 개의 줄 : 선호도, 도수 레벨

## 출력
1. 선호도의 합 M을 채우면서 N개의 맥주를 모두 마실 수 있는 간 레벨의 최솟값 출력하기
2. 조건을 만족할 수 없다면, -1 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 776ms

```python
import sys
import heapq

input = sys.stdin.readline
# n : 기간, m : 선호도의 합, k : 맥주 종류의 수
n,m,k = map(int, input().split())

k_list = []
for _ in range(k):
    # 선호도, 도수 레벨
    k_list.append(list(map(int, input().split())))

# 정렬
k_list.sort(key=lambda x:(x[1], x[0]))

heap = []
# 정답
ans1 = 0
ans2 = 0
for i in k_list:
    # 선호도
    ans1 += i[0]
    heapq.heappush(heap, i[0])

    # n번 다 마셨을 경우
    if len(heap) == n:
        if ans1 >= m:
            ans2 = i[1]
            break
        else:
            ans1 -= heapq.heappop(heap)

if ans2 == 0:
    print(-1)
else:
    print(ans2)
```

1. 선호도, 도수 레벨 기준으로 정렬
2. 힙을 사용해서 n번 다 마셨을 때 선호도의 합 체크하기

