```python
import sys
N = int(sys.stdin.readline())
towers = list(map(int, sys.stdin.readline().split()))
# 님게임 1보다 쉽다....
# 스프라그-그런디 정리를 안다면 쉽게 풀 수 있는 문제
# 그런디 수는 가져갈 수 있는 돌의 개수에 제한이 없으므로 타워당 남은 돌의 수
# 각 타워끼리 xor 연산을 하여 나온 그런디 수가 0이면 후공이, 아니면 선공이 이긴다.
result = 0;
for num in towers:
    result = result ^ num

if result == 0:
    print("cubelover")
else:
    print("koosaga")
```
