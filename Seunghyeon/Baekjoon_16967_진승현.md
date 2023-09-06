## 문제 요약

**배열 복원하기 ( 실버 3 )**

1. 크기 : H * W 인 배열 A

2. 두 정수 X, Y

3. 크기 : ( H + X ) * ( W + Y ) 인 배열 B
- 배열 A 를 아래로 X칸, 오른쪽으로 Y칸 이동시킨 배열을 겹쳐 만듬
- 수가 겹쳐지면 수가 합쳐짐

4. 배열 B 와 정수 X,Y 가 주어졌을 때, 배열 A 구하기

## 입력
1. H, W, X, Y
2. 배열 B
3. 항상 배열 A 는 존재함

## 출력
1. 배열 A 의 원소 출력하기
## 풀이
1. 배열 B 에서 x,y 이동한 만큼의 위치에서 이동하기 전 값 빼버리기

## 코드

### 정답 : 시간 168ms

```python
import sys

input = sys.stdin.readline

h,w,x,y = map(int, input().split())

b_list = []

for _ in range(h+x):
    b_list.append(list(map(int, input().split())))

for i in range(x, h+x):
    for j in range(y, w+y):
        b_list[i][j] = b_list[i][j] - b_list[i-x][j-y]


for i in range(h):
    for j in range(w):
        print(b_list[i][j], end=' ')
    print()

```
