// @ocimatic should-fail=[st4]
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> A(n), B(n);
  for(int &a : A) cin >> a;
  for(int &b : B) cin >> b;

  bool fail = false;
  for(int i = n-1; i >= 0 && !fail; --i) {
    for(int j = min(i+k, n-1); j >= i && B[i] > 0; --j) {
      int delta = min(A[j], B[i]);
      B[i] -= delta;
      A[j] -= delta;
    }

    if(B[i] > 0) fail = true;
  }

  cout << (fail ? "NO" : "SI") << '\n';
  return 0;
}