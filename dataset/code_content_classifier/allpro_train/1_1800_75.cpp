#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
#define MOD 1000000007
typedef long long ll; 
struct data
{
	int u, v, w; 
	inline bool operator <(const data &a) const
	{
		return w < a.w; 
	}
} arr[2005]; 
int fa[1005]; 
inline ll quick_pow(ll a, int n)
{
	ll res = 1; 
	while (n)
	{
		if (n & 1)
			res = res * a % MOD; 
		a = a * a % MOD; 
		n >>= 1; 
	}
	return res; 
}
int getfa(int u)
{
	if (u == fa[u])
		return u; 
	return fa[u] = getfa(fa[u]); 
}
inline bool unite(int u, int v)
{
	u = getfa(u); 
	v = getfa(v); 
	fa[u] = v; 
	return u != v; 
}
int main()
{
	// freopen("ARC093-E.in", "r", stdin); 
	int n, m; 
	ll x; 
	scanf("%d%d%lld", &n, &m, &x); 
	if (n <= 2)
	{
		puts("0"); 
		return 0; 
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &arr[i].u, &arr[i].v, &arr[i].w); 
		arr[i].u--; 
		arr[i].v--; 
	}
	std::sort(arr, arr + m); 
	int cntx = 0, cnty = 0; 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fa[j] = j; 
		ll sum = arr[i].w * unite(arr[i].u, arr[i].v); 
		for (int j = 0; j < m; j++)
			sum += arr[j].w * unite(arr[j].u, arr[j].v); 
		if (sum < x)
			cntx++; 
		if (sum <= x)
			cnty++; 
	}
	printf("%lld\n", (quick_pow(2, std::min(m, m - cntx + 1))
		 - quick_pow(2, std::min(m, m - cnty + 1)) + MOD) % MOD);
	return 0; 
}
