```python
import sys
import math


def diff(m, n):
    if m == n:
        return 0
    else:
        return 1


a = str(sys.stdin.readline().strip())
b = str(sys.stdin.readline().strip())
la = len(a)
lb = len(b)

vertical_index = 0

dp_sliced = [[0 for _ in range(lb+1)] for _ in range(2)]
dp_vertical =[0] * (la + 1)


modify_list_byte = [bytearray(math.ceil((lb+1)/4)) for _ in range(la + 1)]

COPY = 0b00
ADD = 0b01
DELETE = 0b10
MODIFY = 0b11


for i in range(1, la + 1):
    dp_vertical[i] = i
    modify_list_byte[i][0] += DELETE

for j in range(1, lb + 1):
    byte_index = j // 4
    bit_shift = (j % 4)*2
    dp_sliced[0][j] = j
    modify_list_byte[0][byte_index] += ADD << bit_shift

for i in range(1, la + 1):
    next_index = i - vertical_index
    for j in range(1, lb + 1):
        if j-1 == 0:
            dp_sliced[next_index][0] = dp_vertical[i]
        byte_index = j // 4
        bit_shift = (j % 4) * 2
        val = diff(a[i-1], b[j-1])

        dp_sliced[next_index][j] = min(dp_sliced[next_index-1][j] + 1, dp_sliced[next_index][j-1] + 1, dp_sliced[next_index-1][j-1] + val)

        if dp_sliced[next_index][j] == dp_sliced[next_index-1][j-1] + val and val == 0:
            modify_list_byte[i][byte_index] += COPY << bit_shift

        elif dp_sliced[next_index][j] == dp_sliced[next_index-1][j] + 1:
            modify_list_byte[i][byte_index] += DELETE << bit_shift

        elif dp_sliced[next_index][j] == dp_sliced[next_index][j-1] + 1:
            modify_list_byte[i][byte_index] += ADD << bit_shift

        elif dp_sliced[next_index][j] == dp_sliced[next_index-1][j-1] + val and val == 1:
            modify_list_byte[i][byte_index] += MODIFY << bit_shift

    dp_sliced[next_index - 1] = dp_sliced[next_index].copy()
    dp_sliced[next_index] = [0] * (lb + 1)

    vertical_index += 1

n = la
m = lb
print_list = []
counter = 0
while True:
    if n == 0 and m == 0:
        break
    byte_index = m // 4
    bit_shift = (m % 4) * 2
    val = 0b11 << bit_shift

    move = (modify_list_byte[n][byte_index] & val) >> bit_shift

    if move == COPY:
        print_list.append(("c", a[n - 1]))
        m -= 1
        n -= 1
    elif move == DELETE:
        print_list.append(("d", a[n - 1]))
        n -= 1
    elif move == ADD:
        print_list.append(("a", b[m - 1]))
        m -= 1
    elif move == MODIFY:
        print_list.append(("m", b[m - 1]))
        m -= 1
        n -= 1

    counter += 1


for a, b in print_list[::-1]:
    print(a, b)


# before = str(sys.stdin.readline().strip())
# after = str(sys.stdin.readline().strip())
#
# vertical_index = 0
#
# dp_sliced = [([0] * (len(before) + 1)) for _ in range(2)]
# dp_vertical = [0] * (len(after) + 1)
#
# modify_list_sliced = [[[] for _ in range(len(before) + 1)] for _ in range(2)]
# modify_list_vertical = [[] for _ in range(len(after) + 1)]
#
# modify_list_byte = [bytearray(math.ceil((len(before)+1)/4)) for _ in range(len(after) + 1)]
#
# COPY = 0b00
# ADD = 0b01
# DELETE = 0b10
# MODIFY = 0b11
#
# # 00은 변경 없음으로 지정, 01은 add, 10은 delete, 11은 modify로 지정
# for j in range(1, len(before) + 1):
#     byte_index = j // 4
#     bit_shift = (j % 4)*2
#     dp_sliced[0][j] = j
#     modify_list_sliced[0][j] = modify_list_sliced[0][j-1] + [("d", before[j-1])]
#     modify_list_byte[0][byte_index] += DELETE << bit_shift
#
# for i in range(1, len(after) + 1):
#     dp_vertical[i] = i
#     modify_list_vertical[i] = modify_list_vertical[i-1] + [("a", after[i-1])]
#     modify_list_byte[i][0] += ADD
#
#
# for i in range(1, len(after) + 1):
#     next_index = i - vertical_index
#
#     for j in range(1, len(before) + 1):
#         byte_index = j // 4
#         bit_shift = (j % 4)*2
#         if j-1 == 0:
#             dp_sliced[next_index - 1][j-1] = dp_vertical[i - 1]
#             modify_list_sliced[next_index - 1][j - 1] = modify_list_vertical[i - 1]
#
#         if after[i - 1] == before[j - 1]:
#             dp_sliced[next_index][j] = dp_sliced[next_index - 1][j - 1]
#             modify_list_sliced[next_index][j] = modify_list_sliced[next_index - 1][j - 1] + [("c", before[j - 1])]
#             modify_list_byte[i][byte_index] += COPY << bit_shift
#             continue
#         else:
#             dp_sliced[next_index][j] = min(dp_sliced[next_index - 1][j] + 1, dp_sliced[next_index][j - 1] + 1, dp_sliced[next_index - 1][j - 1] + 1)
#
#         if dp_sliced[next_index - 1][j - 1] + 1 == dp_sliced[next_index][j]:
#             modify_list_sliced[next_index][j] = modify_list_sliced[next_index - 1][j - 1] + [("m", after[i - 1])]
#             modify_list_byte[i][byte_index] += MODIFY << bit_shift
#
#         elif dp_sliced[next_index - 1][j] + 1 == dp_sliced[next_index][j]:
#             modify_list_sliced[next_index][j] = modify_list_sliced[next_index - 1][j] + [("a", after[i - 1])]
#             modify_list_byte[i][byte_index] += ADD << bit_shift
#
#         elif dp_sliced[next_index][j - 1] + 1 == dp_sliced[next_index][j]:
#             modify_list_sliced[next_index][j] = modify_list_sliced[next_index][j - 1] + [("d", before[j - 1])]
#             modify_list_byte[i][byte_index] += DELETE << bit_shift
#
#     dp_sliced[next_index - 1] = dp_sliced[next_index].copy()
#     dp_sliced[next_index] = [0] * (len(before) + 1)
#
#     modify_list_sliced[next_index - 1] = modify_list_sliced[next_index].copy()
#     modify_list_sliced[next_index] = [[] for _ in range(len(before) + 1)]
#
#     vertical_index += 1
#
#
# for a, b in modify_list_sliced[0][len(before)]:
#     print(a, b)
#
# print("------------------------------------------")
#
# n = len(after)
# m = len(before)

```
