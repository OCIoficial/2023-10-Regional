#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    using val = tuple<int,int,int>;
    vector <val> a(n);
    for(int i=0; i<n; i++){
        int s, p;
        cin >> s >> p;
        a[i] = {s, p, i};
    }
    sort(a.begin(), a.end(), [&](val &x, val &y){
        auto [x0, x1, x2] = x;
        auto [y0, y1, y2] = y;
        if(x0 != y0) return x0 > y0;
        return x1 < y1;
    });
    cout << get<2>(a[0])+1 << '\n';
}