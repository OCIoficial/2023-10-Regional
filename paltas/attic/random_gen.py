import random
import sys

# args: [random gen seed] [n] [q] [kmin] [kmax] [r_i max] [t max]
random.seed(sys.argv[1])
n, q = int(sys.argv[2]), int(sys.argv[3])
kmin, kmax = int(sys.argv[4]), int(sys.argv[5])
rmax, tmax = int(sys.argv[6]), int(sys.argv[7])

print(n, q, kmin, kmax)
print(*[random.randint(1, rmax) for _ in range(n)])
print(*[random.randint(0, tmax) for _ in range(q)], sep='\n')