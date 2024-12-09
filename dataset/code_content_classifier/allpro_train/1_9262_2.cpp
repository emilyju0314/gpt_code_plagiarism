#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

const int V_MAX=300;
const int E_MAX=V_MAX-1;
const int T_MAX=10000;

struct edge{ int v,cost,capa,val; };

int n;
vector<edge> G[V_MAX]; // tree

vector< pair<edge,int> > order; // <<to,cost,capa,val>,forward or backward>

void dfs(int u,int pre){
	int cost_parent=0,capa_parent=0,val_parent=0;

	rep(i,G[u].size()){
		int v=G[u][i].v,cost=G[u][i].cost,capa=G[u][i].capa,val=G[u][i].val;
		if(v!=pre){
			order.push_back(make_pair((edge){u,cost,capa,val},0)); // forward
			dfs(v,u);
		}
		else{
			cost_parent=cost;
			capa_parent=capa;
			val_parent=val;
		}
	}

	order.push_back(make_pair((edge){u,cost_parent,capa_parent,val_parent},1)); // backward
}

int main(){
	int T; scanf("%d%d",&n,&T);
	rep(u,n) G[u].clear();
	rep(i,n-1){
		int u,v,cost,capa,val;
		scanf("%d%d%d%d%d",&u,&v,&cost,&capa,&val); u--; v--;
		G[u].push_back((edge){v,cost,capa,val});
		G[v].push_back((edge){u,cost,capa,val});
	}

	order.clear();
	dfs(0,-1);

	int m=order.size();
	static int pre[V_MAX+E_MAX];
	rep(i,m){
		pre[i]=-1;
		int u=order[i].first.v;
		rep(j,i){
			int v=order[j].first.v;
			if(u==v) pre[i]=j;
		}
	}

	static int dp[V_MAX+E_MAX][T_MAX+1];
	rep(i,m) rep(j,T+1) dp[i][j]=-INF;
	dp[0][0]=0;
	for(int i=1;i<m;i++){
		int cost=order[i-1].first.cost;
		int capa=order[i-1].first.capa;
		int val=order[i-1].first.val;
		int dir=order[i-1].second;

		rep(j,T+1) if(pre[i]!=-1) dp[i][j]=max(dp[i][j],dp[pre[i]][j]);

		if(dir==0){ // forward
			if(capa%2==1){
				for(int j=(capa+1)*cost;j<=T;j++){
					dp[i][j]=max(dp[i][j],dp[i-1][j-(capa+1)*cost]+capa*val);
				}
				capa--;
			}

			if(capa==0){
				for(int j=2*cost;j<=T;j++) dp[i][j]=max(dp[i][j],dp[i-1][j-2*cost]);
			}
			else{ // capa>=2
				capa-=2;
				for(int c=2;capa>0;c*=2){ // O(log capa) 個の商品に分割
					c=min(c,capa);
					for(int j=T;j>=c*cost;j--){
						dp[i-1][j]=max(dp[i-1][j],dp[i-1][j-c*cost]+c*val);
					}
					capa-=c;
				}

				for(int j=2*cost;j<=T;j++) dp[i][j]=max(dp[i][j],dp[i-1][j-2*cost]+2*val);
			}
		}
		else{ // backward
			rep(j,T+1) dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}

	printf("%d\n",*max_element(dp[m-1],dp[m-1]+T+1));

	return 0;
}