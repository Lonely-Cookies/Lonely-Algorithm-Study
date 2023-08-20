## 문제 요약

**평범한 배낭 ( 골드 5 )**

n개의 물건 -> 무게 : w, 가치 : v
최대 k 만큼의 무게만을 배낭에 넣을 수 있음

배낭에 넣을 수 있는 물건들의 가치의 최댓값

## 입력
1. 물품의 수 n, 버틸 수 있는 무게 k
2. 각 물건의 무게 w, 물건의 가치 v

## 출력
1. 배낭에 넣을 수 있는 물건들의 가치합의 최댓값 출력하기

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 3852ms

```python
input = sys.stdin.readline

# n : 물품의 수, k : 버틸 수 있는 무게
n, k = map(int, input().split())

# dp
dp = [0 for i in range(k+1)]

# w, v 리스트 만들기
w_list = []
for i in range(n):
    # w : 물건의 무게, v : 물건의 가치
    w, v = map(int, input().split())

    w_list.append([w,v])


for i in range(n):
    for j in range(k, w_list[i][0]-1, -1):
        dp[j] = max(dp[j], dp[j-w_list[i][0]]+w_list[i][1])

print(dp[k])
```

1. DP
