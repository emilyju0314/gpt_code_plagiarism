#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long ll;
ll a[100010];
ll b[100010];
ll c[100010];
ll s[100010];
ll m[100010];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll ex(ll x,ll p,ll mod){
	ll a=1;
	while(p){
		if(p%2) a=a*x%mod;
		x=x*x%mod;
		p/=2;
	}
	return a;
}
ll geo(ll x,ll p,ll mod){	//1+x+..+x^(p-1)
	if(p==0) return 0;
	ll a=0,s=1,t=1;
	while(p){
		if(p%2){
			a=(a+s*t)%mod;
			s=s*x%mod;
		}
		t=t*(1+x)%mod;
		x=x*x%mod;
		p/=2;
	}
	return a;
}
typedef pair<int,int> P;
ll getord(ll M,ll a){
	ll H=sqrt(M)+1;
	vector<P> babies;
	ll p=1;
	rep(i,H){
		babies.pb(P(p,i));
		p=p*a%M;
	}
	ll q=p;
	sort(all(babies));
	rep1(i,H){
		int pos=upper_bound(all(babies),P(p,H))-babies.begin()-1;
		if(pos>=0&&babies[pos].fs==p) return i*H-babies[pos].sc;
		p=p*q%M;
	}
}
ll pre,parg;
void getnext(ll M,ll L,int id){
	ll p=L;
	ll gs[101];
	gs[0]=1;
	rep(i,100){
		gs[i+1]=gcd(p,M);
		if(gs[i]==gs[i+1]){
			a[id]=i;
			s[id]=geo(L,i,M);
			ll g=gs[i];
			c[id]=ex(L,i,M);
			M/=g;
			break;
		}
		p=p*L%M;
	}
	if(M==pre){
		m[id]=parg;
		return;
	}
	ll o=getord(M,L);
	ll ss=geo(L,o,M);
	m[id]=M/gcd(M,ss)*o;
	pre=M,parg=m[id];
}
ll getans(ll b,ll M,ll L){
	return (2*ex(L,b,M)+M-1)%M;
}
int solve(ll N,ll M,ll L){
	pre=-1;
	if(N==0) return 1;
	if(N==1) return L%M;
	if(N==2) return getans(1,M,L);
	if(N==3) return getans(2,M,L);
	if(N==4) return getans(2*(L+1),M,L);
	N++;
	m[N]=M;
	for(ll x=N-1;x>=4;x--){
		getnext(m[x+1],L,x);
	}
	b[4]=2*(L+1)%m[4];
	for(ll x=4;x<N;x++){
		ll p=(b[x]-a[x])%m[x];
		if(p<0) p+=m[x];
		b[x+1]=2*(s[x]+c[x]*geo(L,p,m[x+1]))%m[x+1];
	}
	return (b[N]*(L-1)+1)%M;
}
int main(){
	for(int t=1;;t++){
		ll N,M,L;
		cin>>N>>M>>L;
		if(M==0) break;
		printf("Case %d: %d\n",t,solve(N,M,L));
	}
}