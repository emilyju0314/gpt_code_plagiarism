#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
constexpr int MX = 10005, MOD = 1e9+7;
int n;
map<int,int> mp;
ll a, x, y, ac = 1, ac2;
void exgcd(ll a, ll b, ll &x, ll &y){
	if(b){
		exgcd(b, a%b, y, x);
		y -= a/b*x;
	}else{
		x = 1; y = 0;
	}
}
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%lld", &a);
		exgcd(a,MOD,x,y);
		ac2 += x;
		for(int t=2; t*t<=a; t++) if(a%t == 0){
			int k=0;
			for(; a%t == 0; a/=t) k++;
			mp[t] = max(mp[t],k);
		}
		if(a>1) mp[a] = max(mp[a],1);
	}
	ac2 %= MOD; ac2 += MOD;
	for(pair<int,int> it: mp){
		tie(x,y) = it;
		rep(i,y) (ac *= x) %= MOD;
	}
	printf("%lld\n",ac*ac2%MOD);
}