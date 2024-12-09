#pragma GCC optimize("O2")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops,fast-math")

#define ll long long 
#define u unsigned
#define frr(x,y) for(int y=0;y<x;y++)
#define fr(x) frr(x,i)
#define frin fr(n)

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

ll n, m, k, t, x, y, z, a, b, c, d, l, r;
vector<int> f, p, dp;

int getmax(int l, int r)
{
	int ans = 0,mx=0;
	for (int i = l; i <= r; i++)
	{
		if (f[i] > mx)
		{
			mx = f[i];
			ans = i;
		}
	}
	return ans;
}

void bld(int l, int r, int d)
{
	if (r < l)
		return;
	int v = getmax(l, r);
	p[v] = d;
	bld(l, v - 1,d+1);
	bld(v + 1, r, d + 1);
}

void solve()
{
	cin >> n;
	vector<pair<ll, ll>>f;
	vector<ll>ans;
	vector<ll>p;
	frin
	{
		cin >> a;
	f.push_back({ a,i });
	}
	sort(f.begin(), f.end());
	p.push_back(f[0].first);
	fr(n - 1)
	{
		p.push_back(p[i] + f[i + 1].first);
	}
	ans.push_back(f[n - 1].second);
	for (int i = n - 2; i >= 0; i--)
	{
		if (p[i] >= f[i + 1].first)
			ans.push_back(f[i].second);
		else
			break;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto& x : ans)
	{
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main()
{
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		solve();
	}
}