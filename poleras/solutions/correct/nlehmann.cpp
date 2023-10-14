#include <cstdio>
#include <vector>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  int j = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    while (a[i] < b[i] && i < j) {
      if (a[j] > b[j] && j - i <= k) {
        int s = std::min(b[i] - a[i], a[j] - b[j]);
        a[i] += s;
        a[j] -= s;
      } else {
        --j;
      }
    }
    if (a[i] < b[i]) {
      printf("NO\n");
      return 0;
    }
  }

  printf("SI\n");
  return 0;
}
