#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M=5e5+5;

int max(int x,int y){ return x>y?x:y; }
int min(int x,int y){ return x<y?x:y; }

int read(){
	int x=0,y=1;char ch=getchar();
	while(ch<'0'||ch>'9') y=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*y;
}

int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}

int tot=0,first[M];
struct Edge{ int nxt,to,w; }e[M];
void add(int x,int y,int w){
	e[++tot]=(Edge){first[x],y,w},first[x]=tot;
}

int num=0,top=0,cnt=0,col[M],dfn[M],low[M],sta[M];bool ins[M],vis[M];
void tarjan(int u){
	dfn[u]=low[u]=++num,ins[sta[++top]=u]=1;
	for(int i=first[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cnt++;
		for(int x=sta[top--];x!=u;x=sta[top--]) col[x]=cnt,ins[x]=0;
		col[u]=cnt,ins[u]=0;
	}
}
int g[M],dis[M];
void dfs(int u){
	vis[u]=1;
	for(int i=first[u];i;i=e[i].nxt){
		int v=e[i].to,w=e[i].w;if(col[u]!=col[v]) continue ;
		if(!vis[v]) dis[v]=dis[u]+w,dfs(v);
		else{
			int cur=dis[u]+w-dis[v];
			if(!g[col[u]]) g[col[u]]=cur;
			else if(cur) g[col[u]]=gcd(g[col[u]],cur);
		}
	}
}

void solve(){
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),w=read();
		add(x,y,w);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
//	for(int i=1;i<=n;i++) printf("%d ",col[i]);printf("\n");
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
//	for(int i=1;i<=cnt;i++) printf("%d ",g[i]);printf("\n");
	int q=read();
	while(q--){
		int x=read(),s=read(),t=read();
		if(!g[col[x]]) s?puts("NO"):puts("YES");
		else s%gcd(g[col[x]],t)?puts("NO"):puts("YES");
	}
}

signed main(){
	solve();
}