#include<bits/stdc++.h>

using namespace std;

int main() {

  int n, q;
  long long k_min, k_max;
  cin >> n >> q >> k_min >> k_max;

  vector<long long> R(n);

  for(int i = 0; i < n; i++)
    cin >> R[i];

  sort(R.begin(), R.end());

  while(q--)
  {
    long long x;
    cin >> x;

    int l = 0, r = n-1, palta_min = n, palta_max = -1;
    while(l <= r)
    {
      int p = (l + r) / 2;
      if(R[p]*x >= k_min)
      {
        r = p-1;
        palta_min = p;
      } 
      else
        l = p+1;
    }

    l = 0, r = n-1;
    while(l <= r)
    {
      int p = (l + r) / 2;
      if(R[p]*x <= k_max){
        palta_max = p;
        l = p+1;
      }
      else r = p-1;
    }
    cout << palta_max - palta_min + 1 << endl;
  }
}
