#include <cassert>
#include <cstdio>
#include <vector>

bool sol(int k, std::vector<int> &a, std::vector<int> &b) {
  int n = a.size();
  int j = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    while (j >= i && b[i] > 0) {
      if (j - i <= k && a[j] > 0) {
        int s = std::min(b[i], a[j]);
        b[i] -= s;
        a[j] -= s;
      } else {
        --j;
      }
    }
    if (b[i] > 0)
      return false;
  }
  return true;
}

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

  if (sol(k, a, b)) {
    printf("SI\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
