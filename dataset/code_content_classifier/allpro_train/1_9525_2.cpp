#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int V_MAX=100000;

struct edge{ int v,id; };

int main(){
	int n,m; scanf("%d%d",&n,&m);
	static vector<edge> G[V_MAX],H[V_MAX];
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].push_back((edge){v,i});
		H[v].push_back((edge){u,i});
	}

	static int dp1[V_MAX];
	rep(u,n) rep(i,G[u].size()) {
		int v=G[u][i].v;
		dp1[v]=max(dp1[v],dp1[u]+1);
	}

	static int dp2[V_MAX];
	for(int u=n-1;u>=0;u--) rep(i,H[u].size()) {
		int v=H[u][i].v;
		dp2[v]=max(dp2[v],dp2[u]+1);
	}

	int L=*max_element(dp1,dp1+n);

	static int cnt[V_MAX],id[V_MAX];
	rep(u,n) rep(i,G[u].size()) {
		int v=G[u][i].v;
		if(dp1[u]+1+dp2[v]==L) cnt[dp1[u]]++, id[dp1[u]]=G[u][i].id;
	}

	vector<int> ans;
	rep(i,n) if(cnt[i]==1) ans.push_back(id[i]);
	sort(ans.begin(),ans.end());

	if(ans.empty()) puts("-1");
	rep(i,ans.size()) printf("%d\n",ans[i]+1);

	return 0;
}