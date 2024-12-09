#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int d[105][(1<<8)][105],n,m,e,s,t,r;
vector<int>edge[105];
vector<int>ev[105];
P pp[10];
int main()
{
	cin >> n >> m >> e >> s >> t >> r;
	
	for(int i=0;i<m;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b); edge[b].pb(a);
	}
	for(int i=0;i<e;i++)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		ev[c].pb(i);
		pp[i] = mp(a,b);
	}
	for(int i=0;i<105;i++) for(int j=0;j<(1<<8);j++) for(int k=0;k<105;k++)d[i][j][k]=INF;
	priority_queue<P2,vector<P2>,greater<P2> >que;
	int mask = 0;
	for(int j=0;j<ev[s].size();j++) mask += (1<<ev[s][j]);
	d[s][mask][0] = 0;
	que.push(mp(mp(0,s),mp(mask,0)));
	
	while(!que.empty())
	{
		P2 p = que.top(); que.pop();
		
		if(d[p.fi.sc][p.sc.fi][p.sc.sc] != p.fi.fi) continue;
		
		if(d[s][p.sc.fi][0] > p.fi.fi+1)
		{
			d[s][p.sc.fi][0] = p.fi.fi+1;
			que.push(mp(mp(p.fi.fi+1,s),mp(p.sc.fi,0)));
		}
		if(p.sc.sc == r) continue;
		for(int j=0;j<edge[p.fi.sc].size();j++)
		{
			int x = edge[p.fi.sc][j];
			int a = p.sc.fi;
			for(int j=0;j<ev[x].size();j++) a |= (1<<ev[x][j]);
			if(d[x][a][p.sc.sc+1] > p.fi.fi+1)
			{
				d[x][a][p.sc.sc+1] = p.fi.fi+1;
				que.push(mp(mp(p.fi.fi+1,x),mp(a,p.sc.sc+1)));
			}
		}
		for(int j=0;j<e;j++)
		{
			if(!((p.sc.fi>>j)&1)) continue;
			int x;
			if(pp[j].fi == p.fi.sc)
			{
				x = pp[j].sc;
			}
			else if(pp[j].sc == p.fi.sc)
			{
				x = pp[j].fi;
			}
			else
			{
				continue;
			}
			int a = p.sc.fi;
			for(int j=0;j<ev[x].size();j++) a |= (1<<ev[x][j]);
			if(d[x][a][p.sc.sc+1] > p.fi.fi+1)
			{
				d[x][a][p.sc.sc+1] = p.fi.fi+1;
				que.push(mp(mp(p.fi.fi+1,x),mp(a,p.sc.sc+1)));
			}
		}
	}
	int res = INF;
	for(int i=0;i<(1<<8);i++) for(int j=0;j<=r;j++) res = min(res,d[t][i][j]);
	if(res == INF) puts("-1");
	else printf("%d\n",res);
}