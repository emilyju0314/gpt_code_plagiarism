#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=100005;
int n,m,nn,a,b,f[N],fa[N],s[N],d[N],c[N];vi g[N];ll ans;
int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
void dfs(int x,int p,int o)
{
	s[x]=o;
	for(int y:g[x])if(y!=p){d[y]=d[x]+1;fa[y]=x;dfs(y,x,-o);s[x]+=s[y];}
}
int main()
{
	n=rd();m=rd();
	if(n&1){puts("-1");return 0;}
	rep(i,1,n)f[i]=i;
	rep(i,1,m)
	{
		int u=rd(),v=rd();int x=fnd(u),y=fnd(v);
		if(x!=y)f[x]=y,g[u].pb(v),g[v].pb(u);else a=u,b=v;
	}
	if(!a)
	{
		dfs(1,0,1);
		if(s[1]){puts("-1");return 0;}
	}
	else
	{
		dfs(a,0,1);
		if(d[b]&1)
		{
			if(s[a]){puts("-1");return 0;}
			for(int i=b;i!=a;i=fa[i])c[++nn]=s[i],s[i]=0;
			c[++nn]=0;sort(c+1,c+nn+1);int w=c[(nn+1)/2];
			rep(i,1,nn)ans+=abs(c[i]-w);
		}
		else
		{
			if(s[a]&1){puts("-1");return 0;}
			int w=s[a]/2;ans=abs(w);s[a]=0;
			for(int i=b;i!=a;i=fa[i])s[i]-=w;
		}
	}
	rep(i,1,n)ans+=abs(s[i]);
	printf("%lld\n",ans);return 0;
}