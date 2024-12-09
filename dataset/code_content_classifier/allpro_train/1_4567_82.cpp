#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=5e3+10,mod=1e9+7;
void upd(int &x,int y){ x=x+y-mod; x+=x>>31&mod; }
int n,c[N];
vi g[N];
int dp[N][N],siz[N];
void dfs(int u,int f){
	siz[u]=1;
	dp[u][1]=1;
	for (auto v:g[u]) if (v!=f){
		dfs(v,u);
		static int d[N];
		for (int i=0;i<=siz[u]+siz[v];i++) d[i]=0;
		for (int i=1;i<=siz[u];i++){
			for (int j=1;j<=siz[v];j++){
				upd(d[i],mod-(ll)dp[u][i]*dp[v][j]%mod*c[j]%mod);
				upd(d[i+j],(ll)dp[u][i]*dp[v][j]%mod);
			}
		}
		for (int i=1;i<=siz[u]+siz[v];i++) dp[u][i]=d[i];
		siz[u]+=siz[v];
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v),g[v].pb(u);
	}
	c[0]=1;
	for (int i=2;i<=n;i+=2) c[i]=(ll)c[i-2]*(i-1)%mod;
	dfs(1,0);
	int ans=0;
	for (int i=2;i<=n;i+=2) upd(ans,(ll)dp[1][i]*c[i]%mod);
	printf("%d\n",ans);
	return 0;
}