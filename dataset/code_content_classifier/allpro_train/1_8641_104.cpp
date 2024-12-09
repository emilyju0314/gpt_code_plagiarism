#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1919810;
struct edge{
	int to,nxt,cap;
}e[N];
int n,m,sx,sy,tx,ty,id[105][105][2],nod,head[N],cnt=1,ans,dep[N];
int R[105],C[105],T,iter[N];
char mp[105][105];
void addedge(int u,int v,int cap=1){
	e[++cnt]=(edge){v,head[u],cap},head[u]=cnt;
	e[++cnt]=(edge){u,head[v],0},head[v]=cnt;
}
queue<int>q;
void BFS(){
	dep[0]=1;
	for(q.push(0);!q.empty();){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt)
		if(e[i].cap&&!dep[e[i].to]){
			dep[e[i].to]=dep[u]+1;
			q.push(e[i].to);
		}
	}
}
int dfs(int u,int f){
	if(u==T||!f)return f;
	for(int&i=iter[u];i;i=e[i].nxt)
	if(e[i].cap&&dep[e[i].to]>dep[u]){
		int d=dfs(e[i].to,min(f,e[i].cap));
		if(d){
			e[i].cap-=d,e[i^1].cap+=d;
			return d;
		}
	}
	return 0;
}
void dinic(){
	for(;;){
		for(int i=0;i<=T;++i)dep[i]=0;
		BFS();
		if(!dep[T])break;
		for(int i=0;i<=T;++i)iter[i]=head[i];
		while(int f=dfs(0,0x3fffffff))ans+=f;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;++j)
		if(mp[i][j]=='S')sx=i,sy=j;else
		if(mp[i][j]=='T')tx=i,ty=j;else
		if(mp[i][j]=='o'){
			id[i][j][0]=++nod,id[i][j][1]=++nod;
			addedge(nod-1,nod);
		}
	}
	if(sx==tx||sy==ty)return puts("-1"),0;
	for(int i=1;i<=n;++i)R[i]=++nod;
	for(int i=1;i<=m;++i)C[i]=++nod;
	T=++nod;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)if(mp[i][j]=='o'){
		addedge(id[i][j][1],R[i],0x3fffffff);
		addedge(id[i][j][1],C[j],0x3fffffff);
		addedge(R[i],id[i][j][0],0x3fffffff);
		addedge(C[j],id[i][j][0],0x3fffffff);
	}
	addedge(0,R[sx],0x3fffffff),addedge(0,C[sy],0x3fffffff);
	addedge(R[tx],T,0x3fffffff),addedge(C[ty],T,0x3fffffff);
	dinic();
	printf("%d\n",ans);
	return 0;
}