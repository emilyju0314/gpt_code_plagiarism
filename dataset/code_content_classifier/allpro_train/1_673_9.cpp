#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

int n, k;
const int M = 524288;

int fen[500010];
int fens(int p){
	int ret=0;
	while(p) ret+=fen[p], p&=(p-1);
	return ret;
}
void fenu(int p, int v){
	while(p<=n) fen[p]+=v, p+=(p&-p);
}
int fenr(int l, int r){
	l=max(l, 0); r=min(r, n);
	return fens(r)-(l?fens(l-1):0);
}

pp tree[M<<1];
int lazy[M<<1];
void uke(int p, int v){
	tree[p].first += v;
	lazy[p] += v;
}
void pd(int p, int l, int r){
	if(l==r || !lazy[p]) return;
	uke(p*2, lazy[p]);
	uke(p*2+1, lazy[p]);
	lazy[p]=0;
}
void upd(int pt, int v, int l=1, int r=n, int p=1){
	pd(p, l, r);
	if(l==r){
		tree[p]={v, l};
		return;
	}
	int mid=(l+r)/2;
	if(pt<=mid) upd(pt, v, l, mid, p*2);
	else upd(pt, v, mid+1, r, p*2+1);
	tree[p]=min(tree[p*2], tree[p*2+1]);
}

void updr(int ul, int ur, int l=1, int r=n, int p=1){
	pd(p, l, r);
	if(ul<=l && r<=ur){
		uke(p, -1);
		return;
	}
	if(ur<l || r<ul) return;
	int mid=(l+r)/2;
	updr(ul, ur, l, mid, p*2);
	updr(ul, ur, mid+1, r, p*2+1);
	tree[p]=min(tree[p*2], tree[p*2+1]);
}

int a[500010];
int ans[500010];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i){
		int x; scanf("%d", &x); a[x]=i;
	}
	for(auto& x:tree) x={2e9, 0};
	for(int i=1; i<=n; ++i){
		int x=a[i];
		int indeg = fenr(x-k+1, x+k-1);
		fenu(x, 1);
		upd(x, indeg);
	}
	for(int i=1; i<=n; ++i){
		int x=tree[1].second;
		ans[x]=i;
		upd(x, 2e9);
		updr(max(1, x-k+1), min(n, x+k-1));
	}
	for(int i=1; i<=n; ++i){
		printf("%d\n", ans[i]);
	}
	return 0;
}
