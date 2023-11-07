import random
import sys

random.seed(sys.argv[1])
n, k = int(sys.argv[2]), int(sys.argv[3])

print(n, k)

LIM = 10**5

B = [random.randint(20, LIM) for _ in range(n)]
A = [B[i] + random.randint(0, 5) for i in range(n)]

idx = random.randint(0, n-2)
total = random.randint(0, B[idx]-1)

A[idx] = total
for j in range(idx+1, min(idx+k, n-1)):
  A[j] = 0

for i in range(n-2, -1, -1):
  for j in range(min(i+k, n-1), i, -1):
    delta = random.randint(0, A[i])
    A[i] -= delta 
    A[j] += delta

print(' '.join(str(x) for x in A))
print(' '.join(str(x) for x in B))