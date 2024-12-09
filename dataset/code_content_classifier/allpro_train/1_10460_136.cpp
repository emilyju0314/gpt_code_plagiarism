#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int oo = 1e9;
const int MOD = 1000000007;
const int N = 200010;
#define x first
#define y second
#define pb push_back
#define mp make_pair

struct state {
	int x , y , z;
	state() {
		x=y=z=0;	
	}
	state(int _x, int _y , int _z) {
		x = _x, y = _y, z = _z;
	}
};
int n, p[N];
vector<int> g[N];
deque<state> dq[N];

int fast(int a , int b) {
	if (!b)return 1ll;
	int res = fast(a, b / 2);
	res = (1ll * res * res) % MOD;
	if (b & 1)return (1ll * res * a) % MOD;
	return res;
}
int inv(int a) {
	return fast(a, MOD - 2);
}
state merge(state a , state b) {
	state res;
	res.x = (1ll*a.x * b.x + MOD) % MOD;
	res.y = (1ll * a.x * b.y + 1ll * b.x * a.y) % MOD;
	res.z = (1ll + 1ll*(MOD - res.x) + 1ll*(MOD - res.y) + MOD) % MOD;
	return res;
}
const int INV = inv(2);

void solve(int u) {
	int mx = -1 , at = -1;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		solve(v);
		if ((int)dq[v].size() > mx)
			mx = dq[v].size() , at = v;
	}
	int smx = 1;
	if (at != -1) {
		dq[u].swap(dq[at]);
		for (int i = 0 ; i < g[u].size(); ++i) {
			int v = g[u][i];
			if (v == at)continue;
			assert(dq[u].size()>=dq[v].size());
			smx = max(smx,(int)dq[v].size()+1);
			for (int j = 0 ; j < dq[v].size(); ++j) {
				dq[u][j] = merge(dq[v][j], dq[u][j]);
			}
		}
	}
	dq[u].push_front(state(INV, INV, 0));
	for (int j = 0 ; j < smx; ++j) {
		dq[u][j].x = (1ll*dq[u][j].x+dq[u][j].z)%MOD;
		dq[u][j].z = 0;
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n ; ++i) {
		scanf("%d", &p[i]);
		g[p[i]].pb(i);
	}
	solve(0);
	ll res = 0;
	ll cons =  fast(2, n + 1);
	for (int i = 0; i < dq[0].size(); ++i) {
		res = (res + 1ll * dq[0][i].y * 1ll *cons) % MOD;
	}
	printf("%lld\n", res );


	return 0;
}
