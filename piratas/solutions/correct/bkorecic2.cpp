#include <bits/stdc++.h>

using namespace std;

int main(){
    // La diferencia con "bkorecic.cpp" es que este escoge el de 
    // mayor índice en caso de empate,
    // ambas soluciones deberían ser accepted.
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
    int i=0;
    while(i+1<n && get<0>(a[i]) == get<0>(a[i+1]) && get<1>(a[i]) == get<1>(a[i+1])) i++;
    cout << get<2>(a[i])+1 << '\n';
}