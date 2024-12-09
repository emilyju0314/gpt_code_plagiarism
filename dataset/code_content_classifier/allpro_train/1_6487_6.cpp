#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

template<typename Monoid, typename OperatorMonoid=Monoid>
struct LazySegmentTree{
	using F=function<Monoid(Monoid, Monoid)>;
	using G=function<Monoid(Monoid, OperatorMonoid, int)>;
	using H=function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
	int sz;
	vector<Monoid> data;
	vector<OperatorMonoid> lazy;
	const F f;
	const G g;
	const H h;
	const Monoid e1;
	const OperatorMonoid e0;

	LazySegmentTree(int n, const F f, const G g, const H h, const Monoid &e1, const OperatorMonoid &e0): f(f), g(g), h(h), e1(e1), e0(e0){
		sz=1;
		while(sz<n) sz<<=1;
		data.resize(2*sz-1, e1);
		lazy.resize(2*sz-1, e0);
	}

	void build(vector<Monoid> v){
		for(int i=0; i<v.size(); i++) data[i+sz-1]=v[i];
		for(int i=sz-2; i>=0; i--) data[i]=f(data[2*i+1], data[2*i+2]);
	}

	void eval(int k, int l, int r){
		if(lazy[k]!=e0){
			data[k]=g(data[k], lazy[k], r-l);
			if(k<sz-1){
				lazy[2*k+1]=h(lazy[2*k+1], lazy[k]);
				lazy[2*k+2]=h(lazy[2*k+2], lazy[k]);
			}
		}
		lazy[k]=e0;
	}

	void update(int a, int b, const OperatorMonoid &x, int k, int l, int r){
		eval(k, l, r);
		if(r<=a || b<=l) return;
		if(a<=l && r<=b){
			lazy[k]=h(lazy[k], x);
			eval(k, l, r);
		}else{
			update(a, b, x, 2*k+1, l, (l+r)/2);
			update(a, b, x, 2*k+2, (l+r)/2, r);
			data[k]=f(data[2*k+1], data[2*k+2]);
		}
	}
	void update(int a, int b, const OperatorMonoid &x){
		return update(a, b, x, 0, 0, sz);
	}

	Monoid find(int a, int b, int k, int l, int r){
		eval(k, l, r);
		if(b<=l || r<=a) return e1;
		if(a<=l && r<=b) return data[k];
		else return f(find(a, b, 2*k+1, l, (l+r)/2), find(a, b, 2*k+2, (l+r)/2, r));
	}
	Monoid find(int a, int b){
		return find(a, b, 0, 0, sz);
	}
	Monoid operator[](const int &k){
		return find(k, k+1);
	}
};
template<typename Monoid>
struct SegmentTree{
	using F=function<Monoid(Monoid, Monoid)>;
	int sz;
	vector<Monoid> seg;
	const F f;
	const Monoid e;

	SegmentTree(int n, const F f, const Monoid &e): f(f), e(e){
		sz=1;
		while(sz<n) sz<<=1;
		seg.resize(2*sz, e);
	}

	SegmentTree(int n, const F f, const Monoid &e, vector<Monoid> v): f(f), e(e){
		sz=1;
		while(sz<n) sz<<=1;
		seg.resize(2*sz, e);
		for(int i=0; i<n; i++) seg[i+sz]=v[i];
		for(int i=sz-1; i>=1; i--){
			seg[i]=f(seg[2*i], seg[2*i+1]);
		}
	}

	void update(int k, const Monoid &x){
		k+=sz;
		seg[k]=x;
		while(k>1){
			k>>=1;
			seg[k]=f(seg[2*k], seg[2*k+1]);
		}
	}

	Monoid query(int a, int b){
		a+=sz, b+=sz;
		Monoid ret=e;
		for(;a<b; a>>=1, b>>=1){
			if(b&1) ret=f(ret, seg[--b]);
			if(a&1) ret=f(ret, seg[a++]);
		}
		return ret;
	}

	Monoid operator[](const int &k) const{
		return seg[k+sz];
	}
};
int q;
int t[50050], a[50050], b[50050], y[50050];
int s[100010];
vector<int> upd;
vector<int> va[100010], vb[100010];
int main()
{
	scanf("%d", &q);
	vector<int> v;
	for(int i=0; i<q; i++){
		scanf("%d %d %d %d", &t[i], &a[i], &b[i], &y[i]);
		a[i]--;
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int m=v.size();
	auto f=[](int a, int b){ return min(a, b);};
	auto g=[](int a, int x, int len){ return x;};
	auto h=[](int x, int y){ return y;};
	const int INF=1e9+7;
	LazySegmentTree<int> seg1(m, f, g, h, INF, INF);
	for(int i=q-1; i>=0; i--){
		a[i]=lower_bound(v.begin(), v.end(), a[i])-v.begin();
		b[i]=lower_bound(v.begin(), v.end(), b[i])-v.begin();
		if(t[i]==1) seg1.update(a[i], b[i], i);
	}
	for(int i=0; i<m; i++) s[i]=seg1[i];
	auto f2=[](int a, int b){ return max(a, b);};
	SegmentTree<int> seg2(q, f2, -1);
	for(int i=0; i<q; i++){
		if(t[i]==0){
			va[a[i]].push_back(i);
			vb[b[i]].push_back(i);
		}
	}
	upd.resize(m);
	for(int i=0; i<m; i++){
		for(auto x:va[i]){
			seg2.update(x, y[x]);
		}
		for(auto x:vb[i]){
			seg2.update(x, -1);
		}
		upd[i]=seg2.query(0, min(q, s[i]));
		if(upd[i]==-1) upd[i]=INF;
	}
	LazySegmentTree<int> seg(m, f, g, h, INF, INF);
	seg.build(upd);
	for(int i=0; i<q; i++){
		if(t[i]==1) seg.update(a[i], b[i], y[i]);
		else if(seg.find(a[i], b[i])!=y[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
    return 0;
}
