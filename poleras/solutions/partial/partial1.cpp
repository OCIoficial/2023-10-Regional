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

  for(int i = 0; i < n; i++)
    if(A[i] < B[i])
      possible = false;

  if(possible)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
  
	return 0;
}
