#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,dist[205][205],ans=-1,tag;
struct Node
{
	int x,y,b;
}node[2005];
inline int read()
{
	int f=1,w=0;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') w=(w<<1)+(w<<3)+ch-'0',ch=getchar();
	return f*w;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(i!=j) dist[i][j]=1e9;
		else dist[i][j]=0;
	for(int i=1;i<=m;i++)
	{
		node[i]=(Node){read(),read(),read()};
		int x=node[i].x,y=node[i].y;
		if(node[i].b) dist[x][y]=1,dist[y][x]=-1;
		else dist[x][y]=dist[y][x]=1;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
	for(int i=1;i<=n;i++)
	{
		if(dist[i][i]<0) return puts("NO"),0;
		for(int j=1;j<=m;j++) if(dist[i][node[j].x]==dist[i][node[j].y]) return puts("NO"),0;
		for(int j=1;j<=n;j++) if(dist[i][j]>ans) ans=dist[i][j],tag=i;
	}
	puts("YES"),printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",dist[tag][i]);
	return 0;
}
