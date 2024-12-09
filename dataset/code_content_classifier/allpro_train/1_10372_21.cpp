#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 1100;
int n,tot = 1,st,en;
queue<int> q;
struct node{int nex,to,val,flow;}a[N << 5];
int head[N << 2],flow[N << 2],dis[N << 2],vis[N << 2],pre[N << 2],last[N << 2];
int bfs()
{
	memset(flow,0x3f,sizeof(flow));
	for(int i = 0;i <= 2 * n + 5;i ++) dis[i] = -flow[i];
	pre[en] = -1; dis[st] = 0; q.push(st);
	while(!q.empty())
	{
		int f = q.front(); q.pop(); vis[f] = 0;
		for(int i = head[f],to;i;i = a[i].nex)
		{
			to = a[i].to;
			if(dis[to] < dis[f] + a[i].val && a[i].flow)
			{
				dis[to] = dis[f] + a[i].val; 
				flow[to] = min(flow[f],a[i].flow);
				pre[to] = f; last[to] = i;
				if(!vis[to]){vis[to] = 1; q.push(to);}
			}
		}
	}
	return pre[en] != -1;
}
void add(int f,int t,int v,int flow)
{
	a[++ tot].nex = head[f]; a[tot].to = t;
	a[tot].val = v; a[tot].flow = flow;
	head[f] = tot;
	a[++ tot].nex = head[t]; a[tot].to = f;
	a[tot].val = -v; a[tot].flow = 0;
	head[t] = tot;
}
signed main()
{
	n = read(); st = 0; en = 2 * n + 5; 
	for(int i = 1,x,y,c;i <= n;i ++)
	{
		x = read(); y = read(); c = read();
		add(st,i,0,c);
		add(i,2 * n + 1,x + y,c); add(i,2 * n + 2,x - y,c);
		add(i,2 * n + 3,-x + y,c);add(i,2 * n + 4,-x - y,c);
	}
	
	for(int i = 1,x,y,c;i <= n;i ++)
	{
		x = read(); y = read(); c = read();
		add(i + n,en,0,c);
		add(2 * n + 1,i + n,- x - y,c); add(2 * n + 2,i + n,-x + y,c);
		add(2 * n + 3,i + n,x - y,c); add(2 * n + 4,i + n,x + y,c);
	}
	int mdmf = 0,maxflow = 0;
	while(bfs())
	{
		mdmf += dis[en] * flow[en];
		maxflow += flow[en];
		int t = en;
		while(t != st)
		{
			a[last[t]].flow -= flow[en];
			a[last[t] ^ 1].flow += flow[en];
			t = pre[t];
		}
	}
	cout << mdmf << "\n";
	return 0;
}