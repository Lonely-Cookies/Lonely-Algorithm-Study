## 문제 요약

**곱셈 ( 실버 1 )**

1. (A^B) % C 구하기

## 입력
1. A, B, C

## 출력
1. (A^B) % C 출력하기

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 40ms

```python
def power(a,b,c):
    if b == 1:
        return a % c
    elif b == 2:
        return (a ** 2) % c
    else:
        # 홀수일 때
        if b % 2:
            return ((power(a, b//2, c) ** 2) * a) % c
        # 짝수일 때
        else:
            return ((power(a,b//2,c)**2)) % c

a,b,c = map(int, input().split())

print(power(a,b,c))

```

1. 재귀함수를 사용해서 최대한 값이 큰 계산을 덜하도록 분할해주었음

### 더 빠른 코드 : 시간 32ms

```python
print(pow(*map(int,input().split())))
```

차이점
- pow 함수 사용
