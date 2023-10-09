```python
import sys

T = int(sys.stdin.readline())


def dist(x1, y1, x2, y2):
    return (x1-x2)**2 + (y1-y2)**2


def answer(x1, y1, r1, x2, y2, r2):
    if x1 == x2 and y1 == y2:
        if r1 == r2:
            return -1
        else:
            return 0
    big_r = max(r1, r2)
    small_r = min(r1, r2)
    distance = dist(x1, y1, x2, y2)
    if distance <= big_r**2:
        if (big_r - small_r)**2 == distance:
            return 1
        elif (big_r - small_r)**2 < distance:
            return 2
        else:
            return 0
    if distance > big_r**2:
        if (big_r + small_r)**2 == distance:
            return 1
        elif (big_r + small_r)**2 > distance:
            return 2
        else:
            return 0


for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split())
    result = answer(x1, y1, r1, x2, y2, r2)
    print(result)
```
