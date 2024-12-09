#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(int)(b); i++)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define st first
#define nd second
using namespace std;
 
const int maxN = 1 << 11;
const int mod = 998244353;

template <class T1, class T2> inline void addMod(T1& a, T2 b)	{   a = (a + b) % mod;  }
template <class T1, class T2> inline void multMod(T1& a, T2 b)	{   a = a * b % mod;    }

long long qpow(long long a, long long b)
{
    long long res0 = 1;
    for (; b!=0; b>>=1)
    {
        if (b & 1)  multMod(res0, a);
        multMod(a, a);
    }
    return res0;
}

vector <int> vs[maxN][maxN];
char in[maxN][maxN];
bool can[maxN][maxN], canot[maxN][maxN], meet[maxN][maxN], vis[maxN];
int state[maxN], xr;
vector <int> G[maxN];

void ans(long long a)
{
	printf("%lld\n", a);
	exit(0);
}

void dfs(int v)
{
	xr ^= state[v];
	vis[v] = true;
	for (int u : G[v])
		if (!vis[u])
			dfs(u);
}

long long f(int v, int n, int m)
{
	if (n % 2 == 0)
		return qpow(2, m);
	int comps = 0;
	for (; v<n*2; v+=2) if (!vis[v])
	{
		xr = 0;
		dfs(v);
		if (xr != 0)
			return 0;
		comps++;
	}
	return qpow(2, m - n + comps);
}

void solve()
{
	int n;
	scanf ("%d", &n);
	n++;
	FOR(i, 1, n-1)
		scanf ("%s", &in[i][1]);
		
	FOR(i, 1, n-1)
		vs[i][i].pb(0), vs[i][n-1-i].pb(n-1);
	FOR(v, 1, n-1)
	{
		int j0 = v, j1 = v, d0 = -1, d1 = 1;
		
		FOR(i, 1, n-1)
		{
			j0 += d0, j1 += d1;
			for (int j : {j0, j1})
				vs[i][j].pb(v);
			if (j0 == 0)
				d0 = 1;
			if (j1 == n-1)
				d1 = -1;
		}
	}
	
	FOR(i, 1, n-1) FOR(j, 1, n-1)
	{
		assert(vs[i][j].size() == 2);
		int u = vs[i][j][0], v = vs[i][j][1];
		if (in[i][j] != '?')
			in[i][j] == 'o' ? can[u][v] = can[v][u] = true : canot[u][v] = canot[v][u] = true;
		meet[v][u] = meet[u][v] = true;			
	}
	
	int m0 = 0, m1 = 0;
	FOR(v, 0, n) FOR(u, 0, v)
	{
		if (can[v][u] and canot[v][u])
			ans(0);
		if (!can[v][u] and !canot[v][u] and meet[v][u])
		{
			G[u].pb(v), G[v].pb(u);
			u % 2 ? m1++ : m0++;
		}
		if (can[v][u])
			state[v] ^= 1, state[u] ^= 1;
	}
	
	long long res = f(0, (n+1)/2, m0);
	multMod(res, f(1, n/2, m1));	
	ans(res);
}
 
int main()
{
	int t;
	t = 1;//scanf ("%d", &t);
	while (t--)
		solve();
	return 0;
}

