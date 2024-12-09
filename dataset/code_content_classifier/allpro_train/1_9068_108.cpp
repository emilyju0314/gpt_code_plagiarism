#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
ll n, k, Out;
ll ans[100005];

ll Pow(ll a, ll b){
	ll x = 1;
	while(b > 0){
		if(b & 1) x = x * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return x;
}

int main(){
	scanf("%lld%lld", &n, &k);
	for(ll i = k; i >= 1; i--){
		ans[i] = Pow(k / i, n);
		for(ll j = 2;j * i <= k; j++){
			ans[i] = ((ans[i] - ans[i * j]) % MOD + MOD) % MOD;
		}
		Out = (Out + ans[i] * i) % MOD;
	}
	printf("%lld\n", Out);
	return 0;
}