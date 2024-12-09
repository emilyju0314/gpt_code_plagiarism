#include<bits/stdc++.h> 
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
typedef long long ll;
using namespace std;
inline int read(){
	int n=0,f=1;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if (c=='-') c=getchar(),f=-1;
	for(;c>='0'&&c<='9';c=getchar()) n=n*10+c-48;
	return n*f;
}
const int maxn=2e5+5;
int i,j,n,k[maxn],ne[maxn<<1],g[maxn<<1],num;
struct ar{int s1,s2;}mx[maxn];
int fa[maxn],high[maxn],low[maxn];char s[maxn];
struct ax{int x,id;};
bool operator <(ax a,ax b){
	return (a.x==b.x)?a.id<b.id:a.x<b.x;
}
set<ax>w;
ll ans;
void add(int x,int y){
	ne[++num]=k[x],k[x]=num,g[num]=y;
} 
void update(ar &now,int x){
	if (x>now.s1) now.s2=now.s1,now.s1=x;else now.s2=max(now.s2,x); 
}
void dfs(int x){
	int i,f=fa[x];
	for(i=k[x];i;i=ne[i]){
		int go=g[i];
		if (go!=f){
			fa[go]=x,dfs(go);
			update(mx[x],mx[go].s1+1);
		}
	}
}
void df(int x,int y){
	ar now=mx[x];int i,f=fa[x],s;
	update(mx[x],y);
	y++;
	for(i=k[x];i;i=ne[i]){
		int go=g[i];
		if (go!=f) s=(mx[go].s1+1==now.s1?now.s2:now.s1)+1,df(go,max(y,s));
	}
}
int main(){
	n=read();
	fo(i,1,n-1){
		int x=read(),y=read();
		add(x,y),add(y,x);
	}scanf("%s",s+1);
	dfs(1);
	df(1,0);
	fo(i,1,n) {
		if (s[i]=='0') low[i]=n;
		high[i]=min(mx[i].s1-1,mx[i].s2+1);
		w.insert((ax){low[i],i});
	}
	fo(j,1,n){
		ax now=*w.begin();
		w.erase(w.find(now));
		int x=now.id,d=mx[x].s2+1,p=mx[x].s1,o=0; 
		if (d<low[x]||d>high[x]) continue;
		for(i=k[x];i;i=ne[i])if (mx[g[i]].s1+1==p) {o=g[i];break;}
		if (!o) o=fa[x];
		if (low[o]<=d) continue;
		w.erase(w.find((ax){low[o],o}));
		low[o]=d;
		w.insert((ax){low[o],o});
	}
	fo(i,1,n) ans+=max(0,high[i]-low[i]+1);
	printf("%lld\n",ans+1);
} 