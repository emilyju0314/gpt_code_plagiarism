#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
    x=0;char c=getchar();bool f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;return  x;
}
template<class t> inline void write(t x){
    if(x<0){putchar('-'),write(-x);}
    else{if(x>9)write(x/10);putchar('0'+x%10);}
}

#define int long long

const int N=55,M=25;
int en,f[N],d[N],h[N],s[M],n,m,ans;

struct edge{
	int n,v;
}e[N<<1];

void add(int x,int y){
	e[++en]=(edge){h[x],y};
	h[x]=en;
}

void dfs(int x){
	d[x]=d[f[x]]+1;
	for(int i=h[x];i;i=e[i].n){
		int y=e[i].v;
		if(y==f[x]) continue;
		f[y]=x;
		dfs(y);
	}
}

signed main(){
	read(n);
	for(int i=1,x,y;i<n;i++){
		read(x);read(y);
		add(x,y);add(y,x);
	}
	dfs(1);
	read(m);
	for(int i=0,x,y;i<m;i++){
		read(x);read(y);
		if(d[x]<d[y]) swap(x,y);
		while(d[x]^d[y]) s[i]|=1ll<<x-1,x=f[x];
		while(x^y) s[i]|=(1ll<<x-1)|(1ll<<y-1),x=f[x],y=f[y];
	}
	int lim=1<<m;
	for(int i=0;i<lim;i++){
		int cnt=0,now=0,tot=0;
		for(int j=0;j<m;j++) if(i>>j&1) cnt++,now|=s[j];
		for(int j=0;j<n;j++) if(now>>j&1) tot++;
		tot=1ll<<(n-1-tot);
		if(cnt&1) ans-=tot;
		else ans+=tot;
	}
	write(ans);
//	write((1ll<<n-1)-ans);
}