import sys

t = int(sys.stdin.readline())
result = []
for i in range(t):
    H,W,N = map(int,sys.stdin.readline().split())
    floor = H if N%H ==0 else N%H
    side = N//H  if N%H==0 else N//H +1

    sideText = "0" + str(side) if side < 10 else str(side)

    result.append(f"{floor}{sideText}")
for r in result:
    print(r)