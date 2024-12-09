#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define int ll
const int N = 1<<18;

int n, res, c;

VPII G[N];
int x[N];
int p[N];
int dist[N];
int pre[N];
int post[N];
PII e[N];

int Find(int a)
{
	if(p[a]!=a)
		p[a] = Find(p[a]);

	return p[a];
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a!=b)
	{
		p[a] = b;
		return 1;
	}

	return 0;
}

struct tree
{
	PII sub[2*N][2];
	int load[2*N];

	PII query(int z)
	{
		if(sub[1][0].nd==z)
			return sub[1][1];
		else
			return sub[1][0];
	}

	inline void merge(int v)
	{
		int u = 2*v;
		int w = 2*v+1;

		if(sub[u][0]>sub[w][0])
			swap(u, w);

		sub[v][0] = sub[u][0];
		sub[v][1] = sub[u][1];

		if(sub[w][0].nd!=sub[v][0].nd)
			sub[v][1] = min(sub[v][1], sub[w][0]);
		
		if(sub[w][1].nd!=sub[v][0].nd)
			sub[v][1] = min(sub[v][1], sub[w][1]);

		sub[v][0].st += load[v];
		sub[v][1].st += load[v];
	}

	inline void insert(int a, int b, int c, int v = 1, int l = 0, int r = N-1)
	{
		if(a>r || l>b)
			return;

		if(a<=l && r<=b)
		{
			load[v] += c;
			sub[v][0].st += c;
			sub[v][1].st += c;
			return;
 		}

 		insert(a, b, c, v<<1, l, (l+r)>>1);
 		insert(a, b, c, (v<<1)+1, ((l+r)>>1)+1, r);
 		merge(v);
	}

	void build()
	{
		for(int i = 0; i < 2*N; ++i)
		{
			for(int j = 0; j < 2; ++j)
			{
				sub[i][j] = mp(INF, INF);
			}

			load[i] = 0;
		}

		for(int i = 1; i <= n; ++i)
		{
			sub[pre[i]+N][0] = min(sub[pre[i]+N][0], mp(dist[i]+x[i], Find(i)));
		}

		for(int i = N-1; i >= 1; --i)
		{
			merge(i);
		}
	}
};

tree T;

void dfs(int v)
{
	pre[v] = ++c;

	for(auto it:G[v])
	{
		if(!pre[it.st])
		{
			dist[it.st] = dist[v]+it.nd;
			dfs(it.st);
		}
	}

	post[v] = c;
}

int all = 0;

void solve(int v)
{
	auto q = T.query(Find(v));
	q.st += x[v];
	q.st += all;
	e[Find(v)] = min(e[Find(v)], q);

	for(auto it:G[v])
	{
		if(pre[it.st]>pre[v])
		{
			all += it.nd;
			T.insert(pre[it.st], post[it.st], -2*it.nd);
			solve(it.st);
			all += -it.nd;
			T.insert(pre[it.st], post[it.st], 2*it.nd);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i];
	}

	for(int i = 1; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);
	}

	for(int i = 1; i <= n; ++i)
	{
		p[i] = i;
	}

	dfs(1);

	int comp = n;

	while(comp>1)
	{
		T.build();

		for(int i = 1; i <= n; ++i)
		{
			e[i] = mp(INF, INF);
		}

		solve(1);

		for(int i = 1; i <= n; ++i)
		{
			if(i==Find(i) && e[i]!=mp(INF, INF) && Union(i, e[i].nd))
			{
				--comp;
				res += e[i].st;
			}
		}
	}

	cout << res << endl;
}