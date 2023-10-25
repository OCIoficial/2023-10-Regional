// @ocimatic should-pass=[st1, st3]
// solucion cuadratica más rapida
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long p, n, k;
	cin >> p >> n >> k;
	vector<long long> papas(p);
	vector<bool> comida(p, 0);
	for (int i = 0; i < p; ++i) {
		cin >> papas[i];
	}
	long long ans = 0;
	int actual = 1, posactual;
	for (int j = 0; j < p; ++j) {
		long long actual = -1;
		for (int i = 0; i < p; ++i) {
			if (!comida[i] && papas[i] > actual) {
				actual = papas[i];
				posactual = i;
			}
		}
		comida[posactual] = 1;
		if (j % n  == k - 1) ans += actual; 
	}
	cout << ans << endl;
}
