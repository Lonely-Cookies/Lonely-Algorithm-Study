## 문제 요약

**N과 M ( 9 ) ( 실버 2 )**

1. N 개의 자연수 중에서 M 개를 고른 수열

## 입력
1. 자연수 N, M
2. N 개의 수

## 출력
1. 조건을 만족하는 수열 출력
2. 공백 구분
3. 사전 순 증가하는 순서로 출력
4. 중복되는 수열 출력 X

## 코드

### 내가 푼 코드 ( 실패 ) : 시간초과

```python
import sys
def back():
    # 완료 조건
    if len(ans_list) == m:
        if ans_list not in c_list:
            print(' '.join(map(str, ans_list)))
            return

    for i in range(n):
        if not visited[i]:
            ans_list.append(n_list[i])
            visited[i] = True
            back()
            c_list.append(list(ans_list))
            ans_list.pop()
            visited[i] = False


input = sys.stdin.readline

n,m = map(int, input().split())
n_list = sorted(list(map(int, input().split())))

ans_list = []
# 방문 처리
visited = [False for _ in range(n)]

c_list = []

back()


```
1. 중복을 제거하는 과정에서, 시간복잡도를 줄이지 못했음

### 정답 : 시간 88ms
```python
import sys
def back():
    # 완료 조건
    if len(ans_list) == m:
        print(' '.join(map(str, ans_list)))
        return
    # 중복 숫자를 제거하기 위한 변수
    tmp = 0
    for i in range(n):
        if not visited[i] and tmp != n_list[i]:
            ans_list.append(n_list[i])
            visited[i] = True
            back()
            # 중복 제거
            tmp = n_list[i]
            ans_list.pop()
            visited[i] = False


input = sys.stdin.readline

n,m = map(int, input().split())
n_list = sorted(list(map(int, input().split())))

ans_list = []
# 방문 처리
visited = [False for _ in range(n)]

back()
```

1. 중복을 제거하기 위한 변수를 하나 설정
2. 재귀 호출시, 이전 숫자와 동일시 ( 9 -> 9 )
3. 그 다음부터는 리스트에 추가가 되지 않도록 설정함으로써 재귀호출을 막음