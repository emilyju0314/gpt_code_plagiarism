#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1005,mo=1e9+7;
int n,dis[N],f[N][N],l;Vi e[N];
void dfs1(int u, int fa, int dep, int &x){
	umax(x,dep);for(int v:e[u])if(v!=fa)dfs1(v,u,dep+1,x);
}
void dfs(int u, int fa, int dep){
	for(int v:e[u])if(v!=fa)dfs(v,u,dep+1);
	rep(i,0,l-dep)f[u][i]=1;f[u][l-dep+1]=f[u][l-dep+2]=0;
	for(int v:e[u])if(v!=fa)rep(i,0,l-dep)
		f[u][i]=1ll*f[u][i]*(f[v][i]+(i-1>=0?f[v][i-1]:0))%mo;
}
int getans(int u, int v){
	dfs(u,v,0);dfs(v,u,0);
	static int g[N][N];memcpy(g,f,sizeof(f));
	l++;dfs(u,v,0);dfs(v,u,0);l--;
	int res=0;
	rep(x,0,l){
		res=(res+1ll*g[u][x]*g[v][x])%mo;
		if(x)res=(res+1ll*g[u][x]*g[v][x-1])%mo;
		res=(res+1ll*(f[u][x+1]-g[u][x]-g[u][x+1])*g[v][x])%mo;
		res=(res+1ll*g[u][x]*(f[v][x]-g[v][x]-(x-1>=0?g[v][x-1]:0)))%mo;
	//	res=(res+1ll*f[u][x+1]*g[v][x]+1ll*g[u][x]*f[v][x]-1ll*g[u][x]*g[v][x])%mo;
	//	if(x)res=(res+1ll*g[u][x]*f[v][x]+1ll*f[u][x]*g[v][x-1]-1ll*g[u][x]*g[v][x-1])%mo;
	}
//	printf("qwq %d %d %d:%d %d\n",u,v,l,res,f[u][l+1]);
	return res;
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	int rt=1;
	rep(i,1,n){int x=0;dfs1(i,0,0,x);dis[i]=x;if(dis[i]<dis[rt])rt=i;}
	l=dis[rt];int mx=0;rep(i,1,n)umax(mx,dis[i]);
	if(mx&1){
		int u=rt,v=0;rep(i,1,n)if(i!=u&&dis[i]==dis[u])v=i;
		l=mx/2;
		int res=((getans(u,v)+getans(v,u))%mo+mo)%mo;
		cout<<res;return 0;
	}
	dfs(rt,0,0);
	int res=0;rep(i,0,l)res=(res+f[rt][i])%mo;cout<<res<<endl;
//	rep(i,0,l)cerr<<i<<' '<<f[rt][i]<<endl;
	return 0;
}
