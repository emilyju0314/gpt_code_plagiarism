#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=400010;
int n,tt;
int head[N],to[N],nxt[N],f[N][18],v[N],fa[N],ls[N],rs[N],sz[N],ans[N];
struct Dat {
    int x,y,z;
    inline bool operator < (const Dat &A) const {return z<A.z;}
} g[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return o*x;
}
inline void dfs(int x,int fa) {
    f[x][0]=fa;
    for(int i=1;i<18;i++) f[x][i]=f[f[x][i-1]][i-1];
    if(x<=n) sz[x]=1;
    else dfs(ls[x],x),dfs(rs[x],x),sz[x]=sz[ls[x]]+sz[rs[x]];
}
inline int query(int x,int y) {
    for(int i=17;~i;i--)
	if(f[x][i]&&v[f[x][i]]<y) x=f[x][i];
    return sz[x];
}
inline void solve(int x,int fa,int s,int la) {
    if(fa>la) {
	if(x<fa) {
	    s+=query(x,fa);
	    if(x<la) s-=query(x,la);
	}
	else {
	    ++s;
	    for(int i=head[x];i;i=nxt[i])
		if(to[i]!=fa&&to[i]<fa) s+=query(to[i],fa);
	}
	la=fa;
    }
    else if(x>la) {
	++s;
	for(int i=head[x];i;i=nxt[i])
	    if(to[i]!=fa&&to[i]<la) s+=query(to[i],la);
    }
    ans[x]=s;
    for(int i=head[x];i;i=nxt[i])
	if(to[i]!=fa) solve(to[i],x,s,la);
}
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int main() {
    cin>>n;
    for(int i=1;i<n;i++) {
	int x=gi(),y=gi();
	g[i]=(Dat){x,y,max(x,y)};
	to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
	to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
    }
    sort(g+1,g+n);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<n;i++) {
	int x=find(g[i].x),y=find(g[i].y),z=i+n;
	fa[x]=fa[y]=fa[z]=z;
	ls[z]=x,rs[z]=y,v[z]=g[i].z;
    }
    dfs(n+n-1,0),solve(1,0,-1,0);
    for(int i=2;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}