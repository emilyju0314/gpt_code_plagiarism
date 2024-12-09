#include <iostream>
#include <vector>

#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
ll Calc_pow(ll x, ll pow)
{
	if (pow == 0) return 1;
	ll a = Calc_pow(x, pow / 2);
	a = a * a % mod;
	if (pow % 2 == 1) a *= x;
	return a % mod;
}

ll Devide(ll n)
{
	return Calc_pow(n % mod, mod - 2) % mod;
}

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<ll> sum(n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = Devide(i) + sum[i - 1];
		sum[i] %= mod;
	}

	ll fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
		fact %= mod;
	}

	ll ret = 0;
	for (int i = 0; i < n; i++)
	{
		ll t = sum[i + 1] + sum[n - i] - 1;
		t %= mod;
		ret += (a[i] * t % mod) * fact % mod;
		ret %= mod;
	}
	cout << ret << endl;
	return 0;
}
