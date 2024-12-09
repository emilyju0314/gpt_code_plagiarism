#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>


using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define clear(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };



struct Edge
{
	int to, cap, rev;
	Edge(int to, int cap, int rev)
		: to(to), cap(cap), rev(rev) {}
	Edge() { Edge(0, 0, 0); }
};
class FordFulkerson
{
	vector<bool> used;
	int _dfs(int v, int t, int f)
	{
		if (v == t)
			return f;

		used[v] = true;
		for (int i = 0; i < edges[v].size(); ++i)
		{
			Edge& e = edges[v][i];
			if (!used[e.to] && e.cap > 0)
			{
				int d = _dfs(e.to, t, min(f, e.cap));
				if (d > 0)
				{
					e.cap -= d;
					edges[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	vector<vector<Edge> > edges;
	int V;
	FordFulkerson(int V)
		: V(V), edges(V), used(V) {}

	void add_edge(int from, int to, int cap)
	{
		edges[from].push_back(Edge(to, cap, edges[to].size()));
		edges[to].push_back(Edge(from, 0, edges[from].size() - 1));
	}

	int dfs(int v, int t, int f)
	{
		fill(used.begin(), used.end(), false);
		return _dfs(v, t, f);
	}

	int max_flow(int s, int t)
	{
		int flow = 0;
		for (;;)
		{
			const int INF = 1000000000;
			int f = dfs(s, t, INF);
			if (f == 0)
				break;
			flow += f;
		}
		return flow;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	int n, m, l;
	while (cin >> n >> m >> l)
	{
		int a[12345], b[12345], d[12345];
		int p[128], k[128];
		for (int i = 0; i < m; ++i)
		{
			cin >> a[i] >> b[i] >> d[i];
			--a[i], --b[i];
		}
		for (int i = 0; i < n; ++i)
			cin >> p[i];
		for (int i = 0; i < n; ++i)
			cin >> k[i];


		int dis[128][128];
		const int INF = 1 << 28;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dis[i][j] = i == j ? 0 : INF;
		for (int i = 0; i < m; ++i)
			dis[a[i]][b[i]] = dis[b[i]][a[i]] = d[i];
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					min_swap(dis[i][j], dis[i][k] + dis[k][j]);


		FordFulkerson f(2 * n + 2);
		int src = 2 * n, sink = 2 * n + 1;
		for (int i = 0; i < n; ++i)
		{
			f.add_edge(src, i, p[i]);
			f.add_edge(n + i, sink, k[i]);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dis[i][j] < l)
					f.add_edge(i, n + j, INF);

		cout << f.max_flow(src, sink) << endl;
	}
}