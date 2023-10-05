## 문제 요약

**KCPC**
1. k개의 문제풀이
- 0점 ~ 100점 사이의 점수를 얻음
- 팀의 id, 문제 번호, 점수가 서버의 로그에 제출되는 시간 순서대로 저장됨
- 한 문제에 대한 풀이를 여러 번 제출할 수 있음
- 그 중 최고 점수가 그 문제에 대한 최종 점수가 됨 ( 미제출시 0점 )

2. 팀의 최종 점수 = 각 문제에 대해 받은 점수의 총합

3. 순위 = 우리 팀보다 높은 점수를 받은 팀의 수 + 1

4. 점수가 동일한 팀을 나누는 기준
- 최종 점수가 같은 경우, 풀이를 제출한 횟수가 적은 팀의 순위가 높음
- 최종 점수도 같고 제출 횟수도 같은 경우, 마지막 제출 시간이 더 빠른 팀의 순위가 높음

5. 동시 제출 X, 모든 팀이 적어도 한번은 풀이를 제출한다고 가정

6. 서버의 로그가 주어졌을 때, 팀 순위를 계산하는 프로그램 작성하기


## 입력
1. T개의 테스트 데이터

2. 첫번째 줄 : 팀의 개수 n, 문제의 개수 k, 팀의 ID t, 로그 엔트리의 개수 m

3. m개의 줄에는 각 풀이에 대한 정보가 제출되는 순서대로 주어짐
- 팀 ID i, 문제 번호 j, 획득한 점수 s

## 출력
1. 팀 순위 출력하기


## 풀이
1. 배열 활용

2. 람다식을 썼으면 시간을 덜 잡아먹었을 듯 하다.

## 코드

### ( 정답 ) : 시간 140ms

```python
import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    # n : team, k : problem, t : team id, m : log entry
    n, k, t, m = map(int, input().split())
    # [[0,0,0 ...], [0,0,0 ...] ... ] ( n * k )
    n_list = [[0] * k for _ in range(n)]

    # 제출횟수가 적은 팀
    review_count = [0] * n

    # 빨리 제출한 팀
    fast_count = [0] * n

    # log entry
    for cnt in range(1, m+1):
        # i : team id, j : 문제번호, s : score
        i, j, s = map(int, input().split())
        # max(s, ~)
        n_list[i-1][j-1] = max(n_list[i-1][j-1], s)
        # 제출횟수 체크
        review_count[i-1] += 1
        # 빨리 제출한 순서 체크
        fast_count[i-1] = cnt

    # 점수 합하기
    n_sum_list = [0] * n

    for k in range(n):
        n_sum_list[k] = sum(n_list[k])

    # 등수 구하기
    ans = 1
    # 내 팀의 점수
    my_team_score = n_sum_list[t-1]

    for l in range(n):
        if l == (t-1):
            continue
        if my_team_score < n_sum_list[l]:
            ans += 1
        # 점수가 같을 경우
        elif my_team_score == n_sum_list[l]:
            # 풀이 제출 횟수 비교하기
            # 풀이 횟수가 더 적을경우
            if review_count[t-1] < review_count[l]:
                continue
            elif review_count[t-1] == review_count[l]:
                # 제출 시간 체크
                if fast_count[t-1] < fast_count[l]:
                    continue
                else:
                    ans += 1
            else:
                ans += 1

    print(ans)

```