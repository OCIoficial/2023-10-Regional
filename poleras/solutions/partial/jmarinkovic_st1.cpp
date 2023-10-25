// @ocimatic should-pass=[st1]
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k; 
  cin >> n >> k;

  if(k != 0) {
    cout << "NO\n";
    return 0;
  }

  vector<int> A(n), B(n);
  for(int &a : A) cin >> a;
  for(int &b : B) cin >> b;

  bool fail = false;
  for(int i = 0; i < n && !fail; ++i) 
    if(A[i] < B[i]) {
      fail = true;
    }

  cout << (fail ? "NO" : "SI") << '\n';
  return 0;
}