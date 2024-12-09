#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using edge=tuple<int,int,int>;
using ll=long long;


const int vmax=200010;
int par[vmax],sz[vmax];
void init(){rep(i,vmax) par[i]=i,sz[i]=1;}
int find(int x){ 
	if(par[x]==x){
		return x;
	}else{
		sz[par[x]]+=sz[x],sz[x]=0;
		par[x]=find(par[x]);
		return par[x];
	}
}

void unite(int a,int b){a=find(a);b=find(b);par[a]=b;find(a);}


int main(void){
	int n;
	cin >> n;
	init();
	vector<edge> graph;
	rep(i,n-1){
		int a,b,c;
		cin >> a >> b >> c;
		graph.push_back(edge(c,a,b));
	}
	sort(graph.begin(),graph.end());

	ll ans=0LL;
	for(auto &e:graph){
		int a,b,c;
		tie(c,a,b)=e;
		a=find(a),b=find(b);
		ans+=1LL*sz[a]*sz[b]*c;
		unite(a,b);
	}
	cout << ans << endl;
	return 0;
}