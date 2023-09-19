## 문제 요약

**비밀번호 발음하기**
1. 발음이 가능한 패스워드 만들기

2. 조건
- 모음 ( a, e, i, o, u ) 하나를 반드시 포함
- 모음이 3개 혹은 자음이 3개 연속으로 오면 안됨
- 같은 글자가 연속으로 오면 안됨
- ee, oo 만 허용



## 입력
1. 여러개의 테스트 케이스
- 마지막 테스트 케이스 : end
- 패스워드는 대문자를 포함하지 않음


## 출력
1. 품질 평가하기

## 풀이
1. 조건분기

## 코드

### ( 정답 ) : 시간 44ms

```python
import sys

input = sys.stdin.readline

while True:
    s = input().strip()

    if s == 'end':
        break

    # 모음을 체크하는 카운트
    cnt = 0

    # 모음 혹은 자음이 연속으로 오는지 체크하는 카운트
    cnt1, cnt2 = 0, 0

    # 같은 글자가 연속으로 두번오는지 체크
    stack = ''

    check = True

    for i in s:
        # 현재 글자가 모음일 경우
        if i in ['a', 'e', 'i', 'o', 'u']:
            cnt += 1
            cnt1 += 1
            cnt2 = 0
        else:
            cnt2 += 1
            cnt1 = 0
        # 자음 혹은 모음이 3개 연속으로 오면 안됨
        if cnt1 >= 3 or cnt2 >= 3:
            print(f'<{s}> is not acceptable.')
            check = False
            break
        # 같은 글자가 연속으로 오는 경우
        if len(stack) > 0:
            if stack[-1] == i:
                if i == 'e' or i == 'o':
                    stack = stack + i
                else:
                    print(f'<{s}> is not acceptable.')
                    check = False
                    break
            # 다른 문자가 올 경우
            else:
                stack = stack + i
        else:
            stack = stack + i

    if check:
        if cnt > 0:
            print(f'<{s}> is acceptable.')
        else:
            print(f'<{s}> is not acceptable.')


```