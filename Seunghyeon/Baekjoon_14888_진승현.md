## 문제 요약

**연산자 끼워넣기**
1. N 개의 수로 이루어진 수열

2. 수와 수 사이에 끼워넣을 수 있는 N-1 개의 연산자
- +, -, *, /

3. 수와 수 사이에 연산자를 하나씩 넣어서 수식을 만들 수 있음
- 주어진 수의 순서를 바꾸면 안됨

4. 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행함
- 나눗셈 : 정수 나눗셈, 몫만 취함
- 음수를 양수로 나눌 때 : 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같음

5. N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램 작성하기



## 입력
1. 수의 개수 N

2. N_LIST

3. +, -, *, / 의 갯수

## 출력
1. 만들 수 있는 식의 결과의 최댓값, 최솟값 출력하기

## 풀이
1. 백트래킹

## 코드

### ( 정답 ) : 시간 80ms

```python
import sys
maxNum = -1e10
minNum = 1e10

def back(depth, ans):
    global maxNum, minNum

    if depth == n:
        maxNum = max(maxNum, ans)
        minNum = min(minNum, ans)
    else:
        for i in range(4):
            if m_list[i] > 0:
                if i == 0:
                    m_list[i] -= 1
                    back(depth + 1, ans + n_list[depth])
                    m_list[i] += 1
                elif i == 1:
                    m_list[i] -= 1
                    back(depth + 1, ans - n_list[depth])
                    m_list[i] += 1
                elif i == 2:
                    m_list[i] -= 1
                    back(depth + 1, ans * n_list[depth])
                    m_list[i] += 1
                elif i == 3:
                    m_list[i] -= 1
                    back(depth + 1, int(ans / n_list[depth]))
                    m_list[i] += 1



input = sys.stdin.readline

n = int(input())
n_list = list(map(int, input().split()))

# 연산자 리스트 입력받기
m_list = list(map(int, input().split()))

back(1, n_list[0])

print(maxNum)
print(minNum)

```