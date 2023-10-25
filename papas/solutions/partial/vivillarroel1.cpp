// @ocimatic should-pass=[st1]
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long p, n, k;
	cin >> p >> n >> k;
	int a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);
	if (k == 1) cout << a << endl;
	else cout << b << endl;
}
