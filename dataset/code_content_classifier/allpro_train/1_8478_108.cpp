#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll sq(ll num) { return num*num; }
ll mod_pow(ll x, ll n) {
	if (n == 0)return 1;
	if (n == 1)return x%MOD;
	ll res = sq(mod_pow(x, n / 2));
	res %= MOD;
	if (n % 2 == 1) {
		res *= x;
		res %= MOD;
	}
	return res;
}

ll n,m;

int main(){
	cin >> n >> m;
	vector<P> vp(m);
	vector<vector<ll>> cnt(2,vector<ll>(n,1));
	rep(i,m)cin >> vp[i].first >> vp[i].second;
	sort(ALL(vp));
	rep(i,m){
		ll num = vp[i].second;
		cnt[0][num] = max(cnt[0][num],cnt[0][num-1]+1);
		cnt[1][num-1] = max(cnt[1][num]+1,cnt[1][num-1]);
		// rep(j,n){
		// 	cout << cnt[0][j] << " " << cnt[1][j] << endl;
		// }
		// cout << endl;
	}
	rep(i,n){
		// cout << cnt[0][i] << " " << cnt[1][i] << endl;
		cout << cnt[0][i] + cnt[1][i] - 1;
		if(i != n-1)cout << " ";
		else cout << endl;
	}
}

