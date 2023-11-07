N = 10**6
K = 10**6

b = [10**9]

while len(b) != N:
    b.append(b[-1]-1000)

import copy
a = copy.copy(b)

a.reverse()

print(N, K)
print(*a)
print(*b)

