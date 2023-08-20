## 문제 요약

**문자열 폭발( 골드 4 )**


1. 폭발 문자열 폭발
- 그 문자는 사라짐
- 남은 문자열은 합쳐짐

2. 폭발 과정
- 문자열이 폭발 문자열을 포함하고 있는 경우, 모든 폭발 문자열이 폭발
- 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만듬

3. 남아있는 문자가 없는 경우, FRULA 출력

## 입력
1. 문자열
2. 폭발 문자열

## 출력
1. 폭발이 끝난 후 남은 문자열 출력

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 1048ms

```python
import sys

input = sys.stdin.readline

fn = input().strip()
sn = input().strip()

stack = []
for i in fn:
    # 문자열 담기
    stack.append(i)
    check_str = ''
    # 만약 현재 담은 문자와 끝값이 같을 경우
    if len(stack) >= len(sn):
        if stack[-1] == sn[-1]:
            check_str = stack[-1]
            check = -2
            while abs(check) != len(sn)+1:
                if stack[check] == sn[check]:
                    check_str = stack[check] + check_str
                check -= 1
        if check_str == sn:
            for i in range(len(sn)):
                stack.pop()

if len(stack) == 0:
    print('FRULA')
else:
    print(''.join(stack))
```

1. STACK 에 문자열 담기
2. STACK 의 끝값과 폭발 문자열의 끝값이 같을 경우, 폭발시킬 수 있는 문자열인지 체크
3. 정답 출력