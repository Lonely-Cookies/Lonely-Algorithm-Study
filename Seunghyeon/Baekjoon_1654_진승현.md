## 문제 요약

**랜선 자르기 ( 실버 2 )**
1. k개의 랜선
- 길이는 제각각

2. 랜선을 모두 n개의 같은 길이의 랜선으로 만들고 싶음
- k개의 랜선을 잘라서 만들어야 함

3. 자르거나 만들 때 손실되는 길이 X

4. k 개의 랜선으로 n 개의 랜선을 만들 수 없는 경우는 없음

5. n 개보다 많이 만드는 것도 n 개를 만드는 것에 포함됨

6. 만들 수 있는 최대 랜선의 길이를 구하는 프로그램 작성하기


## 입력
1. 랜선의 개수 k, 필요한 랜선의 개수 n

## 출력
1. n개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력

## 풀이
1. 최솟값 1, 최댓값 찾기
2. 값을 더하고 2로 나눈값을 변수에 저장
3. 나눈 정수값 변수에 계속해서 더하고
4. 만약 다 더한 변수값이 n 보다 작을경우
- 크기 줄이기
- 그렇지않으면 크기 늘리기

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 128ms

```python
import sys

input = sys.stdin.readline

n,k = map(int, input().split())

n_list = []

for _ in range(n):
    n_list.append(int(input()))

le, ri = 1, max(n_list)
res = 0
while le <= ri:
    s = 0
    mid = (le+ri)//2

    for i in range(n):
        s += (n_list[i] // mid)

    if s >= k:
        le = mid + 1
        res = mid
    else:
        ri = mid - 1

print(res)

```

