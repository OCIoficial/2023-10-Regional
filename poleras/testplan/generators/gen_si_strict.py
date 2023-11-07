import random
import sys

random.seed(sys.argv[1])
n, k = int(sys.argv[2]), int(sys.argv[3])

print(n, k)

LIM = 10**5 // 2

B = [random.randint(0, LIM) for _ in range(n)]
A = [B[i] for i in range(n)]

for i in range(n-2, -1, -1):
  for j in range(min(i+k, n-1), i, -1):
    delta = random.randint(0, A[i])
    A[i] -= delta 
    A[j] += delta

print(' '.join(str(x) for x in A))
print(' '.join(str(x) for x in B))