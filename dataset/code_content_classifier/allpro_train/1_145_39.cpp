#include<bits/stdc++.h>
#define mod 1000000007
#define mk make_pair
#define ll long long 
#define fi first
#define se second 
#define pb push_back
using namespace std;
const int N=21,M=410;
int n,m,T,S,cnt[1<<N],mul[M][M],e[1<<N];
typedef pair<int,int>pii;
pii dp[1<<N];
vector<pii>G[N];
void inc(int&x,int y){x+=y;if(x>=mod)x-=mod;}
void adde(int u,int v,int w){
	G[u].pb(mk(v,w));
	G[v].pb(mk(u,w));
}
int dfs(int u,int fa=0){
	if(u==T)return 0;
	for(int i=0,t;i<(int)G[u].size();++i){
		int v=G[u][i].fi,w=G[u][i].se;
		if(v==fa||!~(t=dfs(v,u)))continue;
		return t|(1<<(w-1));
	}
	return -1;
}
int main(){
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	scanf("%d%d",&n,&m);
	int all=1<<(n-1),tot=m-n+1;
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v,i);
	}
	for(int i=1;i<=tot;++i){
		int u,v,t;
		scanf("%d%d",&u,&v);
		T=v;t=dfs(u);
		e[(all-1)^t]++;
	}
	for(int i=1;i<n;++i)
	for(int j=0;j<all;++j)if(j>>(i-1)&1){
		e[j^(1<<(i-1))]+=e[j];
	}
	for(int i=0;i<all;++i){
		cnt[i]=cnt[i>>1]+(i&1);
		e[i]=tot-e[i];
	}
	for(int i=1;i<=m+1;++i){
		mul[i][i-1]=1;
		for(int j=i;j<=m+1;++j){
			mul[i][j]=(ll)mul[i][j-1]*j%mod;	
		}
	}
	dp[0]=mk(1,0);
	for(int i=0;i<all;++i)
	for(int j=1;j<n;++j)if(!(i>>(j-1)&1)){
		int b=cnt[i],a=b+e[i],c=dp[i].fi,s=dp[i].se;
		int ni=i|(1<<(j-1)),k=e[ni]-e[i];
		c=(ll)c*mul[a+1][a+k]%mod;
		s=(ll)s*mul[a+2][a+k+1]%mod;
		inc(s,(ll)c*(b+1)%mod);
		inc(dp[ni].fi,c);
		inc(dp[ni].se,s);
	}
	cout<<dp[all-1].se<<endl;
	return 0;
}