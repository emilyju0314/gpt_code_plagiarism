#include<bits/stdc++.h> 
using namespace std;

const int maxn=2005;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}


int n,a[maxn];
int vis[maxn];
vector<int>g[maxn],gg[maxn];
int rd[maxn];vector<int>ans;
priority_queue<int>pq;

void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
	{
		int to=g[x][i];
		if(vis[to])continue;
		gg[x].push_back(to);
		rd[to]++;
		dfs(to);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(gcd(a[i],a[j])!=1)
			{
				g[i].push_back(j);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!rd[i])
		{
			pq.push(i);
		}
	}
	
	while(!pq.empty())
	{
		int x=pq.top();pq.pop();
		ans.push_back(a[x]);
		for(int i=0;i<(int)gg[x].size();i++)
		{
			int to=gg[x][i];
			rd[to]--;
			if(!rd[to])
			{
				pq.push(to);
			}
		}
	}
	
	for(int i=0;i<(int)ans.size();i++)
	{
		printf("%d ",ans[i]);
	}
	
	return 0;
}