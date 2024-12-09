#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int mod = 1e9 + 7;
typedef vector<vi> M;
inline M operator*(const M & a, const M &b){
	M c(a.size(), vi(b[0].size()));
	rep(i, c.size()) rep(j, c[0].size()){
		ll s = 0;
		rep(k, a[0].size()) s += (ll)a[i][k] * b[k][j] % mod;
		c[i][j] = s % mod;
	}
	return c;
}
inline M pow(M a, ll m){
	M res(a.size(), vi(a.size()));
	rep(i, a.size()) res[i][i] = 1;
	for(; m; m /= 2){
		if(m & 1) res = res * a;
		a = a * a;
	}
	return res;
}

int n, K, c, T, a[1000], b[1000], t[1000];
int dp[10][40];


int main(){
	cin >> n >> K >> c >> T;
	rep(i, K) cin >> a[i] >> b[i] >> t[i], a[i]--;
	
	M A(5 * n, vi(5 * n));
	
	rep(s, 5 * n){
		memset(dp, 0, sizeof(dp));
		dp[s / n][s % n] = 1;
		rep(i, 5) rep(j, n) if(dp[i][j]) rep(k, K){
			int nj = j >= a[k] + b[k] ? j : j >= a[k] ? j - a[k] : j + b[k];
			(dp[i + t[k]][nj] += dp[i][j]) %= mod;
		}
		for(int i = 5; i < 10; i++) rep(j, n) (A[(i - 5) * n + j][s] += dp[i][j]) %= mod;
	}
	A = pow(A, T / 5);
	M x(5 * n, vi(1));
	x[c - 1][0] = 1;
	x = A * x;
	
	memset(dp, 0, sizeof(dp));
	rep(i, 5 * n) dp[i / n][i % n] = x[i][0];
	rep(i, 5) rep(j, n) if(dp[i][j]) rep(k, K){
		int nj = j >= a[k] + b[k] ? j : j >= a[k] ? j - a[k] : j + b[k];
		(dp[i + t[k]][nj] += dp[i][j]) %= mod;
	}
	cout << dp[T % 5][0] << endl;
	return 0;
}