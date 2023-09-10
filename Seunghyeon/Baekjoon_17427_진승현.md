## 문제 요약

**약수의 합 2 ( 실버 2 )**

1. A = B * C 일 때, C 는 A 의 약수

2. 자연수 A 의 약수의 합 : A 의 모든 약수를 더한 값 ( f(A) )
- x 보다 작거나 같은 모든 자연수 y의 f(y) 값을 더한 값 : g(x)

3. 자연수 n이 주어졌을 때, g(n) 구하기

## 입력
1. 자연수 n

## 출력
1. g(n) 구하기

## 풀이
1. 1부터 n 까지 차례대로 약수의 합 구하기
- 16 = 1 * 16, 2 * 8, 4 * 4
- 두개씩 더해주기
2. 다 더하기

## 코드

### 실패 : 시간 초과

```python
import sys

input = sys.stdin.readline

n = int(input())

ans = 0

for num in range(1, n+1):
    for i in range(1, int(num ** (1/2)) +1):
        if num % i == 0:
            ans += i

            if i < num // i:
                ans += (num // i)

print(ans)
```

### 성공 : 시간 200ms

```python
import sys

input = sys.stdin.readline

n = int(input())

ans = 0

for num in range(1, n+1):
    ans += (num * (n // num))

print(ans)
```