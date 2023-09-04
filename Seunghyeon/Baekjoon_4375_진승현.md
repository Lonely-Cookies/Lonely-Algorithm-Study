## 문제 요약

**1 ( 실버 3 )**

1. 2와 5로 나누어 떨어지지 않는 정수 n

2. 각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램 작성하기

3 -> 111
7 -> 111111
9901 -> 111111111111

자릿수 맞추기

## 입력
1. 여러개의 테스트 케이스

## 출력
1. 각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수 출력하기

## 코드

### 정답 : 시간 160ms

```python
import sys

input = sys.stdin.readline

while True:
    try:
        s = int(input())
        # 자릿수
        i = 0
        ans = 0
        while True:
            i += 1
            ans = 10 * ans + 1

            if ans % s == 0:
                print(i)
                break
    except:
        break

```
