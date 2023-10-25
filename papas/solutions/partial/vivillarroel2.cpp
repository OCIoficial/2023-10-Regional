// @ocimatic should-pass=[st2]
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long p, n, k;
	cin >> p >> n >> k;
	long long ans = 1000000001;
	for (int i = 0; i < p; ++i) {
		long long aux;
		cin >> aux;
		ans = min(aux, ans);
	}
	cout << ans << endl;
}
