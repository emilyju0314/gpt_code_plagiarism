#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<climits>
#define P pair<int ,int>
#define MAX_N 1002
using namespace std;
#define rep(i,a) for(int i = 0;i < a; i++)

struct E{
	int to, cap, rev;
	E(int t, int c, int r) : to(t), cap(c), rev(r){}
};
//始点0, 終点1
vector<E> G[MAX_N];
bool f[MAX_N];
const int INF = 1 << 10;

void add_edge(int from, int to, int cap) {
	G[from].push_back(E(to, cap, G[to].size()));
	G[to].push_back(E(from, 0, G[from].size() - 1));
}

int gcd(int x, int y)
{
	if (!x | !y) return 0;
	
	while (x != y) {
		if (x > y) x -= y;
		else y -= x;
	}
	
	return x;
}

bool dfs(int s, int e, int fl) {
	if (s == e) return fl;
	f[s] = 1;
	rep(i, G[s].size()) {
		E &ed = G[s][i];
		if (!f[ed.to] && ed.cap > 0) {
			int d = dfs(ed.to, e, min(fl, ed.cap));
			if (d > 0) {
				ed.cap -= d;
				G[ed.to][ed.rev].cap += d;
				return d;
			}
		}
	}
	
	return 0;
}

int max_flow(int src, int snk)
{
	int flow = 0;
	
	while (1) {
		memset(f, 0, sizeof(f));
		int fl = dfs(src, snk, INF);
		if (fl == 0) break;
		flow += fl;
	}
	
	return flow;
}

int main()
{
	int m, n;
	int b[MAX_N];
	
	while (cin >> m >> n, m) {
		rep(i, MAX_N) G[i].clear();
		
		rep(i, m) {
			cin >> b[i];
			add_edge(0, i + 2, 1);
		}
		
		int r;
		rep(i, n) {
			 cin >> r;
			 add_edge(m + 2 + i, 1, 1);
			 rep(j ,m) {
			 	 if (gcd(r, b[j]) > 1) {
			 	 	 add_edge(j + 2, m + 2 + i, 1);
			 	 }
			 }
		}

		int res = max_flow(0, 1);
		
		cout << res << endl;
	}
	
	return 0;
}