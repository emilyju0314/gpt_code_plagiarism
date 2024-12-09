#include<cstdio>
#include<vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

struct edge{
	int u,v;
	ll cost;
};

int n;
vector<edge> G[100000];

vector<edge> T[100000]; // G の全域木

bool vis[100000];
void dfs1(int u){
	vis[u]=true;
	rep(i,G[u].size()){
		edge e=G[u][i];
		if(!vis[e.v]){
			T[u].push_back(e);
			dfs1(e.v);
		}
	}
}

ll dist[100000]; // dist[u] := ( T における頂点 0-u 間の距離 )
void dfs2(int u,ll sum){
	dist[u]=sum;
	rep(i,T[u].size()){
		edge e=T[u][i];
		dfs2(e.v,sum^e.cost);
	}
}

int main(){
	int m,q; scanf("%d%d%d",&n,&m,&q);
	rep(i,m){
		int u,v;
		ll cost; scanf("%d%d%lld",&u,&v,&cost);
		G[u].push_back((edge){u,v,cost});
		G[v].push_back((edge){v,u,cost});
	}

	dfs1(0);
	dfs2(0,0);

	ll basis[60]={};
	rep(u,n) rep(i,G[u].size()) {
		edge e=G[u][i];
		ll sum=dist[e.u]^dist[e.v]^e.cost;
		int i0=-1;
		for(int i=59;i>=0;i--){
			if(sum&(1LL<<i)){
				sum^=basis[i];
				if(sum&(1LL<<i)){ i0=i; break; }
			}
		}
		if(i0!=-1) basis[i0]=sum;
	}

	while(q--){
		int u,v; scanf("%d%d",&u,&v);
		ll ans=dist[u]^dist[v];
		for(int i=59;i>=0;i--){
			if((ans&(1LL<<i))==0){
				ans^=basis[i];
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}