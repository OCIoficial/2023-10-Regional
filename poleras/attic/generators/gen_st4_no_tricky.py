import random
import sys

random.seed(sys.argv[1])
n = int(sys.argv[2])

k = random.randint(0, n)

print(n, k)

idx1 = random.randint(1, n-1)
idx2 = random.randint(0, idx1-1)

A = [0 for _ in range(n)]
A[idx2] = 1

B = [0 for _ in range(n)]
B[idx1] = 1

print(' '.join(str(x) for x in A))
print(' '.join(str(x) for x in B))