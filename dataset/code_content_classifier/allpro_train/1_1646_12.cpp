#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
using namespace std;
const int N=2*1e5+100;
int n,k,sz[N],son[N],id[N],ans[N];
int c[N],d[N],cnt,ti[N],dfn;
int tot,first[N],nxt[N*2],point[N*2];
namespace dsu
{
	struct node
	{
		int x,y,e,sz,T;//x->y
	};
	int fa[N],e[N],sz[N];
	stack <node> s;
	int nowtime()
	{
		if (s.empty()) return 0;
		else return s.top().T;
	}
	inline int find(int x)
	{
		if (fa[x]==x) return fa[x];
		return fa[x]=find(fa[x]);
	}
	void init()
	{
		for (int i=1;i<=k;i++) fa[i]=i,sz[i]=1;
	}
	void connect(int x,int y)
	{
		int fax=find(x),fay=find(y),T=nowtime()+1;
		if (fax==fay)
		{
			s.push((node){fax,fay,e[fax],sz[fax],T});
			cnt-=sz[fax]-(e[fax]==sz[fax]-1);
			e[fax]++;
			cnt+=sz[fax]-(e[fax]==sz[fax]-1);
			return;
		}
		if (sz[fax]>sz[fay]) swap(fax,fay);
		cnt-=sz[fax]-(e[fax]==sz[fax]-1);
		cnt-=sz[fay]-(e[fay]==sz[fay]-1);
		s.push((node){fax,fay,e[fay],sz[fay],T});
		fa[fax]=fay,sz[fay]+=sz[fax],e[fay]+=e[fax]+1;
		cnt+=sz[fay]-(e[fay]==sz[fay]-1);
	}
	void back(int T)
	{
		while (!s.empty() && s.top().T>T)
		{
			node tmp=s.top();
			s.pop();
			cnt-=sz[tmp.y]-(e[tmp.y]==sz[tmp.y]-1);
			fa[tmp.x]=tmp.x,e[tmp.y]=tmp.e,sz[tmp.y]=tmp.sz;
			cnt+=sz[tmp.x]-(e[tmp.x]==sz[tmp.x]-1);
			if (tmp.x!=tmp.y) cnt+=sz[tmp.y]-(e[tmp.y]==sz[tmp.y]-1);
		}
	}
}
void add_edge(int x,int y)
{
	tot++;
	nxt[tot]=first[x];
	first[x]=tot;
	point[tot]=y;
}
void dfs(int x,int fa)
{
	sz[x]=1;
	for (int i=first[x];i!=-1;i=nxt[i])
	{
		int u=point[i];
		if (u==fa) continue;
		dfs(u,x);
		sz[x]+=sz[u];
		if (sz[u]>sz[son[x]]) son[x]=u;
	}
}
void dfs1(int x,int fa)
{
	dsu::connect(c[x],d[x]);
	for (int i=first[x];i!=-1;i=nxt[i])
	{
		int u=point[i];
		if (u==fa) continue;
		dfs1(u,x);
	}
}
void dfs2(int x,int fa)
{
	for (int i=first[x];i!=-1;i=nxt[i])
	{
		int u=point[i],t=dsu::nowtime();
		if (u==fa || u==son[x]) continue;
		dfs2(u,x);
		dsu::back(t);
	}
	if (son[x]) dfs2(son[x],x);
	dsu::connect(c[x],d[x]);
	for (int i=first[x];i!=-1;i=nxt[i])
	{
		int u=point[i];
		if (u==fa || u==son[x]) continue;
		dfs1(u,x);
	}
	ans[x]=cnt;
}
signed main()
{
	tot=-1;
	memset(first,-1,sizeof(first));
	memset(nxt,-1,sizeof(nxt));
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
	dfs(1,1);
	dsu::init();
	dfs2(1,1);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
