## 문제 요약

**로또 ( 실버 2 )**
1. 1 ~ 49 중 수 6개 고르기
- 49가지 중 k개 ( > 6 ) 의 수를 골라 집합 S 를 만듬
- 이 집합에서 그 수만 가지고 6개의 번호 선택하기

2. 집합 S 와 k 가 주어졌을 때, 수를 고르는 모든 방법 구하기



## 입력
1. 여러 개의 테스트 케이스

2. 마지막 : 0


## 출력
1. 각 테스트 케이스마다 수를 고르는 모든 방법 출력
- 사전순

## 풀이
1. 조합
2. 백트래킹

## 코드

### 위상 정렬 ( 정답 ) : 시간 48ms

```python
import sys
def back(lst, level, depth):
    if len(back_list) == 6:
        print(*back_list)
        return

    for i in range(level, depth):
        back_list.append(lst[i])
        back(lst, i+1, depth)
        back_list.pop()

input = sys.stdin.readline

while True:
    n_list = list(map(int, input().split()))

    # 만약 0이 들어왔을 경우 종료
    if n_list.pop(0) == 0:
        break

    # 6개의 수를 선택해서 차례대로 출력 ( 사전순 )
    n_list.sort()

    # 백트래킹을 돌며 원소를 출력할 리스트
    back_list = []

    back(n_list, 0, len(n_list))

    print()
```