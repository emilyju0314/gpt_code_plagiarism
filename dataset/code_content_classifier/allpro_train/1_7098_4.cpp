#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

struct edge {
	int to; ll cap;
};
vector<edge> G[1 << 17];

bool inpath[1 << 17];
int s, g;
vector<int> path;
bool find_path(int id,int fr) {
	if (id == g) {
		inpath[id] = true;
		path.push_back(id); return true;
	}
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		if (to == fr)continue;
		if (find_path(to,id)) {
			inpath[id] = true;
			path.push_back(id); return true;
		}
	}
	return false;
}

bool valid = true;

//int cnt[1 << 17];
ll t;
void dfs(int id, int fr) {
	vector<ll> v;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		if (to == fr)continue;
		dfs(to, id);
		ll rest = G[id][j].cap - t * ((ll)G[to].size()+1);
		if (rest <= 0) {
			valid = false; return;
		}
		v.push_back((rest - 1) / t);
	}
	sort(v.begin(), v.end());
	rep(i, v.size()) {
		if (v[i] < i) {
			valid = false; return;
		}
	}
}

void solve() {
	int n; cin >> n >> t >> s >> g;
	s--; g--;
	rep(i, n - 1) {
		int a, b, w; cin >> a >> b >> w; a--; b--;
		G[a].push_back({ b,w });
		G[b].push_back({ a,w });
	}
	if (t == 0) {
		cout << "Yes" << endl; return;
	}
	find_path(s, -1);
	per(i, (int)path.size()) {
		int v = path[i];
		vector<ll> u;
		rep(j, G[v].size()) {
			int to = G[v][j].to;
			if (!inpath[to]) {
				dfs(to, v);
				ll rest = G[v][j].cap - t * ((ll)G[to].size()+1);
				if (v == s)rest += t;
				if (rest <= 0) {
					cout << "No" << endl; return;
				}
				u.push_back((rest - 1) / t);
			}
		}
		sort(u.begin(), u.end());
		rep(j, u.size()) {
			if (u[j] < j) {
				cout << "No" << endl; return;
			}
		}
		if (i > 0) {
			ll c = 0;
			rep(j, G[v].size()) {
				if (G[v][j].to == path[i - 1]) {
					c = G[v][j].cap; break;
				}
			}
			ll sum = t * ((ll)G[v].size() - 1);
			if (sum >= c) {
				cout << "No" << endl; return;
			}
		}

	}
	if (!valid) {
		cout << "No" << endl; return;
	}
	cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}

