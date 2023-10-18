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
  int j = n-1;

  for(int i = n-1; i >= 0 && !fail; --i) {

    j = min(j, i+k);
    while(j >= i && B[i] > 0) {
      int delta = min(B[i], A[j]);
      B[i] -= delta;
      A[j] -= delta;

      if(A[j] == 0) --j;
    }

    if(B[i] > 0) fail = true;
  }

  cout << (fail ? "NO" : "SI") << '\n';
  return 0;
}