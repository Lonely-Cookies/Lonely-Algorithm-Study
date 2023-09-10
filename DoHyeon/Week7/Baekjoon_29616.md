```python
import sys
import math # 파이썬엔 gcd 라이브러리가 있다.....
# 간단한 문제인데 직접만든 gcd함수에 문제가 있었나보다.
N, P = map(int, sys.stdin.readline().split())

before_list = list(map(int, sys.stdin.readline().split()))
after_list = list(map(int, sys.stdin.readline().split()))

gcd_before = math.gcd(*before_list)
before_list = list(map(lambda x: x // gcd_before, before_list))

gcd_after = math.gcd(*after_list)
after_list = list(map(lambda x: x // gcd_after, after_list))
mul_list = []
for i in range(N):
    if after_list[i] != 0:
        val = int(math.ceil(before_list[i]/after_list[i]))
        if val != 0:
            mul_list.append(val)
if mul_list:
    after_list = list(map(lambda x: x*max(mul_list), after_list))

print(str(sum(before_list)) + " " + str(sum(after_list)))
```
