#include <iostream>
#include <cstdlib>
#include <cstdio>
#define N 3011
using namespace std;
struct apple{
	int v,nxt;
}edge[N*4];
int indexx[N],tot,n,val[N];
void addedge(int x,int y){
	edge[++tot].v=y;
	edge[tot].nxt=indexx[x];
	indexx[x]=tot;
}
int dfs(int u,int fa){
	int t=indexx[u],vv,sum=val[u];
	while(t){
		vv=edge[t].v;
		if(vv!=fa){
			int k=dfs(vv,u);
			if(!k && val[vv]<val[u]) return 1;
		}
		t=edge[t].nxt;
	}
	return 0;
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;i++){
		int k=dfs(i,0);
		if(k ) printf("%d ",i);
	}
	return 0;
}