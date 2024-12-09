#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;
typedef long long ll;

int par[210],sz[210];
void init(int n){
	for(int i=0;i<n;i++){
		par[i] = i; sz[i] = 1;
	}
}

int find(int x){
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

void unite(ll x, ll y){
	x = find(x); y = find(y);
	if(x==y) return;
	if(sz[x]<sz[y]) swap(x,y);
	par[y] = x; sz[x] += sz[y];
}

bool same(ll x, ll y){
	return find(x)==find(y);
}

struct edge{ll u,v,cost,num;};
vector<edge> E;
bool comp1(const edge& e1, const edge& e2){
	if(e1.cost!=e2.cost) return e1.cost<e2.cost;
	else return e1.num<e2.num;
}

bool comp2(const edge& e1, const edge& e2){
	if(e1.cost!=e2.cost) return e1.cost<e2.cost;
	else return e1.num>e2.num;
}

pair<ll,ll> kruscal(int n,ll w,int x){
	int i; pair<ll,ll> p = {0,0};
	for(i=0;i<E.size();i++){
		if(E[i].num==1) E[i].cost += w;
	}
	if(x==0) sort(E.begin(),E.end(),comp1);
	if(x==1) sort(E.begin(),E.end(),comp2);
	init(n);
	for(i=0;i<E.size();i++){
		edge e = E[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			p.first += e.cost;
			p.second += 1 - e.num;
		}
	}
	for(i=0;i<E.size();i++){
		if(E[i].num==1) E[i].cost -= w;
	}
	if(sz[find(0)]<n) p.second = -1;
	return p;
}

int main(){
	while(true){
		int i,n,m,k;
		cin >> n >> m >> k;
		if(n + m + k==0) break;
		E.clear();
		int cnt = 0;
		for(i=0;i<m;i++){
			ll u,v,w; char c;
			cin >> u >> v >> w >> c;
			u--; v--;
			ll l = 0 + (c=='B');
			E.push_back({u,v,w,l});
		}
		ll inf = 1000000000000;
		if(kruscal(n,inf,0).second<k || kruscal(n,-inf,0).second>k){
			cout << -1 << endl;
		}else{
			ll r = inf,l = -inf;
			while(r - l>1){
				ll mid = (l + r)/2;
				if(kruscal(n,mid,0).second<k) l = mid;
				else r = mid;
			}
			cout << kruscal(n,r,0).first - r*(n - k - 1) << endl;
			ll x = kruscal(n,r - 1,0).second,y = kruscal(n,r,1).second;
			assert(x==y);
		}
	}
}
