## 문제 요약

**N과 M ( 5 ) ( 실버 3 )**

1. N 개의 자연수 중에서 M 개를 고른 수열

## 입력
1. 자연수 N, M
2. N 개의 수

## 출력
1. 조건을 만족하는 수열 출력
2. 공백 구분
3. 사전 순 증가하는 순서로 출력
4. 중복 X

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 200ms

```python
import sys

def back():
    if len(ans_list) == m:
        print(*ans_list)
        return
    
    for i in n_list:
        # 중복 제거
        if i in ans_list:
            continue
        ans_list.append(i)
        back()
        ans_list.pop()

input = sys.stdin.readline

n,m = map(int, input().split())
n_list = list(map(int, input().split()))

# 정렬
n_list.sort()

ans_list = []
back()

```

1. 백트래킹