## 문제 요약

**부분 합 ( 골드 4 )**
1. 10000 이하의 자연수로 이루어진 길이 n 수열

2. 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중 가장 짧은 것의 길이를 구하는 프로그램 작성하기


## 입력
1. n ( 10 ~ 100000 ), s ( 0 ~ 100000000 )
2. 수열


## 출력
1. 구하고자 하는 최소의 길이 출력
2. 불가능하다면, 0 출력

## 풀이
1. 투 포인터 이용 ( 왼쪽부터 시작 )
2. 누적합이 s 이상일 경우, 연속 수열인지 체크하기

---
### 풀이 2차전
1. 현재 값과 그 다음 값 비교
2. 다음 값이 더 크면, 누적합에 저장

--- 
### 풀이 3차전
1. 뒤에서부터 돌기
---
### 풀이 4차전
1. 말 그대로 연속된 수이기 때문에.. 그냥 하면 됨 ( 연속적이기만 하면 )
2. ( 지금까지 삽질.. )
3. 문제 이해를 제대로 못했다.

## 코드

### 해설 참고 ( 정답 ) : 시간 144ms

```python
import sys

input = sys.stdin.readline

n,s = map(int, input().split())
n_list = list(map(int, input().split())) + [0]

start, end = 0, 0
length = 0
# 부분 합
sumNum = 0
# 정답
ans = 100000001
# 리스트의 끝까지 탐색 진행
while end <= n:
    # s 값에 못 미칠 경우
    if sumNum < s:
        sumNum += n_list[end]
        # 그 다음으로 이동
        length += 1
        end += 1
    else:
        ans = min(ans, length)
        # 왼쪽 한칸 이동
        start += 1
        # 왼쪽으로 한칸 이동했으니 이전값 빼기
        sumNum -= n_list[start-1]
        length -= 1

if ans == 100000001:
    print(0)
else:
    print(ans)

```

