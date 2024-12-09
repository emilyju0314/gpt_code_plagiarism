#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

#define MX 1000100

ll fact[MX], dfact[MX];

ll bin_pow(ll a, ll n) {
	ll res(1);
	while (n)
	{
		if (n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

void pre_calc()
{
	fact[0] = dfact[0] = 1;
	for (int i(1); i < MX; ++i)
	{
		fact[i] = fact[i - 1] * i % mod;
		dfact[i] = bin_pow(fact[i], mod - 2);
	}
}

ll C(ll n, ll k) { return fact[n] * dfact[n - k] % mod * dfact[k] % mod; }

int main()
{
	pre_calc();
	int n;
	cin >> n;
	ll ans(0);
	ll pre(0);
	for (int m(1); m < n; ++m)
		if (m * 2 >= n) {
			ll d = (2 * m - n) % mod;
			ll c = C(m - 1, d);
			ll cur = (mod - pre + C(m - 1, d) * fact[m] % mod * fact[n - 1 - m] % mod) % mod;
			pre += cur; pre %= mod;
			ans += cur * m; ans %= mod;
		}
	cout << ans;
}
