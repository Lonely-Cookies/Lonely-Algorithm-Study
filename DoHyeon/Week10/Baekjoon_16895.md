```python
import sys
N = int(sys.stdin.readline())
towers = list(map(int, sys.stdin.readline().split()))

# 스프라그-그런디 정리를 안다면 쉽게 풀 수 있는 문제
# 그런디 수는 가져갈 수 있는 돌의 개수에 제한이 없으므로 타워당 남은 돌의 수
# 각 타워끼리 xor 연산을 하여 나온 그런디 수가 0이면 후공이, 아니면 선공이 이긴다.
# 이 문제는 게임을 이기기 위해 첫 턴에 선공이 할 수 있는 방법의 수를 나타낸 것으로, 각 타워에서 돌을 최소 1개, 최대 타워에 있는 돌 수만큼 빼서 님 합이 0이 나오는지 검사해봐야 한다.

result = 0;

for i in range(N):
    for j in range(1, towers[i]+1):
        xor_sum = 0
        val = towers[i]-j
        for k in range(N):
            if k == i:
                xor_sum = xor_sum ^ val
            else:
                xor_sum = xor_sum ^ towers[k]
        if xor_sum == 0:
            result += 1
print(result)
```
