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

  int p2 = n-1;

  for(int i = n-1; i >= 0; i--)
  {
    while(p2 > i+k)
      p2--;

    while(p2 >= i && B[i] > 0)
    {
      int delta = min(B[i], A[p2]);
      B[i] -= delta;
      A[p2] -= delta;

      if(A[p2] == 0)
        p2--;
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
