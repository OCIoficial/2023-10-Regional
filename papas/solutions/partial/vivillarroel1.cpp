// solución más lenta para st1
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long p, n, k;
	cin >> p >> n >> k;
	multiset<long long> papas;
	for (int i = 0; i < p; ++i) {
		long long aux;
		cin >> aux;
		papas.insert(aux);
	}
	long long ans = 0;
	int i = 1;
	for (auto it = papas.rbegin(); it != papas.rend(); ++it, ++i) {
		if (i % (n+1) == 1 % (n+1)) ans += *it;
	}
	cout << ans << endl;
}
