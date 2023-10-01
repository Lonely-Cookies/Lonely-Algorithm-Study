```python
import sys

b1, b2, b3 = map(int, sys.stdin.readline().split())

# 총 2개의 개별적인 게임이라 가정하자.
# 두 개의 게임 모두에서 선공이 이긴다(1이라고 하자)면 선공이 이긴다.
# 하나의 게임에서 선공이 진다면 선공에게 선택지가 있으므로 지는 게임을 선공이 마무리 후 이기는 게임을 할 수 있다. 따라서 선공이 이긴다.
# 두 게임 모두 선공이 진다면 선공이 무조건 진다. 이를 기반으로 코드를 짜보자. -> 틀렸다. 내가 생각한게 틀렸나..?
# -> 턴 수에 따라 결과가 달라질 수 있다. --> 그런디 수를 구해보아야 한다.... -> 맞았다


def mex(grundy, num):
    val = num
    if num == b1 or num == b2 or num == b3:
        return

    for i in range(len(grundy[num])):
        grundy[num][i] = grundy[grundy[num][i]][0]
    # print("grundy["+str(num)+"]->" + str(grundy[num]))
    if 0 not in grundy[num]:
        val = 0
        grundy[num] = [val]
        return
    for i in range(b1, b3+1):
        if i not in grundy[num]:
            val = i
            break
    grundy[num] = [val]


for _ in range(5):
    k1, k2 = map(int, sys.stdin.readline().split())
    length = max(k1, k2)
    grundy = [[] for _ in range(length+1)]

    for i in range(0, b1):
        grundy[i].append(0)
    grundy[b1].append(b1)
    grundy[b2].append(b2)
    grundy[b3].append(b3)

    for i in range(b1+1, length+1):
        if i > b3:
            grundy[i].append(i-b1)
            grundy[i].append(i-b2)
            grundy[i].append(i-b3)
        elif b3 > i > b2:
            grundy[i].append(i-b1)
            grundy[i].append(i-b2)
        elif b2 > i > b1:
            grundy[i].append(i-b1)
    # print(grundy)
    for i in range(b1+1, length+1):
        mex(grundy, i)
    # print(grundy)
    if grundy[k1][0] ^ grundy[k2][0] == 0:
        print("B")
    else:
        print("A")

```
<img width="729" alt="image" src="https://github.com/latteisacat/Lonely-Algorithm-Study/assets/114455070/86998205-d093-4d4d-9840-d10b7994cb88">

