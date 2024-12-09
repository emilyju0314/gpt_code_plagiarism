#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 200010;

vi g[2][maxn];
int dep[maxn], par[maxn]; //sugim

void dfs(int v, int p, int d) { //on sugim
	dep[v] = d;
	par[v] = p;
	for (int to : g[1][v]) if (to != p) {
		dfs(to, v, d + 1);
	}
}

bool far(int a, int b) { //on sugim, 3
	if (dep[a] > dep[b]) swap(a, b);
	if (a == b || par[b] == a || par[a] == par[b] || (par[b] != -1 && par[par[b]] == a)) {
		return false;
	} else {
		return true;
	}
}

const int INF = 1e8;

int DFS(int v, int p, int d) { //on sigma
	int res = (dep[v] - d) * 2;
	for (int to : g[0][v]) if (to != p) {
		if (dep[to] > d+1) {
			res = max(res, DFS(to, v, d + 1) + 2);
		}
		if (far(v, to)) {
			res = max(res, INF);
		}
	}
	return res;
}

int main() {
	int N, X, Y;
	cin >> N >> X >> Y; --X; --Y;

	rep(t, 2) {
		rep(i, N-1) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			g[t][a].pb(b); g[t][b].pb(a);
		}
	}

	dfs(Y, -1, 0);
	int ans = DFS(X, -1, 0);
	if (ans >= INF) ans = -1;
	cout << ans << endl;

	return 0;
}
