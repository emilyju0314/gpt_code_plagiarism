#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define For(i,x) for (int i=h[x],k; i; i=nxt[i])
typedef long long ll;
using namespace std;

const int N=20010;
int n,u,v,tot,ans,cnt,c[N],s[N],h[N],to[N<<1],nxt[N<<1];
struct E{ int u,v; }e[N];
void add(int u,int v){ to[++cnt]=v; nxt[cnt]=h[u]; h[u]=cnt; }
bool cmp(int a,int b){ return a>b; }

void dfs(int x,int fa){
	s[x]=c[++tot];
	For(i,x) if ((k=to[i])!=fa) dfs(k,x);
}

int main(){
	scanf("%d",&n);
	rep(i,2,n) scanf("%d%d",&u,&v),e[i]=(E){u,v},add(u,v),add(v,u);
	rep(i,1,n) scanf("%d",&c[i]);
	sort(c+1,c+n+1,cmp); dfs(1,0);
	rep(i,2,n) ans+=min(s[e[i].u],s[e[i].v]);
	printf("%d\n",ans);
	rep(i,1,n) printf("%d ",s[i]);
	return 0;
}