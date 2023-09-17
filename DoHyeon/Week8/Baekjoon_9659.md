```python
import sys
N = int(sys.stdin.readline())

# 마지막 돌을 가져간 사람이 이기기 때문에 홀수 턴에는 상근이가, 짝수 턴에는 창영이가 이김
# 이전 문제를 통해 규칙을 찾고 그걸 적용시키는 문제.

if N%2 == 1:
    print("SK")
else:
    print("CY")

    
```
