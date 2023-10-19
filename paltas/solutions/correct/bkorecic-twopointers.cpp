#include <bits/stdc++.h>

using namespace std;

int main(){
    // solution sorting queries and using two pointers
    int n, q, kmin, kmax;
    cin >> n >> q >> kmin >> kmax;
    vector <int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector <pair<int,int>> queries(q);
    for(int i=0; i<q; i++){
        int x; cin >> x;
        queries[i] = {x, i};
    }
    sort(queries.begin(), queries.end());
    int l=n-1, r=n-1;
    vector <int> ans(q,0);
    for(auto [t, idx] : queries){
        while(l > 0 && t*a[l-1] >= kmin) l--;
        while(r > 0 && t*a[r] > kmax) r--;
        if(r>=l && t*a[l] >= kmin && t*a[r] <= kmax)
            ans[idx] = r-l+1;
    }
    for(int &x : ans){
        cout << x << '\n';
    }
}