#include<queue>
#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

class edge{
public:
	int v,cost;
	edge(int v,int cost):v(v),cost(cost){}
};

int main(){
	for(int n,m,k;scanf("%d%d%d",&n,&m,&k),n;){
		vector<edge> G[100];
		int d[100][100];
		rep(u,n) rep(v,n) d[u][v]=(u==v?0:INF);
		rep(_,m){
			int u,v,cost; scanf("%d%d%d",&u,&v,&cost);
			d[u][v]=d[v][u]=cost;
			G[u].push_back(edge(v,cost));
			G[v].push_back(edge(u,cost));
		}

		rep(w,n) rep(u,n) rep(v,n) d[u][v]=min(d[u][v],d[u][w]+d[w][v]);

		double dp[100][100]={}; // dp[u][v] := ( u->v 間の最短経路の個数 )
		rep(u,n) rep(i,G[u].size()) {
			int v=G[u][i].v,cost=G[u][i].cost;
			if(d[0][u]+cost+d[v][n-1]==d[0][n-1]) dp[u][v]=1;
		}
		rep(w,n) rep(u,n) rep(v,n) dp[u][v]+=dp[u][w]*dp[w][v];

		rep(_,k){
			int c; scanf("%d",&c);
			printf("%.9f\n",dp[0][c]*dp[c][n-1]/dp[0][n-1]);
		}
		puts("");
	}

	return 0;
}