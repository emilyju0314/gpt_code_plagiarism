#include<bits/stdc++.h>
#define MN 700
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bitset<705> b;
int s[MN+5][MN+5],n,m,vis[MN+5],c[MN+5],flag,num[2];
void dfs(int x,int v)
{
	vis[x]=1;c[x]=v;++num[v];
	for(int j=1;j<=n;++j) if(j!=x&&!s[x][j])
	{
		if(!vis[j]) dfs(j,v^1);
		else if(c[j]!=v^1) flag=1;	
	}
}
int main()
{
	n=read();m=read();b[0]=1;
	for(int i=1;i<=m;++i) 
	{
		int x=read(),y=read();
		s[x][y]=s[y][x]=1;	
	}
	for(int i=1;i<=n;++i) 
		if(!vis[i]) num[0]=num[1]=0,dfs(i,0),b=(b<<num[0])|(b<<num[1]);
	if(flag) return 0*puts("-1");int ans=1e9;
	for(int j=0;j<=n;++j) if(b[j]) ans=min(ans,j*(j-1)/2+(n-j)*(n-j-1)/2);
	cout<<ans; 
	return 0;
}
 