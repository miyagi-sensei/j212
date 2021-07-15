import random

MAXN = 5
colors = ['R', 'G', 'B']
N = random.randint(1, MAXN)
P = random.randint(1, N*(N+1) // 2)
print(N, P)
for _ in range(P):
    c = random.randint(0,2)
    l = random.randint(1,N)
    print(colors[c], l)
Q = N * (N+1) // 2
print(Q)
# prints all tiles of the entire wall
for i in range(1, N+1):
    for j in range(1, i+1):
        print(i, j)
