#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int n,m;
ll s[100100];

ll calc(int d){
	int l = 0, r = m, k=0;
	ll ret = -INFLL, tmp = 0ll;
	while(l<n && r>d){
		if((r%d==0 && r/d<=k)){
			break;
		}
		tmp += (s[l]+s[r]);
		ret = max(ret, tmp);
		l += d;
		r -= d;
		++k;
	}
	return ret;
}

int main(void){
	int i,d;
	ll ans=0ll;
	cin >> n; m = n-1;
	for(i=0; i<n; ++i){
		cin >> s[i];
	}
	for(d=1; d<n; ++d){
		ans = max(ans,calc(d));
	}
	cout << ans << endl;
	return 0;
}
