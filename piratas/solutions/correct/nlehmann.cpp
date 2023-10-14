#include <climits>
#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int maxSeeds = -1, minPeers = INT_MAX, bestIndex = -1;
  for (int i = 0; i < N; ++i) {
    int s, p;
    scanf("%d %d", &s, &p);

    if (s > maxSeeds) {
      maxSeeds = s;
      minPeers = p;
      bestIndex = i;
    } else if (s == maxSeeds && p < minPeers) {
      minPeers = p;
      bestIndex = i;
    }
  }
  printf("%d\n", bestIndex + 1);
}
