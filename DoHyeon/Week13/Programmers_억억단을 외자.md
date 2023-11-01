```python
  # 프로그래머스 파이썬 실행시간 너무 빡빡하다....
  # 마지막 케이스에서 서버 상태 좋아야 통과한다.
  def solution(e, starts):
    counter_list =[1]*(e+1)
    starts_dict = {}
    sorted_starts = sorted(starts)
    for div in range(2, e + 1):
        for jump in range(div, e + 1, div):
            counter_list[jump] += 1
    
    memo = 0
    
    for i in range(len(sorted_starts)):
        if memo == 0:
            max_index = counter_list[sorted_starts[i]:].index(max(counter_list[sorted_starts[i]:])) + sorted_starts[i]
            memo = max_index
            starts_dict[sorted_starts[i]] = memo
        else:
            if sorted_starts[i] <= memo:
                starts_dict[sorted_starts[i]] = memo
            else:
                max_index = counter_list[sorted_starts[i]:].index(max(counter_list[sorted_starts[i]:])) + sorted_starts[i]
                memo = max_index
                starts_dict[sorted_starts[i]] = memo

    return [starts_dict.get(start) for start in starts]
```
