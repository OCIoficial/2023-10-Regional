// @ocimatic should-pass=[st1]
#include<bits/stdc++.h>

using namespace std;

int main() {

  int n, q;
  long long k_min, k_max;
  cin >> n >> q >> k_min >> k_max;

  vector<long long> R(n);

  for(int i = 0; i < n; i++)
    cin >> R[i];

  while(q--)
  {
    long long x;
    cin >> x;

    int good_paltas = 0;

    for(int i = 0; i < n; i++)
      if(R[i]*x >= k_min && R[i]*x <= k_max)
        good_paltas++;

    cout << good_paltas << endl;
  }
}
