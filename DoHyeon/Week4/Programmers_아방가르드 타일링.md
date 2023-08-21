```python

import sys
sys.setrecursionlimit(10**6)

memo = [0] * 100001

memo[1] = 1
memo[2] = 3
memo[3] = 10
memo[4] = 23
memo[5] = 62
memo[6] = 170

k = 1000000007

def solution(n):
    answer = cal(n)
    # 정말 많이 고민했는데 결국 답을보고야 말았다...
    # https://school.programmers.co.kr/questions/47346 이 힌트가 많은 도움이 되었다
    # 결국 특정 n에서만 가능한 패턴은 일정한 규칙에 따라 증가하게 된다.
    # 특정 n에서만 가능한 패턴의 개수를 s(n)이라고 할 때
    # s(1) == 1, s(2) == 2 s(3) == 5 이고
    # s(4 + 3k) == 2, s(5+3k) == 2, s(6+3k) == 4 로 일정하게 증가한다
    # 이를 정리하여 점화식을 만들고 점화식을 정리하여 일반식을 구하면 풀리는 문제이다.
    # A(n) 을 n * 3 크기의 판을 타일링하는 방법의 수라고 할 때
    # A(n) = A(n-1)*s(1) + A(n-2)*s(2) + ... + A(n-k)s(k) + ... + A(1)s(n) 이다.
    # 이를 정리하는건 주석으론 표현이 힘들어서 생략하도록 하겠다....
    # 정리하면 A(n) = A(n-1) + 2A(n-2) + 6A(n-3) + A(n-4) - A(n-6) + s(n) - s(n-3)이다.
    # 이를 메모제이션 기법으로 재귀적으로 처리하면 된다...
    # 코딩은 간단한데 생각하기가 너무어려웠다.
    
    return answer

def cal(n):
    if memo[n] != 0:
        return memo[n]
    else:
        memo[n] = (cal(n-1)%k + 2 * (cal(n-2)%k) + 6 * (cal(n-3)%k) + cal(n-4)%k - cal(n-6)%k)%k
        return memo[n]
                
            

 
```
