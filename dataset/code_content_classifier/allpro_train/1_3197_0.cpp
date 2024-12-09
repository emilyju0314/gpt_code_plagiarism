#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }

ll fast_modmul(ll a,ll b,ll m){
	return (((a*(b>>20)%m)<<20)+a*(b&((1<<20)-1)))%m;
}

ll fast_modpow(ll a,ll n,ll m){
	ll r=1;
	for(ll x=a%m;n;n>>=1,x=(x*x)%m) if(n&1) r=(r*x)%m;
	return r;
}

ll modmul(ll a,ll b,ll m){
	ll r=0;
	for(;b;b>>=1,a=(a<<1)%m) if(b&1) r=(r+a)%m;
	return r;
}

ll modpow(ll a,ll n,ll m){
	ll r=1;
	for(ll x=a%m;n;n>>=1,x=modmul(x,x,m)) if(n&1) r=modmul(r,x,m);
	return r;
}

bool Miller_Rabin(ll n){
	if(n<=1)   return false;
	if(!(n&1)) return n==2;
	if(n%3==0) return n==3;

	int s=0; // n-1 = 2^s * d (d: odd)
	ll d=n-1;
	while(!(d&1)) s++, d>>=1;

	const static ll a[]={2,3,5,7,11,13,17,19,23};
	rep(i,sizeof a/sizeof(ll)){
		if(a[i]>=n) break;

		ll x=modpow(a[i],d,n);
		if(x==1 || x==n-1) continue;
		bool b=false;
		for(int r=1;r<s;r++){
			x=modmul(x,x,n);
			if(x== 1 ) return false;
			if(x==n-1){ b=true; break; }
		}
		if(!b) return false;
	}

	return true;
}

ll Pollard_rho(ll n,int c){
	if((n&1)==0) return 2;

	ll x=2,y=2,d=1;
	while(d==1){
		x=modmul(x,x,n)+c; if(x<0) x+=n;
		y=modmul(y,y,n)+c; if(y<0) y+=n;
		y=modmul(y,y,n)+c; if(y<0) y+=n;
		d=gcd(llabs(x-y),n);
	}
	return d<n?d:-1;
}

void prime_factorize(ll n,map<ll,int> &pf){
	if(n<=1) return;
	if(Miller_Rabin(n)){ ++pf[n]; return; }

	ll d;
	for(int c=1;;c++){
		d=Pollard_rho(n,c);
		if(d!=-1) break;
	}

	prime_factorize( d ,pf);
	prime_factorize(n/d,pf);
}

void dfs(int i,ll a,const vector< pair<ll,int> > &pf,vector<ll> &res){
	if(i==pf.size()){
		res.push_back(a);
		return;
	}

	dfs(i+1,a,pf,res);
	rep(j,pf[i].second){
		a*=pf[i].first;
		dfs(i+1,a,pf,res);
	}
}

const ll M=1000000007;

int main(){
	int n; scanf("%d",&n);
	ll o[1000],p[1000];
	rep(i,n) scanf("%lld%lld",o+i,p+i);

	rep(i,n){
		rep(j,i) if(o[i]==o[j]) {
			p[j]+=p[i];
			swap(o[i],o[n-1]);
			swap(p[i],p[n-1]);
			i--;
			n--;
			break;
		}
	}

	// 多項式 Σ p[i] * x^o[i] の正の重根を求めればよい

	// 0 は答えじゃないので x^hoge で割って定数項が見えるようにする
	ll o_min=*min_element(o,o+n);
	rep(i,n) o[i]-=o_min;

	ll c; // 定数項
	rep(i,n) if(o[i]==0) c=p[i];

	map<ll,int> pf;
	prime_factorize(llabs(c),pf);

	vector<ll> d; // c の約数全体
	vector< pair<ll,int> > pf2(pf.begin(),pf.end());
	dfs(0,1,pf2,d);

	sort(d.begin(),d.end());

	rep(i,d.size()){
		ll x=d[i];

		if(x>M) break; // 大きい約数はどうせ答えじゃないので見ない ( TLE がきつい!! )

		ll val1=0,val2=0;
		rep(i,n){
			ll q=llabs(p[i])%M;
			int sgn=(p[i]>0?1:-1);
			val1=(val1+sgn*fast_modmul(q,fast_modpow(x%M,o[i],M),M)+M)%M;
			if(o[i]>0){
				val2=(val2+sgn*fast_modmul(fast_modmul(o[i],q,M),fast_modpow(x%M,o[i]-1,M),M)+M)%M;
			}
		}

		if(val1==0 && val2==0){ printf("Yes %lld\n",x); return 0; }
	}

	puts("No");

	return 0;
}