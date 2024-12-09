#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 210
#define ll long long
#define mod 1000000007
using namespace std;

struct edge{int x, y, f, z, next;}a[N];
int jc[N], inv[N], ans, n, m, k, l, p[N], x, y, d[N], size[N], f[N], flag[N], cl, sum[N], now;

inline int gcd(int a, int b){return b?gcd(b, a%b):a;}
inline int pow(int y, int x){
	int s=1, t=y;
	while(x){if(x&1)s=(ll)s*t%mod; t=(ll)t*t%mod; x>>=1;}
	return s;
}
inline int C(int n, int m){return (ll)jc[n]*inv[m]%mod*inv[n-m]%mod;}

inline int gether(int x){return f[x]?f[x]=gether(f[x]):x;}

inline void add(int x, int y){a[++l].x=x; a[l].y=y; a[l].f=a[l].z=0; a[l].next=p[x]; p[x]=l;}
inline void dfs(int x){
	flag[x]=1;
	for(int i=p[x]; i; i=a[i].next)if(!a[i].f){
		a[i].f=a[i^1].f=1;
		if(!flag[a[i].y]){
			d[++cl]=i; dfs(a[i].y); cl--;
		}else{
			d[++cl]=i;
			l++; int now=cl, x1, y1;
			while(a[d[now]].x!=a[i].y){
				if(a[d[now]].z){x1=gether(a[d[now]].z); y1=gether(l); if(x1!=y1){f[y1]=x1; size[x1]+=size[y1];}}
				a[d[now]].z=a[d[now]^1].z=l; now--;
			}
			if(a[d[now]].z){x1=gether(a[d[now]].z); y1=gether(l); if(x1!=y1){f[y1]=x1; size[x1]+=size[y1];}}
			a[d[now]].z=a[d[now]^1].z=l; now--;
			cl--;
		}
	}
}

int main(){
	jc[0]=1; for(int i=1; i<=200; i++)jc[i]=(ll)jc[i-1]*i%mod;
	inv[0]=inv[1]=1; for(int i=2; i<=200; i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1; i<=200; i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
	scanf("%d%d%d", &n, &m, &k);
	l=1; memset(p, 0, sizeof(p));
	for(int i=1; i<=m; i++){scanf("%d%d", &x, &y); add(x, y); add(y, x);}
	l=cl=0; memset(f, 0, sizeof(f)); memset(flag, 0, sizeof(flag));
	for(int i=1; i<=m; i++)size[i]=1;
	for(int i=1; i<=n; i++)if(!flag[i])dfs(i);
	memset(sum, 0, sizeof(sum));
	ans=1;
	for(int i=1; i<=m; i++){
		x=a[i*2].z;
		if(x)sum[gether(x)]++; else ans=(ll)ans*k%mod;
	}
	for(int i=1; i<=l; i++)if(!f[i]){
		if(size[i]==1){
			x=sum[i]; now=0;
			for(int j=0; j<=x-1; j++)now=(now+pow(k, gcd(x, j)))%mod;
			ans=(ll)ans*now%mod*pow(x, mod-2)%mod;
		}else ans=(ll)ans*C(k+sum[i]-1, k-1)%mod;
	}
	printf("%d", ans);
	return 0;
}