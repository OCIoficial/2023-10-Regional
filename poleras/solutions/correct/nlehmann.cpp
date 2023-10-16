#include <cassert>
#include <cstdio>
#include <vector>

bool sol(int k, std::vector<int> &a, const std::vector<int> &b) {
  int n = a.size();
  int j = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    assert(j - i <= k);
    while (a[i] < b[i]) {
      assert(j >= i);
      if (i == j) {
        return false;
      }

      if (a[j] > b[j]) {
        int s = std::min(b[i] - a[i], a[j] - b[j]);
        a[i] += s;
        a[j] -= s;
      } else {
        --j;
      }
    }
    if (j - i >= k) {
      --j;
    }
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
