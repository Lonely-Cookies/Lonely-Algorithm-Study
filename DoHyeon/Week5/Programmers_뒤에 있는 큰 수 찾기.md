```python
# n^2의 알고리즘으로 풀고 싶지 않은데...
# 최적화는 해볼 수 있지 않을까
# 자료 구조를 써보자.
def solution(numbers):
    answer = [-1] * len(numbers)
    stack = []
    for i in range(len(numbers)):
        while stack and numbers[stack[-1]] < numbers[i]:
            answer[stack.pop()] = numbers[i]
        stack.append(i)
        print(stack)
    return answer
```
