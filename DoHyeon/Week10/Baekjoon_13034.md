```python
import sys

N = int(sys.stdin.readline())

# 이거 알고리즘 분류에 스프라그-그런디 정리라고 되어있다
# 이걸 어떻게 스프라그- 그런디 정리로 치환할까..
# 0은 0이다. 무조건 선공이 진다. 1 역시 0이다. 2는 어떨까? 2는 선공이 무조건 이긴다. 이를 1이라고 하자.
# N은 최소 3 이상이다. 3일 때는 2와 1로 분해될 수 있다. 2는 1, 1은 0이다. 현재 순서에 이을 점 두개인 2를 제외 나머지 1은 0이다. 따라서 이후 가능한
# 행동 집합이 해당 턴의 사용자가 무조건 지는 행동집합이 되므로 3은 1임을 알 수 있다.
# N이 4 일땐 어떨까? 점 두 개 제외 1 1, 2 로 분해될 수 있는데 1 1은 각각을 xor 하면 0이고 2는 1이므로 상대의 행동집합을 0으로 만드는 수가 존재한다.
# 따라서 4의 그런디 수는 2이다.
# 5일 때는 3 0, 1 2 로 분해된다. 3은 1이다. 따라서 1xor0 = 1 1은 0, 2는 1이므로 2xor0 = 1 따라서 5는 0이다.
# 이런 식으로 아래에서부터 채워나가면 답이 나온다.


dp = [-1]*(N+1)


def make_dp(num):
    num_list = []
    result_set = set()
    if num < 3:
        return
    else:
        next_num = num - 2
        for i in range(next_num//2+1):
            # print((i, next_num - i))
            num_list.append((i, next_num-i))

    for a, b in num_list:
        result_set.add(dp[a] ^ dp[b])
    # print(result_set)
    val = 0
    for i in range(10):
        if i not in result_set:
            val = i
            break
    dp[num] = val
    # print(str(num) + " : " + str(dp[num]))


dp[0] = 0
dp[1] = 0
dp[2] = 1
dp[3] = 1
for num in range(4, N+1):
    make_dp(num)

if dp[N] == 0:
    print(2)
else:
    print(1)
```
