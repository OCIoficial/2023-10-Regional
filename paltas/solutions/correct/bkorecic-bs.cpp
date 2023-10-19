#include <bits/stdc++.h>

using namespace std;

int main(){
    // solution using binary search
    int n, q, kmin, kmax;
    cin >> n >> q >> kmin >> kmax;
    vector <int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
   
    while(q--){
        int t;
        cin >> t;
        int first, last;
        {
            int l=0, r=n-1, mid;
            while(l < r){ // primer t*a[mid] >= kmin
                mid = (l+r)/2;
                if(t*a[mid] >= kmin) r = mid;
                else l = mid+1;
            }
            first = l;
        }
        {
            int l=0, r=n-1, mid;
            while(l < r){ // ultimo <= kmax
                mid = (l+r+1)/2;
                if(t*a[mid] <= kmax) l = mid;
                else r = mid-1;
            }
            last = l;
        }
        if(t*a[first] >= kmin && t*a[first] <= kmax) cout << last-first+1 << '\n';
        else cout << "0\n";
    }
}