#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <cstdio>
using namespace std;

int D, K, L;
int M, N, P;
vector<vector<int> > c, r, t;

struct edge {
	int to, cap, cost, rev;
	edge(int to_, int cap_, int cost_, int rev_) {
		to = to_; cap = cap_; cost = cost_; rev = rev_;
	};
};

int V;
vector<vector<edge> > G;
vector<int> dist;
vector<int> prevv, preve;
const int INF = 1e7;

void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}

int min_cost_flow(int src, int snk, int f) {
	int res = 0;
	while(f > 0) {
		fill(dist.begin(), dist.end(), INF);
		dist[src] = 0;
		bool update = true;
		while(update) {
			update = false;
			for(int v = 0; v < V; v++) {
				if(dist[v] == INF) continue;
				for(int i = 0; i < G[v].size(); i++) {
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}

		if(dist[snk] == INF)
			return -1;

		int d = f;
		for(int v = snk; v != src; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		assert(d==1);
		f -= d;
		res += d * dist[snk];
		for(int v = snk; v != src; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

int dp[8][6570][9];
int solve_dp(int day, int items, int rest) {
	assert(items >= 0);
	if(day < 0 || rest < 0) return INF;
	//	cout << day << "," << items << "," << rest << endl;
	if(dp[day][items][rest] + 1)
		return dp[day][items][rest];

	dp[day][items][rest] = INF;
	dp[day][items][rest] =
		min(dp[day][items][rest], solve_dp(day-1, items, L));
	int one = 1;
	int itm = items;
	for(int i = 0; i < K; i++) {
		if(itm % 3) {
			dp[day][items][rest] =
				min(dp[day][items][rest], solve_dp(day, items-one, rest-1) + c[day][K-1-i]);
		}
		one *= 3;
		itm /= 3;
	}
	return dp[day][items][rest];
}

bool input() {
	scanf("%d%d%d",&D,&K,&L);
	if(D + K + L == 0) return false;
	c.clear();
	c.resize(D);
	for(int i = 0; i < D; i++) {
		c[i].resize(K);
		for(int j = 0; j < K; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	scanf("%d%d%d", &M, &N, &P);
	r.clear();
	r.resize(M);
	for(int i = 0; i < M; i++) {
		r[i].resize(K);
		for(int j = 0; j < K; j++) {
			scanf("%d", &r[i][j]);
		}
	}
	t.clear();
	t.resize(P);
	for(int i = 0; i < P; i++) {
		t[i].resize(K);
		for(int j = 0; j < K; j++) {
			scanf("%d", &t[i][j]);
		}
	}
	return true;
}

int main() {
	while(input()) {
		V = M+P+3;
		G.clear();
		dist.clear();
		prevv.clear();
		preve.clear();
		for(int i = 0; i < D; i++)
			for(int j = 0; j < 6570; j++)
				for(int k = 0; k <= L; k++)
					dp[i][j][k] = -1;
		for(int i = 0; i <= L; i++)
			dp[0][0][i] = 0;

		// make edge
		G.resize(V);
		dist.resize(V,0);
		prevv.resize(V,0);
		preve.resize(V,0);
		for(int i = 0; i < M; i++)
			add_edge(0, 1+i, 1, 0);
		for(int i = 0; i < M; i++) {
			int item;
			int C;
			for(int j = 0; j < P; j++) {
				item = 0;
				bool flg = true;
				for(int k = 0; k < K; k++) {
					item *= 3;
					item += r[i][k]-t[j][k];
					if(r[i][k]-t[j][k]<0)
						flg = false;
				}
				if(flg) {
					C = solve_dp(D-1,item,L);
					if(C < INF)
						add_edge(1+i, M+1+j, 1, C);
				}
			}
			item = 0;
			for(int k = 0; k < K; k++) {
				item *= 3;
				item += r[i][k];
			}
			C = solve_dp(D-1,item,L);
			if(C < INF)
				add_edge(1+i, M+P+1, 1, C);
		}
		for(int i = 0; i < P; i++)
			add_edge(M+1+i, M+P+2, 1, 0);
		add_edge(M+P+1, M+P+2, 200, 0);

		int ans = min_cost_flow(0,M+P+2,N);
		printf("%d\n", ans);
	}
}