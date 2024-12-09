#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char map[15][15];
int n,m;
int a[15];bool vis[15],ans=false;
bool v2[15];
void check()
{
	memset(v2,false,sizeof(v2));
	bool op=m&1;
	for(int i=1;i<=m;i++)
		if(!v2[i])
		{
			bool flag=false;
			for(int j=i+1;j<=m;j++)
			{
				if(!v2[j])
				{
					bool ok=true;
					for(int k=1;k<=n;k++) if(map[a[k]][i]!=map[a[n-k+1]][j]) ok=false;
					if(ok) {v2[j]=flag=true;break;}
				}
			}
			if(!flag)
			{
				if(op)
				{
					bool ok=true;
					for(int k=1;k<=n;k++) if(map[a[k]][i]!=map[a[n-k+1]][i]) ok=false;
					if(ok) op=false;
					else return;
				}
				else return;
			}
		}
	ans=true;
}
void dfs(int x,int pos,bool op)
{
	if(ans) return;
	if(x>n) {check();return;}
	if(vis[x]) {dfs(x+1,pos,op);return;}
	for(int i=x+1;i<=n;i++)
	{
		if(vis[i]) continue;
		a[pos]=i;a[n-pos+1]=x;
		vis[i]=true;dfs(x+1,pos+1,op);vis[i]=false;
	}
	if(op)
	{
		a[n/2+1]=x;
		dfs(x+1,pos,false);
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",map[i]+1);
	dfs(1,1,n&1);
	if(ans) printf("YES");
	else printf("NO");
}