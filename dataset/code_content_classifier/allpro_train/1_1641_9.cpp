#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

struct Info{
	Info(ll arg_row1,ll arg_col1,ll arg_row2,ll arg_col2){
		row1 = arg_row1;
		col1 = arg_col1;
		row2 = arg_row2;
		col2 = arg_col2;
	}
	bool operator<(const struct Info &arg) const{

		if(row1 != arg.row1){

			return row1 < arg.row1;
		}else{

			return col1 < arg.col1;
		}
	}

	ll row1,col1,row2,col2;
};

ll H,W,K;
ll dp[1005];
ll fact[SIZE];


ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b != 0){
		d = extgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}else{
		x = 1;
		y = 0;
	}
	return d;
}

ll mod_pow(ll x,ll count, ll mod){

	if(count == 0)return 1;
	ll ret = mod_pow((x*x)%mod,count/2,mod);
	if(count%2 == 1){

		ret = (ret*x)%mod;
	}
	return ret;
}


ll mod_inverse(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}

ll mod_fact(ll n,ll p,ll &e){
	e = 0;
	if(n == 0)return 1;

	int res = mod_fact(n/p,p,e);
	e += n/p;

	if(n/p%2 != 0)return res*(p-fact[n%p])%p;
	return res*fact[n%p]%p;
}


ll nCm(ll n,ll m,ll p){
   if(n < m) return 0;
   ll e1,e2,e3;
   ll a1 = mod_fact(n,p,e1),a2 = mod_fact(m,p,e2),a3 = mod_fact(n-m,p,e3);
   if(e1 > e2+e3)return 0;
   return a1 * mod_inverse(a2*a3%p,p)%p;
}

void func(){

	vector<Info> V;

	ll col1,row1,col2,row2;

	for(int loop = 0; loop < K; loop++){

		scanf("%lld %lld %lld %lld",&col1,&row1,&col2,&row2);

		V.push_back(Info(row1,col1,row2,col2));
	}

	sort(V.begin(),V.end());

	ll minus,A,B;

	for(int i = 0; i < V.size(); i++){

		dp[i] = nCm(V[i].row1+V[i].col1-2,V[i].row1-1,MOD);

		for(int k = 0; k <= i-1; k++){
			if(V[k].col1 > V[i].col1)continue;

			A = nCm((V[i].row1-V[k].row1+V[i].col1-V[k].col1),V[i].row1-V[k].row1,MOD);
			if(V[k].col2 > V[i].col1 || V[k].row2 > V[i].row1){

				B = 0;

			}else{

				B = nCm((V[i].row1-V[k].row2+V[i].col1-V[k].col2),V[i].row1-V[k].row2,MOD);
			}

			minus = (A-B+MOD)%MOD;
			minus *= dp[k];
			minus %= MOD;

			dp[i] = (dp[i]-minus+MOD)%MOD;
		}
	}

	ll ans = nCm(H+W-2,H-1,MOD);

	for(int i = 0; i < V.size(); i++){

		A = nCm(H-V[i].row1+W-V[i].col1,H-V[i].row1,MOD);
		B = nCm(H-V[i].row2+W-V[i].col2,H-V[i].row2,MOD);

		minus = (A-B+MOD)%MOD;
		minus *= dp[i];
		minus %= MOD;

		ans = (ans-minus+MOD)%MOD;
	}

	printf("%lld\n",ans);
}


int main(){

	fact[0] = 1;
	for(ll i = 1; i < SIZE; i++){
		fact[i] = i*fact[i-1];
		fact[i] %= MOD;
	}

	while(true){

		scanf("%lld %lld %lld",&W,&H,&K);
		if(H == 0 && W == 0 && K == 0)break;

		func();
	}

	return 0;
}

