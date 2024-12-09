#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int n,m,a[maxn],lk[maxn];
vector<int>G[maxn];
bool vis[maxn];
bool dfs(int u){
	for(int v:G[u]) if(!vis[v]){
		vis[v]=1;
		if(!lk[v]||dfs(lk[v])) return lk[v]=u,1;
	}
	return 0;
}
inline bool check(int x){
	if(x<=2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,pre=-1,now;i<=n;i++,pre=now){
		scanf("%d",&now);
		if(pre<now-1) a[++m]=now,a[++m]=now+1;
		else a[m]=now+1;
	}
	int cnt[2]={0},ans=0;
	for(int i=1;i<=m;i++) cnt[a[i]&1]++; 
	for(int i=1;i<=m;i++) if(!(a[i]&1))
		for(int j=1;j<=m;j++) if((a[j]&1)&&check(abs(a[j]-a[i])))
			G[i].push_back(j);
	for(int i=1;i<=m;i++) if(!(a[i]&1)) memset(vis,0,sizeof vis),ans+=dfs(i);
	printf("%d\n",ans+(m-2*ans)+(cnt[0]-ans)%2);
}