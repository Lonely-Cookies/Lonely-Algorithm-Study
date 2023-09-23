```python
import sys

# 스프라그-그런디 정리와 그런디 수에 대한 자료 https://casterian.net/algo/sprague-grundy.html
# https://developerhan.tistory.com/30
# 근데 아직 무슨 소리인지 잘 모르겠다;;
# 이걸 알아야 이 문제를 완벽히 이해하고 풀 수 있다.

N = int(sys.stdin.readline())

towers = list(map(int, sys.stdin.readline().split()))

# 마지막 돌을 가져가면 지는 게임이다. 따라서 돌이 한 개만 있는 더미만 존재할 경우 홀수 개의 더미가 있을 때
# 선공이 무조건 진다.
# 돌이 1개인 더미가 하나도 없을 경우 스프라그-그런디 정리에 따라 마지막 돌을 가져가면 이기는 게임의
# 그런디 수를 반대로 해석하면 된다? -> 이건 확신이 없지만 일단 그렇다고 치자.
# 돌 더미가 비어있는 경우의 그런디 수를 1 이라고 하자. 이 때의 선공은 이긴다.
# 돌 더미에 있는 돌이 1개인 경우를 0 이라고 하자. 이 때는 선공이 무조건 진다.
# 돌 더미에 있는 돌이 2개인 경우 갈 수 있는 집합이 *0, *1 이다. 따라서 그런디 수는 2가 되고 이 때의 선공은 이긴다.
# 돌 더미의 있는 돌이 n개인 경우 갈 수 있는 집합은 *0, *1 ... *n-1이다. 따라서 그런디 수는 n이 되고 이 떄도 선공이 무조건 이긴다.
# 이제 이걸 기반으로 각 돌더미를 xor 하면 나오는 그런디 수에 따라 선공이 이길 수도 후공이 이길 수도 있다.
# 따라서 1개인 돌 더미가 하나도 없을 경우는 그냥 돌더미 개수를 xor해서 0이면 후공이, 아니면 선공이 이긴다.
# 1개인 돌더미만 존재할 경우는 돌더미의 개수가 홀수일 경우 후공이, 짝수일 경우 선공이 이긴다.
# 1개인 돌더미와 2개이상인 돌더미가 여러 개 섞여있을 경우는 좀 다르다.
# 1개인 돌더미가 홀수개 일 경우 돌더미의 개수를 xor 하여 0이 아니면 선공, 0이면 후공이 이긴다.
# 1개인 돌더미가 짝수개 일 경우 나머지 여러 개인 돌더미 중 하나를 1로 만들고
# xor 연산하여 0이 아니면 선공, 0이면 후공이 이긴다.

only_one_tower = 0
result = 0
if N == 1:
    if towers[0] == 1:
        print("cubelover")
    else:
        print("koosaga")
else:
    for num in towers:
        if num == 1:
            only_one_tower += 1

    if N == only_one_tower:
        if N % 2 == 1:
            print("cubelover")
        else:
            print("koosaga")
    elif only_one_tower == 0:
        for num in towers:
            result = result ^ num

        if result == 0:
            print("cubelover")
        else:
            print("koosaga")
    else:
        if only_one_tower % 2 == 0:
            for i in range(N):
                if towers[i] != 1:
                    towers[i] = 1
                    break
        for num in towers:
            result = result ^ num
        if result == 0:
            print("cubelover")
        else:
            print("koosaga")




```
