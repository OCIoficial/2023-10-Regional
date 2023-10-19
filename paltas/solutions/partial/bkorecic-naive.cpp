#include <bits/stdc++.h>

using namespace std;

int main(){
    // O(nq) naive solution
    int n, q, kmin, kmax;
    cin >> n >> q >> kmin >> kmax;
    vector <int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
   
    while(q--){
        int t;
        cin >> t;
        int first=0, last=0;

        for(int i=0; i<n; i++){
            if(t*a[i] >= kmin){
                first = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(t*a[i] <= kmax){
                last = i;
                break;
            }
        }
        if(t*a[first] >= kmin && t*a[first] <= kmax) cout << last-first+1 << '\n';
        else cout << "0\n";
    }
}