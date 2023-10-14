#include <cstdio>
#include <vector>

int binsearch(const std::vector<int> &arr, int x, int k) {
  int l = 0;
  int r = arr.size();
  while (l < r) {
    int m = l + (r - l) / 2;
    if (arr[m] * x < k) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

int main() {
  int n, q, kmin, kmax;
  scanf("%d%d%d%d", &n, &q, &kmin, &kmax);

  std::vector<int> rates(n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &rates[i]);
  }

  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    int imin = binsearch(rates, x, kmin);
    int imax = binsearch(rates, x, kmax + 1);
    printf("%d\n", imax - imin);
  }
}
