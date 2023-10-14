#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
  int p, n, k;
  scanf("%d%d%d", &p, &n, &k);

  std::vector<int> fries(p);
  for (int i = 0; i < p; ++i) {
    scanf("%d", &fries[i]);
  }
  std::sort(fries.rbegin(), fries.rend());

  int sum = 0;
  for (int i = k - 1; i < p; i += n) {
    sum += fries[i];
  }
  //   for (int i = 0; i < p; ++i) {
  //     if (i % n == k - 1) {
  //       sum += fries[i];
  //     }
  //   }
  printf("%d\n", sum);
}
