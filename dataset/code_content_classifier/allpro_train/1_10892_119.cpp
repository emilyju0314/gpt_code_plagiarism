#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
vector<pair<int,int> >G1[100010],G2[100010];
int s,t;
bool vis[100010];
long long ds[100010],dt[100010];
long long alld[100010];
set<pair<long long,int> >st;
void dijkstra(int S,long long dis[],vector<pair<int,int> >G[])
{
	for(int i=1;i<=n;i++)dis[i]=1e18;
	memset(vis,false,sizeof(vis));
	priority_queue<pair<long long,int>, vector<pair<long long,int> > ,greater<pair<long long,int> > >q;
	dis[S]=0LL;
	q.push(make_pair(0,S));
	for(int i=1;i<=n;i++)
	{
		while(!q.empty() && (vis[q.top().second] || dis[q.top().second]!=q.top().first))q.pop();
		int x=q.top().second;
		q.pop();
		vis[x]=true;
		for(int j=0;j<G[x].size();j++)
		{
			int y=G[x][j].first;
			if(vis[y] || dis[x]+G[x][j].second>=dis[y])continue;
			dis[y]=dis[x]+G[x][j].second;
			q.push(make_pair(dis[y],y)); 
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v,a,b;
		scanf("%d%d%d%d",&u,&v,&a,&b);
		G1[u].push_back(make_pair(v,a));
		G1[v].push_back(make_pair(u,a));
		G2[u].push_back(make_pair(v,b));
		G2[v].push_back(make_pair(u,b));
	}
	dijkstra(s,ds,G1);
	dijkstra(t,dt,G2);
	for(int i=1;i<=n;i++)alld[i]=ds[i]+dt[i],st.insert(make_pair(alld[i],i));
	for(int i=0;i<n;i++)
	{
		printf("%lld\n",1000000000000000LL-(*st.begin()).first);
		st.erase(st.find(make_pair(alld[i+1],i+1)));
	}
	return 0;
}