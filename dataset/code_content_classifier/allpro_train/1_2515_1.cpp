#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=65537;
const int mo=65537;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head


// FFT_MAXN = 2^k
// fft_init() to precalc FFT_MAXN-th roots
const int N=301000;

typedef double db;
const int FFT_MAXN=262144;
const db pi=acos(-1.);
struct cp{
	db a,b;
	cp operator+(const cp&y)const{return (cp){a+y.a,b+y.b};}
	cp operator-(const cp&y)const{return (cp){a-y.a,b-y.b};}
	cp operator*(const cp&y)const{return (cp){a*y.a-b*y.b,a*y.b+b*y.a};}
	cp operator!()const{return (cp){a,-b};};
}nw[FFT_MAXN+1];int bitrev[FFT_MAXN];
void dft(cp*a,int n,int flag=1){
	int d=0;while((1<<d)*n!=FFT_MAXN)d++;
	rep(i,0,n)if(i<(bitrev[i]>>d))swap(a[i],a[bitrev[i]>>d]);
	for (int l=2;l<=n;l<<=1){
		int del=FFT_MAXN/l*flag;
		for (int i=0;i<n;i+=l){
			cp *le=a+i,*ri=a+i+(l>>1),*w=flag==1?nw:nw+FFT_MAXN;
			rep(k,0,l>>1){
				cp ne=*ri**w;
				*ri=*le-ne,*le=*le+ne;
				le++,ri++,w+=del;
			}
		}
	}
	if(flag!=1)rep(i,0,n)a[i].a/=n,a[i].b/=n;
}
void fft_init(){
	int L=0;while((1<<L)!=FFT_MAXN)L++;
	bitrev[0]=0;rep(i,1,FFT_MAXN)bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(L-1));
//	cp ste=(cp){cosl(2*pi/FFT_MAXN),sinl(2*pi/FFT_MAXN)};
	nw[0]=nw[FFT_MAXN]=(cp){1,0};
//	rep(i,1,(FFT_MAXN>>1)+1)nw[i]=nw[i-1]*ste;
//	rep(i,(FFT_MAXN>>1)+1,FFT_MAXN)nw[i]=!nw[FFT_MAXN-i];
	rep(i,0,FFT_MAXN+1)nw[i]=(cp){cos(2*pi/FFT_MAXN*i),sin(2*pi/FFT_MAXN*i)};	//very slow
}

void convo(db*a,int n,db*b,int m,db*c){
	static cp f[FFT_MAXN>>1],g[FFT_MAXN>>1],t[FFT_MAXN>>1];
	int N=2;while(N<=n+m)N<<=1;
	rep(i,0,N)
		if(i&1){
			f[i>>1].b=(i<=n)?a[i]:0.0;
			g[i>>1].b=(i<=m)?b[i]:0.0;
		}else{
			f[i>>1].a=(i<=n)?a[i]:0.0;
			g[i>>1].a=(i<=m)?b[i]:0.0;
		}
	dft(f,N>>1);dft(g,N>>1);
	int del=FFT_MAXN/(N>>1);
	cp qua=(cp){0,0.25},one=(cp){1,0},four=(cp){4,0},*w=nw;
	rep(i,0,N>>1){
		int j=i?(N>>1)-i:0;
		t[i]=(four*!(f[j]*g[j])-(!f[j]-f[i])*(!g[j]-g[i])*(one+*w))*qua;
		w+=del;
	}
	dft(t,N>>1,-1);
	rep(i,0,n+m+1)c[i]=(i&1)?t[i>>1].a:t[i>>1].b;
}


void mul(int *a,int *b,int n){// n<=N, 0<=a[i],b[i]<mo
	static cp f[N],g[N],t[N],r[N];
	int nn=2;while(nn<=n+n)nn<<=1;
	rep(i,0,nn){
		f[i]=(i<=n)?(cp){(db)(a[i]>>15),(db)(a[i]&32767)}:(cp){0,0};
		g[i]=(i<=n)?(cp){(db)(b[i]>>15),(db)(b[i]&32767)}:(cp){0,0};
	}
	swap(n,nn);
	dft(f,n,1);dft(g,n,1);
	rep(i,0,n){
		int j=i?n-i:0;
		t[i]=( (f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j]) )*(cp){0,0.25};
		r[i]=(!f[j]-f[i])*(!g[j]-g[i])*(cp){-0.25,0} + (cp){0,0.25}*(f[i]+!f[j])*(g[i]+!g[j]);
	}
	dft(t,n,-1); dft(r,n,-1);
	rep(i,0,n)a[i]=( (ll(t[i].a+0.5)%mo<<15) + ll(r[i].a+0.5) + (ll(r[i].b+0.5)%mo<<30) )%mo;
}

int n,k,c[N],d[N],_;
ll fac[N],fnv[N];
void solve() {
	scanf("%d%d",&n,&k);
	k=k%mod;
	if (k<0) k+=mod;
	rep(i,0,n) {
		scanf("%d",c+i);
		c[i]=c[i]%mod;
		if (c[i]<0) c[i]+=mod;
	}
	reverse(c,c+n);
	rep(i,0,n) c[i]=c[i]*fnv[i]%mod;
	rep(i,0,n) d[i]=powmod(mod-k,i)*fnv[i]%mod;
	mul(c,d,n-1);
	rep(i,0,n) c[i]=c[i]*fac[i]%mod;
	rep(i,0,n) printf("%d%c",c[i]," \n"[i==n-1]);
}

int main() {
	fft_init();
	fac[0]=fnv[0]=1;
	for (int i=1;i<=50000;i++) {
		fac[i]=fac[i-1]*i%mod;
		fnv[i]=powmod(fac[i],mod-2);
	}
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
