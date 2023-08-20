## 문제 요약

**N과 M ( 4 ) ( 실버 3 )**

1. 자연수 N, M
2. 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램 작성하기
- 1 ~ N 까지 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 됨
- 고른 수열은 비내림차순

## 입력
1. 자연수 N, M

## 출력
1. 조건을 만족하는 수열 출력
2. 공백 구분
3. 사전 순 증가하는 순서로 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 60ms

```python
import sys
def back(start):
    if len(n_list) == m:
        print(*n_list)
        return

    for i in range(start, n+1):
        n_list.append(i)
        back(i)
        n_list.pop()

input = sys.stdin.readline

n,m = map(int, input().split())

n_list = []

back(1)
```

1. 백트래킹