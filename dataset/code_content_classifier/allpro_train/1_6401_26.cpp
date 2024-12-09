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
const int inf = (int)1e9 + 100000;
const double INF = 1e12, EPS = 1e-9;

template<class T>struct SegTree{
	T *ans, *sum, *left, *right, *lazy;
	
	int n;
	SegTree(int size = 1000000){
		for(n = 1; n < size; n *= 2);
		ans = new T[2 * n - 1];
		sum = new T[2 * n - 1];
		left = new T[2 * n - 1];
		right = new T[2 * n - 1];
		lazy = new T[2 * n - 1];
		
		rep(i, 2 * n - 1) sum[i] = ans[i] = right[i] = left[i] = 0, lazy[i] = inf;
	}
	~SegTree(){
		delete ans; delete sum;
		delete left; delete right;
		delete lazy;
	}
	
	inline void fix(int i){
		int l = i * 2 + 1, r = i * 2 + 2;
		ans[i] = max(max(ans[l], ans[r]), left[r] + right[l]);
		sum[i] = sum[l] + sum[r];
		left[i] = max(sum[l] + left[r], left[l]);
		right[i] = max(sum[r] + right[l], right[r]);
	}
	inline void lazyfix(int k, int l, int r){
		if(lazy[k] == inf) return;
		update(l, (l + r) / 2, lazy[k], k * 2 + 1, l, (l + r) / 2);
		update((l + r) / 2, r, lazy[k], k * 2 + 2, (l + r) / 2, r);
		lazy[k] = inf;
	}
	
	void init(){
		for(int i = n - 2; i >= 0; i--) fix(i);
	}
	inline void update(int a, int b, T x){
		update(a, b, x, 0, 0, n);
	}
	
	inline void update(int a, int b, T x, int k, int l, int r){
		
		if(b <= l || a >= r) return;
		if(a <= l && r <= b){
			lazy[k] = x;
			left[k] = right[k] = ans[k] = x >= 0 ? (r - l) * x : x;
			sum[k] = (r - l) * x;
			return;
		}
		lazyfix(k, l, r);
		
		int lch = k * 2 + 1, rch = k * 2 + 2;
		update(a, b, x, lch, l, (l + r) / 2);
		update(a, b, x, rch, (l + r) / 2, r);
		fix(k);
	}
	
	#define LEFT a, b, k * 2 + 1, l, (l + r) / 2
	#define RIGHT a, b, k * 2 + 2, (l + r) / 2, r
	
	inline T query(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return -inf;
		if(a <= l && r <= b) return ans[k];
		lazyfix(k, l, r);
		
		int vl = query(LEFT);
		int vr = query(RIGHT);
		int vll = queryRight(LEFT);
		int vrr = queryLeft (RIGHT);
		return max(max(vl, vr), vll + vrr);
	}
	inline T querySum(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return sum[k];
		lazyfix(k, l, r);
		
		int vl = querySum(LEFT);
		int vr = querySum(RIGHT);
		return vl + vr;
	}
	inline T queryRight(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return -inf;
		if(a <= l && r <= b) return right[k];
		lazyfix(k, l, r);
		
		int R = queryRight(RIGHT);
		int rsum = querySum(RIGHT);
		int lr = queryRight(LEFT);
		return max(R, rsum + lr);
	}
	inline T queryLeft(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return -inf;
		if(a <= l && r <= b) return left[k];
		lazyfix(k, l, r);
		
		int L = queryLeft(LEFT);
		int lsum = querySum(LEFT);
		int rl = queryLeft(RIGHT);
		return max(L, lsum + rl);
	}
	#undef LEFT
	#undef RIGHT
};

const int MX = 200000;
const int MX_L=18;

SegTree<int> *st[MX];
int st_root[MX];
int st_sz;

int n, q;
int w[MX];
int sz[MX];
int parent[MX_L][MX];
int depth[MX];
int which[MX];

vector<vi> e;

void size_rec(int, int);
void heavy_light_rec(int, int, int);
void segtest();

