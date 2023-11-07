import random
import sys

random.seed(sys.argv[1])
n = int(sys.argv[2])
k = 1

print(n, k)

LIM = 10**5

B = [random.randint(0, LIM) for _ in range(n)]
A = [B[i] for i in range(n)]

for i in range(n-2, -1, -1):
  delta = random.randint(0, A[i])
  A[i] -= delta 
  A[i+1] += delta

print(' '.join(str(x) for x in A))
print(' '.join(str(x) for x in B))