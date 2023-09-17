```python
import sys
N = int(sys.stdin.readline())
# 역시 이전 문제들을 통해 규칙을 찾아 적용시키는 문제.
# dp는 메모리가 부족해서 안된다.
if N % 7 == 2 or N % 7==0:
    print("CY")
else:
    print("SK")
```
