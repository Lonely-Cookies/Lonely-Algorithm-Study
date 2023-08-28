## 문자열 나누기
![|800](https://i.imgur.com/BVJELqf.png)

```python
n = int(input())
st = input()
# 최적화된 코드

# 모든 부분 문자열 찾기 (중복 제외, 길이가 n-2 이하인 부분 문자열만 포함)
all_substrings = set()
for i in range(n):
  for j in range(i + 1, n + 1):
    if len(st[i:j]) > n - 2:
      continue
    all_substrings.add(st[i:j])
all_substrings = sorted(list(all_substrings))

# 부분 문자열 인덱스 캐싱
substring_index_mapping = {substring: idx for idx, substring in enumerate(all_substrings)}

# 최대 점수를 저장할 변수 초기화
max_score = 0

# 첫 번째 분할 지점을 설정
for first_split in range(1, n - 1):  # n-1까지 가능
  # 두 번째 분할 지점을 설정
  for second_split in range(first_split + 1, n):  # n까지 가능
    # 세 부분 문자열로 나누기
    part1 = st[:first_split]
    part2 = st[first_split:second_split]
    part3 = st[second_split:]

    # 각 부분 문자열의 점수 계산
    score_part1 = substring_index_mapping[part1] + 1
    score_part2 = substring_index_mapping[part2] + 1
    score_part3 = substring_index_mapping[part3] + 1

    # 총 점수 계산
    total_score = score_part1 + score_part2 + score_part3

    # 최대 점수 업데이트
    max_score = max(max_score, total_score)

print(max_score)
```
모든 부분 문자열을 찾는다. 부분 문자열의 특징은 중복이 없고, 연속적이며 길이가 1이상 n-2이하인 문자열이다

문자열을 3토막 내기 때문에, O(n^2)의 시간 복잡도로 문자열을 쪼갤 수 있다
이 후 반복적으로 최댓 값을 계산하면 된다
