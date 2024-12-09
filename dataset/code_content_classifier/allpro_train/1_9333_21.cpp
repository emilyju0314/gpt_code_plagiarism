#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 2005

using namespace std;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int par[SIZE][SIZE];
int id[SIZE][SIZE];
bool use[SIZE][SIZE];
int ans;

void dfs(int v,int p,int rt)
{
	par[rt][v]=p;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v,rt);
	}
}
void add(int a,int b)
{
	if(id[a][b]==b||id[b][a]==a) return;
	if(id[a][b]!=-1) add(id[a][b],b);
	else if(id[b][a]!=-1) add(id[b][a],a);
	else
	{
		vector <P> nxt;
		for(int t=0;t<2;t++)
		{
			use[a][b]=true;
			id[a][b]=b;
			queue <int> que;
			que.push(b);
			while(!que.empty())
			{
				int v=que.front();que.pop();
				for(int i=0;i<vec[v].size();i++)
				{
					int to=vec[v][i];
					if(to!=par[a][v])
					{
						if(id[a][to]!=-1)
						{
							if(use[a][to])
							{
								use[to][a]=use[a][to]=false;
								nxt.push_back(P(to,b));
							}
						}
						else
						{
							id[a][to]=b;
							que.push(to);
						}
					}
				}
			}
			swap(a,b);
		}
		for(int i=0;i<nxt.size();i++) add(nxt[i].first,nxt[i].second);
	}
}
void dfs2(int v,int p,int b)
{
	if(id[b][v]==v)
	{
		ans++;
		b=v;
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs2(to,v,b);
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for(int i=0;i<n;i++) dfs(i,-1,i);
	memset(id,-1,sizeof(id));
	memset(use,false,sizeof(use));
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		add(a,b);
	}
	ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j];
			dfs2(to,i,i);
		}
	}
	printf("%d\n",ans/2);
	return 0;
}
