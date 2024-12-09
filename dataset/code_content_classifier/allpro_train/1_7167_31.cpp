#include <cstdio>
#include <map>
typedef long long ll; 
inline ll quick_pow(ll a, ll n, ll mod)
{
	ll res = 1; 
	while (n)
	{
		if (n & 1)
			res = res * a % mod; 
		a = a * a % mod;
		n >>= 1; 
	}
	return res; 
}
struct data
{
	ll arr[5]; 
	inline ll &operator [](const int &x)
	{
		return arr[x]; 
	}
	inline const ll &operator [](const int &x) const
	{
		return arr[x]; 
	}
	inline bool operator <(const data &x) const
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i] != x[i])
				return arr[i] < x[i]; 
		}
		return false; 
	}
} hsh[300005], cur; 
const ll bs[] = {500003, 250001, 250007, 1234567, 34252124}, md[] = {1000000007, 1000000009, 998244353, 1234567891, 2147483647}; 
ll pw[5][600005], inv[5][600005]; 
int arr[300005]; 
std::map<data, int> app; 
char str[300005]; 
int main()
{
	// freopen("ARC099-F.in", "r", stdin); 
	int n; 
	scanf("%d%s", &n, str); 
	for (int i = 0; i < 5; i++)
	{
		pw[i][0] = 1;
		for (int j = 1; j < 600005; j++)
			pw[i][j] = pw[i][j - 1] * bs[i] % md[i]; 
		inv[i][0] = 1; 
		int x = quick_pow(bs[i], md[i] - 2, md[i]); 
		for (int j = 1; j < 600005; j++)
			inv[i][j] = inv[i][j - 1] * x % md[i]; 
	}
	int pos = n + 5; 
	for (int i = 0; i <= n; i++)
	{
		hsh[i] = cur;
		arr[i] = pos; 
		switch (str[i])
		{
		case '+':
			for (int j = 0; j < 5; j++)
				cur[j] = (cur[j] + pw[j][pos]) % md[j]; 
			break; 
		case '-':
			for (int j = 0; j < 5; j++)
				cur[j] = (cur[j] - pw[j][pos] + md[j]) % md[j]; 
			break; 
		case '<':
			pos--; 
			break; 
		case '>':
			pos++;
		}
	}
	ll ans = 0; 
	for (int i = n; i >= 0; i--)
	{
		int diff = arr[i] - n - 5; 
		data x; 
		if (diff >= 0)
		{
			for (int j = 0; j < 5; j++)
				x[j] = (hsh[i][j] + cur[j] * pw[j][diff]) % md[j]; 
		}
		else
		{
			for (int j = 0; j < 5; j++)
				x[j] = (hsh[i][j] + cur[j] * inv[j][-diff]) % md[j];
		}
		ans += app[x]; 
		app[hsh[i]]++; 
	}
	printf("%lld\n", ans);
	return 0; 
}
