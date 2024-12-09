#include <cstring>
#include <cstdio>
const int N=100005;
int fi[N],ne[N],fst[N],ans[N],n,tot=0;
bool f[N],g[N];
struct Edge{
	int to,nxt;
}e[N*2];
void addedge(int x,int y){
	e[++tot].to=y;e[tot].nxt=fst[x];fst[x]=tot;
	e[++tot].to=x;e[tot].nxt=fst[y];fst[y]=tot;
}
void add(int &x,int y){
	if (!y) return;
	if (x) addedge(x,y),x=0;
		else x=y;
}
int dfs(int x){
	f[x]=1;int y=0;
	for (int i=fi[x];i;i=ne[i]){
		f[x]^=1;
		add(y,dfs(i));
	}
	if (f[x]) add(y,x);
	return y;
}
void work(){
	memset(fi,0,sizeof fi);
	int rt=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (x==-1) rt=i;
			else ne[i]=fi[x],fi[x]=i;
	}
	dfs(rt);
}
void dfs2(int x,int v){
	if (ans[x]) return;
	ans[x]=v;
	for (int i=fst[x];i;i=e[i].nxt)
		dfs2(e[i].to,-v);
}
int main(){
	scanf("%d",&n);
	work();
	memcpy(g,f,sizeof f);
	work();
	for (int i=1;i<=n;i++)
		if (f[i]!=g[i]){
			printf("IMPOSSIBLE\n");
			return 0;
		}
	for (int i=1;i<=n;i++)
		if (f[i]) dfs2(i,1);
	printf("POSSIBLE\n");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}