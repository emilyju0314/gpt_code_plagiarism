#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
namespace Dango
{
	const int MAXN=200005,MOD=1000000007;
	vector<int> cir,node;
	int n;
	int head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
	int tot;
	int fa[MAXN],size[MAXN];
	long long ans;
	bool vis[MAXN],on_cir[MAXN];
	int read()
	{
		int x=0,f=0;
		char ch=getchar();
		while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	void add(int u,int v)
	{
		static int cnt;
		cnt++;
		to[cnt]=v;
		nxt[cnt]=head[u];
		head[u]=cnt;
	}
	void dfs(int u)
	{
		node.push_back(u);
		vis[u]=true;
		tot+=2;
		for(int i=head[u];i;i=nxt[i])
		{
			tot--;
			int v=to[i];
			if(vis[v])continue;
			dfs(v);
		}
	}
	void findcircle(int u,int pre)
	{
		static bool vis[MAXN],flag;
		static int s,t;
		vis[u]=true;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(v==pre)continue;
			if(vis[v])
			{
				flag=true;
				s=u;t=v;
				break;
			}
			findcircle(v,u);
			if(flag)break;
		}
		if(flag){cir.push_back(u);on_cir[u]=true;}
		if(u==t)flag=false;
	}
	long long pow_(long long a,long long b)
	{
		long long res=1;
		while(b)
		{
			if(b&1)res=res*a%MOD;
			a=a*a%MOD;
			b>>=1;
		}
		return res;
	}
	long long dfs_(int u)
	{
		if(size[u])return 1;
		long long res=1;
		size[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(v>=fa[u])continue;
			res=res*dfs_(v)%MOD;
			size[u]+=size[v];
		}
		res=res*pow_(size[u],MOD-2)%MOD;
		return res;
	}
	int calc()
	{
		long long res=1;
		for(int i=0;i<node.size();i++)
			size[node[i]]=0;
		for(int i=0;i<node.size();i++)
		{
			int x=node[i];
			if(size[x])continue;
			res=res*dfs_(x)%MOD;
		}
		return res;
	}
	void dfs_for_fa(int u)
	{
		static int vis[MAXN];
		vis[u]=true;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(vis[v]||on_cir[v])continue;
			fa[v]=u;
			dfs_for_fa(v);
		}
	}
	void solve(int u)
	{
		long long res=0;
		cir.clear();
		node.clear();
		dfs(u);
		if(tot){ans=0;return;}
		findcircle(u,0);
		for(int i=0;i<cir.size();i++)
			dfs_for_fa(cir[i]);
		cir.push_back(cir[0]);
		for(int i=1;i<cir.size();i++)
			fa[cir[i]]=cir[i-1];
		res=(res+calc())%MOD;
		for(int i=0;i<cir.size()-1;i++)
			fa[cir[i]]=cir[i+1];
		res=(res+calc())%MOD;
		ans=ans*res%MOD;
	}
	int work()
	{
		n=read();
		n<<=1;
		for(int i=1;i<=n;i++)
		{
			int u=read(),v=read()+n/2;
			add(u,v);add(v,u);
		}
		ans=1;
		for(int i=1;i<=n&&ans;i++)
		{
			ans=ans*i%MOD;
			if(!vis[i])solve(i);
		}
		printf("%lld",ans);
		return 0;
	}
}
int main()
{
	return Dango::work();
}