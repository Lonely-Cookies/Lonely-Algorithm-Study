```python
import sys

AB = list(str(sys.stdin.readline().strip()))

result = 0

if len(AB) == 2:
    A = int(AB[0])
    B = int(AB[1])
    result = A+B
elif len(AB) == 3:
    if AB[1] == '0':
        A = int(''.join(AB[:2]))
        B = int(AB[2])
        result = A+B
    else:
        A = int(AB[0])
        B = int(''.join(AB[1:]))
        result = A+B
else:
    A = int(''.join(AB[:2]))
    B = int(''.join(AB[2:]))
    result = A+B

print(result)
```
