## 문제 요약

**n과 m ( 실버 3 )**

1. n개의 자연수와 자연수 m 이 주어졌을 때, 아래 조건을 만족하는 길이가 m 인 수열을 모두 구하는 프로그램 작성하기
2. n 개의 자연수는 모두 다른 수
- N개의 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
- 고른 수열은 비내림차순이어야 한다.

## 입력
1. n, m 입력
2. n 개의 수

## 출력
1. 문제의 조건을 만족하는 수열 출력
2. 중복 수열 출력 X
3. 각 수열은 고백으로 구분해서 출력
4. 수열은 사전 순으로 증가하는 순서로 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 64ms

```python
import sys
def back():
    if len(ans) == m:
        print(*ans)
        return

    for i in n_list:
        if len(ans) == 0:
            ans.append(i)
            back()
            ans.pop()
        else:
            if ans[-1] <= i:
                ans.append(i)
                back()
                ans.pop()

input = sys.stdin.readline

n,m = map(int, input().split())
n_list = list(map(int, input().split()))

n_list.sort()

ans = []

back()

```

1. 크기를 비교하는 if 문 을 백트래킹 과정에 넣어줌