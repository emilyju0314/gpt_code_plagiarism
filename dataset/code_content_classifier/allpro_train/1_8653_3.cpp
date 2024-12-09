#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

const int MOD = 1000000007;

int n, m;
int x[1001], y[1001];
struct Edge {
	int a, b, i;
	Edge(int a_, int b_, int i_): a(a_), b(b_), i(i_) {}
};
vector<Edge> a[1001];

bool vis[1001];
int dfs(int prev, int i) {
	if(vis[i]) return 0;
	vis[i] = 1;
	int r = i;
	each(j, a[i]) if(j->i != prev) {
		r = dfs(j->i, abs(j->b));
	}
	return r;
}
int dp[1001][2][2][2];
int rec(int prev, int i, bool assign, int first, bool firstassign) {
	if(dp[i][assign][first == 0][firstassign] != -1)
		return dp[i][assign][first == 0][firstassign];
	int r = 0;
	int current, next = 0, edge;
	each(j, a[i]) if(j->i != prev)
		current = j->a, next = j->b, edge = j->i;
	if(i == first) {
		if(assign == firstassign) r = 1;
	}else if(next == 0) {
		r = 1;
	}else {
		bool ff = first == 0;
		int nfirst = ff ? i : first;
		if(assign == (current > 0)) {	//この項が既に満たされている
			r = rec(edge, abs(next), false, nfirst, ff ? assign : firstassign);
			if((r += rec(edge, abs(next), true, nfirst, ff ? assign : firstassign)) >= MOD) r -= MOD;
		}else {	//assign == (next > 0)にして満たす必要がある
			r = rec(edge, abs(next), next > 0, nfirst, ff ? assign : firstassign);
		}
	}
	return dp[i][assign][first == 0][firstassign] = r;
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
	rep(i, m)
		scanf("%d%d", &x[i], &y[i]);
	rer(i, 1, n) a[i].clear();
	rep(i, m) {
		a[abs(x[i])].pb(Edge(x[i], y[i], i));
		a[abs(y[i])].pb(Edge(y[i], x[i], i));
	}
	mset(vis, 0);
	mset(dp, -1);
	ll r = 1;
	rer(i, 1, n) if(!vis[i]) {
		unsigned x = 0;
		if(int last = dfs(-1, i)) {
			//line
			x += rec(-1, last, false, 0, 0);
			x += rec(-1, last, true, 0, 0);
		}else {
			//cycle
			x += rec(-1, i, false, 0, 0);
			x += rec(-1, i, true, 0, 0);
		}
		x %= MOD;
		(r *= x) %= MOD;
	}
	printf("%d\n", (int)r);
	}
	return 0;
}