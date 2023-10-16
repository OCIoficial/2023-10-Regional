import sys
import random

random.seed(sys.argv[1])
n, max_val = int(sys.argv[2]), int(sys.argv[3])
solution_index = random.randint(0, n - 1)

print(f"{n}")
for i in range(n):
    seeds = random.randint(0, max_val - 1)
    peers = random.randint(0, max_val)
    if i == solution_index:
        print(f"{max_val} {peers}")
    else:
        print(f"{seeds} {peers}")