void fix(int a, int b, int c){
	while(1){
		if(which[a] < 0){
			w[a] = c;
			if(a == b) break;
			a = parent[0][a];
		}
		else{
			int v = st_root[which[a]];
			int base = depth[v];
			
			if(depth[v] <= depth[b]) v = b;
			int da = depth[a] - base;
			int dv = depth[v] - base;
			
			st[which[a]]->update(dv, da + 1, c);
			if(v == b) break;
			a = parent[0][v];
		}
	}
}
pi calc(int a, int b){
	int res = -inf, resleft = -inf;
	
	while(1){
		if(which[a] < 0){
			res = max(res, max(w[a], resleft > -inf ? w[a] + resleft : -inf));
			resleft = max(w[a], resleft > -inf ? w[a] + resleft : -inf);
			if(a == b) break;
			a = parent[0][a];
		}
		else{
			int v = st_root[which[a]];
			int base = depth[v];
			
			if(depth[v] <= depth[b]) v = b;
			int da = depth[a] - base;
			int dv = depth[v] - base;
			
			int m = st[which[a]]->n;
			int Q = st[which[a]]->query(dv, da + 1, 0, 0, m);
			int L = st[which[a]]->queryLeft(dv, da + 1, 0, 0, m);
			int R = st[which[a]]->queryRight(dv, da + 1, 0, 0, m);
			int S = st[which[a]]->querySum(dv, da + 1, 0, 0, m);
			
			res = max(res, max(Q, resleft > -inf ? R + resleft : -inf));
			resleft = max(resleft > -inf ? S + resleft : -inf, L);
			if(v == b) break;
			a = parent[0][v];
		}
	}
	
	return mp(res, resleft);
}

void run(){
	scanf("%d%d", &n, &q);
	rep(i, n) scanf("%d", w + i);
	
	e.resize(n);
	rep(i, n - 1){
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		e[a].pb(b); e[b].pb(a);
	}
	memset(which, -1, sizeof(which));
	size_rec(0, 0);
	heavy_light_rec(0, 0, -1);
	
	rep(i, MX_L - 1) rep(j, n) parent[i + 1][j] = parent[i][parent[i][j]];
	
	
	while(q--){
		int t, aa, bb, c, v;
		scanf("%d%d%d%d", &t, &aa, &bb, &c);
		aa--; bb--;
		if(depth[aa] > depth[bb]) swap(aa, bb);
		
		int a = aa, b = bb;
		int d = depth[b] - depth[a];
		
		rep(i, MX_L) if(d & 1 << i) b = parent[i][b];
		if(a == b) v = a;
		else{
			for(int i = MX_L - 1; i >= 0; i--) if(parent[i][a] != parent[i][b]){
				a = parent[i][a];
				b = parent[i][b];
			}
			v = parent[0][a];
		}
		
		if(t == 1){
			fix(aa, v, c); fix(bb, v, c);
		}
		else{
			if(v == aa){
				printf("%d\n", calc(bb, aa).first);
			}
			else{
				pi x = calc(aa, a), y = calc(bb, v);
				int ans = max(max(x.first, y.first), x.second + y.second);
				
				printf("%d\n", ans);
			}
		}
	}
}

void size_rec(int c, int p){
	sz[c] = 1;
	depth[c] = c == p ? 0 : depth[p] + 1;
	parent[0][c] = p;
	rep(i, e[c].size()) if(e[c][i] != p){
		size_rec(e[c][i], c);
		sz[c] += sz[e[c][i]];
	}
}
void heavy_light_rec(int c, int p, int root){
	
	bool found = 0;
	
	rep(i, e[c].size()){
		int to = e[c][i];
		if(to == p) continue;
		
		if(2 * sz[to] >= sz[c]){
			heavy_light_rec(to, c, root < 0 ? c : root);
			found = 1;
		}
		else heavy_light_rec(to, c, -1);
	}
	if(!found && root >= 0){
		int size = depth[c] - depth[root] + 1;
		SegTree<int> *t = st[st_sz] = new SegTree<int>(size);
		st_root[st_sz] = root;
		
		for(int v = c, k = size - 1 + t->n - 1; ; v = parent[0][v], k--){
			which[v] = st_sz;
			t->left[k] = t->right[k] = t->ans[k] = w[v];
			t->sum[k] = w[v];
			if(v == root) break;
		}
		t->init();
		st_sz++;
	}
}
long long esp_org, esp_new;
int main(){
	const int size = 128*1024*1024;
	void *p = malloc(size);
	esp_new = (long long)p + size - 1;
	
	
	__asm__("mov %%rsp, %0" : "=r"(esp_org) : : );
	__asm__("mov %0, %%rsp" : : "r"(esp_new) : );
	
	run();
	
	__asm__("mov %0, %%rsp" : : "r"(esp_org) : );
	free(p);
	return 0;
}