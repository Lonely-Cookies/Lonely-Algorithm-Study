## 문제 요약

**카드 합체 놀이 ( 실버 1 )**

1. 카드 : n장
2. x번 카드와 y번 카드를 골라 그 두장에 쓰여진 수를 더한 값 계산
3. 계산한 값을 x번 카드와 y번 카드 두장 모두에 덮어 쓰기
4. 이 카드 합체를 m번 진행
5. m번 진행 후, 카드에 적힌 수를 모두 더한 값 출력하기
6. 출력값이 가장 작은 값이 되도록 하는 것이 목표


## 입력
1. 카드의 개수 : n
2. 카드 합체 횟수 : m
3. 카드의 상태를 나타내는 n 개의 자연수

## 출력
1. 만들 수 있는 가장 작은 점수 출력하기

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 60ms

```python
import sys
import heapq

input = sys.stdin.readline

n,m = map(int, input().split())
# 리스트 생성
heap = list(map(int,input().split()))

# 힙 변환
heapq.heapify(heap)

for _ in range(m):
    num1, num2 = heapq.heappop(heap), heapq.heappop(heap)

    ans = num1+num2

    for i in range(2):
        heapq.heappush(heap, ans)

print(sum(heap))

```

1. 힙 활용
