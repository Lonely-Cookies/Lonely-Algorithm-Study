```python
import sys

N = int(sys.stdin.readline())
# N 은 50보다 작으므로 하드 코딩을 해도 되는 문제이다..??
# 각 값들은 -1000이상 1000이하이다.
zero_list = list()
one_list = list()
negative_list = list()
positive_list = list()

for _ in range(N):
    val = int(sys.stdin.readline())

    if val < 0:
        negative_list.append(val)
    elif val > 1:
        positive_list.append(val)
    elif val == 1:
        one_list.append(val)
    elif val == 0:
        zero_list.append(val)

    negative_list.sort(reverse=True)
    positive_list.sort()

result = 0

# 자신과 두번 씩만 더해져도(최소 2 * 자기자신) 그냥 두 수를 더한 것 보다 낫다.
while len(positive_list) > 1:
    val_1 = positive_list.pop()
    val_2 = positive_list.pop()
    result += val_1*val_2

# 음수 끼리는 무조건 곱해서 양수로 만드는게 좋다.
while len(negative_list) > 1:
    val_1 = negative_list.pop()
    val_2 = negative_list.pop()
    result += val_1*val_2

while len(negative_list) > 0 and len(zero_list) > 0:
    negative_list.pop()
    zero_list.pop()

result += sum(one_list)
result += sum(positive_list)
result += sum(negative_list)

print(result)

```
