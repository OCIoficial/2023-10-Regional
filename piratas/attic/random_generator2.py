
import random
import sys

# args: [random gen seed] [n] [min seeds] [max seeds] [min peers] [max peers]
random.seed(sys.argv[1])
n = int(sys.argv[2])
min_sval, max_sval = int(sys.argv[3]), int(sys.argv[4])
min_pval, max_pval = int(sys.argv[5]), int(sys.argv[6])

torrents = []
for i in range(n):
    seeds = random.randint(min_sval, max_sval)
    peers = random.randint(min_pval, max_pval)
    torrents.append((seeds, peers, i))

# Sort to get best values first
sorted_torrents = sorted(torrents, key=lambda k: (-k[0], k[1], -k[2]))
best_seeds = sorted_torrents[0][0]
best_peers = sorted_torrents[0][1]
# Leave only one copy of the overall best
for t in sorted_torrents[1:]:
    if t[0] == best_seeds and t[1] == best_peers:
        del torrents[t[2]]
    else:
        break
assert len(torrents) > 0, "N became zero after removing duplicated best results"
print(len(torrents))
for t in torrents:
     print(f"{t[0]} {t[1]}")
