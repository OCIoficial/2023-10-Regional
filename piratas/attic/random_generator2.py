
import random
import sys

# args: [random gen seed] [n] [min seeds] [max seeds] [min peers] [max peers]
random.seed(sys.argv[1])
n = int(sys.argv[2])
min_sval, max_sval = int(sys.argv[3]), int(sys.argv[4])
min_pval, max_pval = int(sys.argv[5]), int(sys.argv[6])

print(n)
for i in range(n):
    seeds = random.randint(min_sval, max_sval)
    peers = random.randint(min_pval, max_pval)
    print(seeds, peers)
