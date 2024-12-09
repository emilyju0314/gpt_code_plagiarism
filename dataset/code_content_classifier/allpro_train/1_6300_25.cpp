#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<62;
const double eps=1e-5;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct UnionFind{
	vector<ll> par,siz,s;
	UnionFind(int n){
		s.resize(n,0);
		par.resize(n);
		siz.resize(n,1);
		for(int i=0;i<n;i++)par[i]=i;
	}
	int find(int x){
		return (par[x]==x?x:find(par[x]));
	}
	void unite(int u,int v,ll c){
		u=find(u);v=find(v);
		if(u==v)return;
		if(siz[u]<siz[v])swap(u,v);
		par[v]=u;
		s[u]+=siz[v]*c;
		s[v]+=siz[u]*c;
		s[v]-=s[u];
		siz[u]+=siz[v];
	}
	ll ans(int x){
		return (par[x]==x?s[x]:ans(par[x])+s[x]);
	}
};
int main(){
	int n;cin>>n;
	vector<pair<ll,P>> v;
	for(int i=0;i<n-1;i++){
		int a,b,c;cin>>a>>b>>c;--a;--b;
		v.push_back(mp(c,mp(b,a)));
	}
	sort(all(v));
	reverse(all(v));
	UnionFind uf(n);
	for(int i=0;i<n-1;i++){
		ll c=v[i].first;int a=v[i].second.first,b=v[i].second.second;
		uf.unite(a,b,c);
	}
	for(int i=0;i<n;i++){
		cout<<uf.ans(i)<<endl;
	}
}
