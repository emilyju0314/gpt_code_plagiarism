// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

ll DS[N], DT[N];
int n, DPS[N], DPT[N];
vector<pii> G[N];

void Dijkstra(int s, ll dis[N], int dp[N]) {
	for (int i = 1; i < N; i++) dis[i] = INF;
	dis[s] = 0;
	dp[s] = 1;
	set< pair<ll, int> > st; st.insert(make_pair(0, s));
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (pii e : G[v]) {
			int u = e.first, w = e.second;
			if (dis[v] + w < dis[u]) {
				st.erase(make_pair(dis[u], u));
				dis[u] = dis[v] + w;
				dp[u] = 0;
				st.insert(make_pair(dis[u], u));
			}
			if (dis[v] + w == dis[u]) dp[u] = (dp[u] + dp[v]) % MOD;
		}
	}
}
int sq(int x) { return 1LL * x * x % MOD; }

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int m, s, t; cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)  {
		int v, u, w; cin >> v >> u >> w;
		G[v].push_back(make_pair(u, w));
		G[u].push_back(make_pair(v, w));
	}
	Dijkstra(s, DS, DPS);
	Dijkstra(t, DT, DPT);
	int ans = 1LL * DPS[t] * DPT[s] % MOD;
	ll d = DS[t];
	for (int v = 1; v <= n; v++) 
		if (DS[v] + DT[v] == d && DS[v] == DT[v]) 
			ans = (ans - sq(1LL * DPS[v] * DPT[v] % MOD) + MOD) % MOD;
	for (int v = 1; v <= n; v++) for (pii e : G[v]) {
		int u = e.first, w = e.second;
		if (DS[v] + w + DT[u] == d && abs(DS[v] - DT[u]) < w)
			ans = (ans - sq(1LL * DPS[v] * DPT[u] % MOD) + MOD) % MOD;
	}
	cout << ans << endl;

	return 0;
}
