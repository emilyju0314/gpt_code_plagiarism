#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 200050;
int n, q, A, lst;
LL tag, mn[MAXN<<2][2];
void build(int i, int l, int r) {
	if(l == r) {
		mn[i][0] = abs(l-A) - l;
		mn[i][1] = abs(l-A) + l;
		return;
	}
	int mid = (l + r) >> 1;
	build(i<<1, l, mid);
	build(i<<1|1, mid+1, r);
	mn[i][0] = min(mn[i<<1][0], mn[i<<1|1][0]);
	mn[i][1] = min(mn[i<<1][1], mn[i<<1|1][1]);
}
LL qry(int i, int l, int r, int x, int y, int o) {
	if(x <= l && r <= y) return mn[i][o];
	int mid = (l + r) >> 1; LL re = 1ll<<60;
	if(x <= mid) re = min(re, qry(i<<1, l, mid, x, y, o));
	if(y > mid) re = min(re, qry(i<<1|1, mid+1, r, x, y, o));
	return re;
}
void upd(int i, int l, int r, int x, LL val) {
	if(l == r) {
		if(val < mn[i][0]+l+tag) {
			mn[i][0] = val-tag-l;
			mn[i][1] = val-tag+l;
		}
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) upd(i<<1, l, mid, x, val);
	else upd(i<<1|1, mid+1, r, x, val);
	mn[i][0] = min(mn[i<<1][0], mn[i<<1|1][0]);
	mn[i][1] = min(mn[i<<1][1], mn[i<<1|1][1]);
}
LL ans;
void dfs(int i, int l, int r) {
	if(l == r) {
		ans = min(ans, mn[i][0]+l+tag);
		return;
	}
	int mid = (l + r) >> 1;
	dfs(i<<1, l, mid);
	dfs(i<<1|1, mid+1, r);
}
int main () {
	scanf("%d%d%d%d", &n, &q, &lst, &A);
	build(1, 1, n);
	for(int i = 1, x; i <= q; lst = x, ++i) {
		scanf("%d", &x);
		LL val = qry(1, 1, n, 1, x, 0) + tag + x;
		if(x < n) val = min(val, qry(1, 1, n, x+1, n, 1) + tag - x);
		tag += abs(x-lst);
		upd(1, 1, n, lst, val);
	}
	ans = 1ll<<60;
	dfs(1, 1, n);
	printf("%lld\n", ans);
}