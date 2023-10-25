// @ocimatic should-pass=[st2]
#include<bits/stdc++.h>

using namespace std;

int main() {

  int n, k;
	cin >> n >> k;
  vector<int> A(n), B(n);

  for(int i = 0; i < n; i++)
    cin >> A[i];

  for(int i = 0; i < n; i++)
    cin >> B[i];

  bool possible = true;

  for(int i = n-1; i >= 0; i--)
  {
    for(int j = min(n-1, i+1); j >= i; j--)
    {
      int delta = min(B[i], A[j]);
      B[i] -= delta;
      A[j] -= delta;
    }

    if (B[i] > 0)
      possible = false;
  }

  if(possible)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
  
	return 0;
}
