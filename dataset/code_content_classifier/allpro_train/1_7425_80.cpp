#include <iostream>
#include <cstdio>
#define N 300005
using namespace std;

typedef long long ll;
ll M = 998244353;
ll n, a, b, k, s, fac[N]{1, 1}, inv[N]{1, 1}, fin[N]{1, 1};

ll f(ll p, ll q) {
	return fac[p] * fin[p - q] % M * fin[q] % M;
}

int main()
{
	ll i, j;
	cin >> n >> a >> b >> k;
	for (i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % M;
	for (i = 2; i <= n; i++) inv[i] = inv[M % i] * (M - M / i) % M;
	for (i = 2; i <= n; i++) fin[i] = fin[i - 1] * inv[i] % M;
	for (i = 0; a * i <= k && i <= n; i++) {
		j = (k - a * i) / b;
		if (a * i + b * j != k || j > n) continue;
		s = (s + f(n, i) * f(n, j)) % M;
	}
    cout << s << endl;
    return 0;
}