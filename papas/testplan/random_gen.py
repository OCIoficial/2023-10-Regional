
import random
import sys

# args: [random gen seed] [p] [n] [k] [min size] [max size]
random.seed(sys.argv[1])
p, n, k = int(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4])
min_size, max_size = int(sys.argv[5]), int(sys.argv[6])

print(p, n, k)
vals = [random.randint(min_size, max_size) for _ in range(p)]
print(*vals)