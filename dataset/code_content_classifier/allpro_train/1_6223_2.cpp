#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int N = 2000;
const int M = 8192;

int n, a[N], b[N], cost[N];
vector<vi> e;

int parent[11][N];
int depth[N];

int euler[2*N], sz;
int pos[N][2];


int seg_sz = 1;
ll dat[2*M];
inline ll query(int a, int b, int k, int l, int r){
	
	if(b <= l || a >= r) return 0;
	if(a <= l && r <= b) return dat[k];
	
	ll lch = query(a, b, k * 2 + 1, l, (l + r) / 2);
	ll rch = query(a, b, k * 2 + 2, (l + r) / 2, r);
	
	return lch + rch;
}
inline void update(int pos, int d){
	
	pos += seg_sz - 1;
	dat[pos] += d;
	
	while(1){
		if(pos == 0) break;
		pos = (pos - 1) / 2;
		dat[pos] = dat[pos * 2 + 1] + dat[pos * 2 + 2];
	}
}

void dfs(int c, int p, int d = 1){
	
	depth[c] = d;
	parent[0][c] = p;
	dat[seg_sz - 1 + sz] = cost[c];
	euler[sz] = c;
	pos[c][0] = sz++;
	
	rep(i, e[c].size()){
		int id = e[c][i];
		int to = id < 0 ? a[-id - 1] : b[id - 1];
		
		if(to != p) dfs(to, c, d + 1);
	}
	
	dat[seg_sz - 1 + sz] = -cost[c];
	euler[sz] = c;
	pos[c][1] = sz++;
}

inline int lca(int a, int b){
	if(depth[a] < depth[b]) swap(a, b);
	
	for(int i = 10; i >= 0; i--) if(depth[a] - depth[b] >> i & 1) a = parent[i][a];
	
	if(a == b) return a;
	
	for(int i = 10; i >= 0; i--) if(parent[i][a] != parent[i][b]){
		
		a = parent[i][a];
		b = parent[i][b];
	}
	return parent[0][a];
}

int main(){
	
	scanf("%d", &n);
	e.resize(n);
	
	rep(i, n) scanf("%d", cost + i);
	rep(i, n - 1){
		scanf("%d%d", a + i, b + i);
		a[i]--; b[i]--;
		
		e[a[i]].pb(i + 1);
		e[b[i]].pb(-i - 1);
	}
	
	for(; seg_sz < 2 * n; seg_sz *= 2);
	
	dfs(0, 0);
	
	rep(i, 10) rep(j, n) parent[i + 1][j] = parent[i][parent[i][j]];
	
	for(int i = seg_sz - 2; i >= 0; i--){
		
		dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
	}
	
	#if 0
	rep(i, seg_sz) cerr<<dat[seg_sz - 1 + i]<<" ";cerr<<endl;
	rep(i, n) cerr<<pos[i][0]<<" "<<pos[i][1]<<endl;
	cerr<<"---"<<endl;
	#endif
	
	int qs; scanf("%d", &qs);
	
	while(qs--){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		
		if(x == 0){
			y--; z--;
			
			int p = lca(y, z);
			ll ans = 0;
			
			ans += query(0, pos[y][0] + 1, 0, 0, seg_sz);
			ans += query(0, pos[z][0] + 1, 0, 0, seg_sz);
			ans -= query(0, pos[p][0] + 1, 0, 0, seg_sz) * 2;
			ans += dat[seg_sz - 1 + pos[p][0]];
			
			printf("%lld\n", ans);
		}
		else{
			y--;
			update(pos[y][0], z);
			update(pos[y][1], -z);
		}
	}
	
	return 0;
}
