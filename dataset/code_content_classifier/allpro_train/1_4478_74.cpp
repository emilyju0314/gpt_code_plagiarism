#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=1e9+7;
struct Edge{
	int next,to;
}edge[N*2];
int n,fi[N],se,f[N],ans[N],inv[N],fac[N],size[N];
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
inline int C(int n,int m){return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
inline int fC(int n,int m){return 1ll*inv[n]*fac[m]%mo*fac[n-m]%mo;}
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for(int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo,
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
}
void dfs(int x,int fa){
	f[x]=size[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);size[x]+=size[v];
		f[x]=1ll*f[x]*C(size[x]-1,size[v])%mo*f[v]%mo;
	}
}
void dfs1(int x,int fa){
	int w=1ll*ans[fa]*fC(n-1,size[x])%mo*Pow(f[x],mo-2)%mo;
	if(!fa)ans[x]=f[x];
	else ans[x]=1ll*f[x]*C(n-1,size[x]-1)%mo*w%mo;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs1(v,x);
	}
}
int main(){
	init();
	int u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	dfs1(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}