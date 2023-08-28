## 문제 요약

**게임 ( 실버 3 )**

1. 모든 게임에서 지지 않음

2. 게임 기록을 삭제할 수 없음
- 게임 횟수 : X
- 이긴 게임 : Y
- 게임 승률 : Z , 소수점은 버림

3. X, Y 가 주어졌을 때, 형택이가 게임을 최소 몇 번 더해야 Z 가 변하는지 구하는 프로그램 작성하기

## 입력
1. 각 줄에 정수 X, Y

## 출력
1. Z 가 변하려면 게임을 최소 몇 판 더 해야하는지 출력하기

2. 만약 Z 가 절대 변하지 않는다면 -1 출력

## 풀이
1. 이분 탐색
- 승률 체크

## 코드

### 내가 푼 코드 ( 정답 ) : 시간 44ms

```python
import sys

input = sys.stdin.readline

x, y = map(int, input().split())

# 현재 승률
z = y * 100 // x

# 바뀔 수 없는 승률일 경우
if z >= 99:
    print(-1)
else:
    start = 1
    end = 1000000000
    ans = 0
    while start <= end:
        mid = (start + end) // 2
        # 승률이 z 보다 클 경우
        if (y+mid) * 100 // (x + mid) > z:
            end = mid - 1
            ans = mid
        else:
            start = mid + 1
    print(ans)


```

