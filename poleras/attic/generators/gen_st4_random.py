import random
import sys

random.seed(sys.argv[1])

n = random.randint(1, 10**6)
k = random.randint(0, 10**6)

LIM = 10**6

B = [random.randint(0, LIM) for _ in range(n)]
A = [random.randint(0, LIM) for _ in range(n)]

print(' '.join(str(x) for x in A))
print(' '.join(str(x) for x in B))