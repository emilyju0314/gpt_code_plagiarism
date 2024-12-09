#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100010];
int x,y,n,m,q,u,d,c;
int color[100010],maxu[100010],U[100010],D[100010],C[100010];
void dfs(int u,int d,int c)
{
 if(color[u]==0)color[u]=c;
 if(d==0)return;
 if(maxu[u]>=d)return;
 maxu[u]=d; 
 for(int i=0;i<edge[u].size();i++)
  {int to=edge[u][i];
   dfs(to,d-1,c);
  }
}
int main()
{
    scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	 {scanf("%d%d",&x,&y);
	  edge[x].push_back(y);
	  edge[y].push_back(x);
	 }
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d%d%d",&U[i],&D[i],&C[i]);	
	for(int i=q;i>=1;i--)dfs(U[i],D[i],C[i]);
	for(int i=1;i<=n;i++)printf("%d\n",color[i]);
	return 0;
} 