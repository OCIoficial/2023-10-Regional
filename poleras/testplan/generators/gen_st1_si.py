import random
import sys

random.seed(sys.argv[1])
n = int(sys.argv[2])
k = 0

print(n, k)

LIM = 10**3

B = [random.randint(0, LIM) for _ in range(n)]
A = [B[i] + random.randint(0, LIM) for i in range(n)]

print(' '.join(str(x) for x in A))
print(' '.join(str(x) for x in B))