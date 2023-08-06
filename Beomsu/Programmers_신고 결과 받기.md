## 풀이
한 유저가 중복해서 같은 유저를 계속 신고할 수 없다
k 번 이상 신고된 유저는 정지되고, 그 결과를 모든 유저에게 정지 사실을 메일로 발송한다
즉 유저는 신고한 유저의 정보를 가지고 있어야 하고, 유저마다 신고된 횟수도 기록되어야 한다.
최종적으로 answer에는 각 유저들이 받은 처리 메일만 기록하면 된다.

풀이 방법은 신고 받은 유저 딕셔너리를 만들고, 해당 유저를 신고한 유저들을 한 명씩 넣는다
그리고 연산 끝에 한 번에 정지된 이용자를 정리한다
## 코드 
```python
score = {}
result = {}
def solution(id_list, report, k):
    answer = []
    for id in id_list:
        score[id] =[]
        result[id]=0
    for rp in report:
        gUser,bUser = rp.split()
        score[bUser].append(gUser)
        score[bUser] = list(set(score[bUser]))
    for sc in score.keys():
        if len(score[sc])>=k:
            for s in score[sc]:
                result[s]+=1
    answer = list(result.values())
    return answer
```