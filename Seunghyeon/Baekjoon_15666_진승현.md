## 문제 요약

**n과m ( 12 ) ( 실버 2 )**

1. n과 m ( 자연수 ) 이 주어졌을 때, 아래 조건을 만족하는 길이가 m 인 수열 모두 구하기
- N개의 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
- 고른 수열은 비내림차순이어야 한다.
## 입력
1. n, m
## 출력
1. 수열 출력하기
- 중복 수열 X
- 각 수열은 공백으로 구분
- 수열은 사전 순으로 증가하는 순서로 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 6376ms

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
n_list = list(set(map(int, input().split())))

n_list.sort()

ans = []

back()
```
