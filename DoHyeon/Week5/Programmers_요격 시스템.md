```python
def solution(targets):
    answer = 0
    targets.sort(key = lambda x: (x[1], x[0])) # 미사일의 끝나는 지점을 기준으로 정렬
    # 만약 끝나는 지점이 다음 폭격 미사일의 시작 지점과 같거나 더 크다면 해당 지점을 요격할 때는
    # 다른 요격 미사일이 필요
    std = 0
    print(targets)
    for target in targets:
        if target[0] >= std:
            print(std)
            answer += 1
            std = target[1]
    return answer
```
