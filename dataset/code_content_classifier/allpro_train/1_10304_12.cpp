#include<bits/stdc++.h>

using namespace std;

constexpr long long INF64 = 1e18;

using Weight=long long;

struct Edge{
    int src,dst;
    Edge(int src,int dst):
    src(src),dst(dst){}
};

using Edges=vector<Edge>;
using Graph=vector<Edges>;

vector<int> tarjan(const Graph& g) {
	int n = g.size(), idx = 0, k = 0, s = 0;
	vector<int>ord(n, -1), low(n), onS(n), cmp(n), stk(n);
	function<void(int)>dfs;
	dfs = [&](int v) {
		ord[v] = low[v] = idx++;
		stk[s++] = v;
		onS[v] = true;
		for (auto &e : g[v]) {
			int w = e.dst;
			if (ord[w] == -1) {
				dfs(w);
				low[v] = min(low[v], low[w]);
			}
			else if (onS[w]) {
				low[v] = min(low[v], ord[w]);
			}
		}
		if (low[v] == ord[v]) {
			while (1) {
				int w = stk[--s];
				onS[w] = false;
				cmp[w] = k;
				if (w == v)break;
			}
			++k;
		}
	};
	for (int v = 0; v<n; ++v)
		if (ord[v] == -1)dfs(v);
	return cmp;
}

int dfs(const Graph &g,int s,vector<int> &memo){
	int ret=1;
	if(memo[s])return memo[s];
	for(auto e:g[s]){
		ret=max(dfs(g,e.dst,memo)+1,ret);
	}
	return memo[s]=ret;
}

int main(){
	int n;
	cin>>n;
	Graph g(n);
	vector<pair<int,int>>contri(n);
	vector<vector<pair<int,int>>>friends(n);
	for(int i=0;i<n;++i){
		int a;
		cin>>a;
		contri[i]=make_pair(a,i);
		friends[i].push_back(contri[i]);
	}
	int m;
	cin>>m;
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		friends[a].push_back(contri[b]);
		friends[b].push_back(contri[a]);
	}
	for(auto x:friends){
		sort(x.begin(),x.end(),greater<pair<int,int>>());
		for(int i=0;i<x.size()-1;++i){
			g[x[i].second].emplace_back(x[i].second,x[i+1].second);
			if(x[i].first==x[i+1].first){
				g[x[i+1].second].emplace_back(x[i+1].second,x[i].second);
			}
		}
	}
	vector<int>idx=tarjan(g);
	Graph ng(n);
	for(auto es:g){
		for(auto e:es){
			if(idx[e.src]==idx[e.dst])continue;
			ng[idx[e.src]].emplace_back(idx[e.src],idx[e.dst]);
		}
	}
	vector<int>memo(n,0);
	for(auto es:ng){
		if(es.size()>=1)dfs(ng,es[0].src,memo);
	}
	Weight ans=0;
	for(auto x:idx){
		if(!memo[x])memo[x]=1;
		ans+=memo[x];
	}
	cout<<ans<<endl;
	return 0;
}