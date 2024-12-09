#include<cstdio>
#include<cstring>
#define max 100001
using namespace std;
int par[max],rank[max];
int vis[max];
void init(int N)
{
	for(int i=1;i<=N;i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x)
{
	if(par[x] == x)
	return x;
	else
	return par[x] = find(par[x]);
}

void unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x == y)
	return ;
	
	if(rank[x] < rank[y])
	par[x] = y;
	else 
	{
		par[y] = x;
		if(rank[x] == rank[y])
		rank[x]++;
	}
	
}



int main()
{
	int N,M;
	while(~scanf("%d%d",&N,&M))
	{
		init(N);
		memset(vis,0,sizeof vis);
		int k,tmp;
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&tmp);
				if(!vis[tmp])
				{
					vis[tmp] = i;
				}
				else if(vis[tmp] != i)
				{
					unite(vis[tmp],i);
				}
			}
		}
		int cnt = 0;
		for(int i=1;i<=N;i++)
		if(find(i) == i)
		cnt++;
		
		if(cnt == 1)
		printf("YES\n");
		else 
		printf("NO\n");
	}
	return 0;	
} 