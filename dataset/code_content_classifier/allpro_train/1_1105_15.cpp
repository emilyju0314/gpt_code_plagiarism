#include<bits/stdc++.h>
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,size,stdin),p1==p2)?EOF:*p1++)
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define IT iterator 
#define vi vector<int>
#define TP template<class o>
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N=2e5+10,size=1<<20,mod=998244353,inf=2e9;

//char buf[size],*p1=buf,*p2=buf;
template<class o> void qr(o &x) {
    char c=gc; x=0; int f=1;
    while(!isdigit(c)){if(c=='-')f=-1; c=gc;}
    while(isdigit(c)) x=x*10+c-'0',c=gc;
    x*=f;
}
template<class o> void qw(o x) {
    if(x/10) qw(x/10);
    putchar(x%10+'0');
}
template<class o> void pr1(o x) {
    if(x<0)x=-x,putchar('-');
    qw(x); putchar(' ');
}
template<class o> void pr2(o x) {
    if(x<0)x=-x,putchar('-');
    qw(x); putchar('\n');
}

ll p[N],np[N],n,k,s,cnt,ans;
int c[N],a[N];

TP void upd(o &x,int y) {x += y; if(x>=mod) x -= mod;}
void add(int x,int y) {upd(s,y); for( ;x<=n;x += x&-x) upd(c[x],y); }
int ask(int x) {ll y=0; for( ; x;x -= x&-x) y += c[x]; return y%mod; }
void clear() {memset(c+1,0,sizeof(int)*n); s=0;}

ll mult(ll a,ll b,ll p) {
    a=(a%p+p)%p; b=(b%p+p)%p;
    ll c=(ld)a*b/p;
    return a*b-c*p;
}
ll gcd(ll a,ll b) {return !a?b:gcd(b%a,a);}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
ll power(ll a,ll b=mod-2) {
    ll c=1;
    while(b) {
        if(b&1) c=c*a%mod;
        b /= 2; a=a*a%mod;
    }
    return c;
}
ll Power(ll a,ll b=mod-2) {
    ll c=1;
    while(b) {
        if(b&1) c=mult(c,a,mod);
        b /= 2; a=mult(a,a,mod);
    }
    return c;
}

int main() {
    qr(n); qr(k);
    for(int i=1;i<=n;i++) 
		qr(a[i]),add(a[i],1),cnt += i-ask(a[i]);
    p[0]=np[0]=1; p[1]=(k-1)*power(k)%mod; np[1]=power(p[1]); clear();
    for(int i=2;i<=n;i++) p[i]=p[i-1]*p[1]%mod,np[i]=np[i-1]*np[1]%mod;
    for(int i=1;i<=n;i++) {
        int f=max(i-k,0LL);
        ans += p[f]*(2*ask(a[i])-s+mod)%mod;
        add(a[i],np[f]);
    }
    pr2((cnt+ans%mod*(mod+1)/2%mod)%mod); return 0;
}