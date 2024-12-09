#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<ll, ll> LP;
typedef long double ld;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

int n, m;

ll rsum[501];
//回数、前の位置([)
ld dp[502][501],cop[502][501];

void solve() {
	cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		rsum[i + 1] = rsum[i] + a[i];
	}
	rep(i, 502) {
		rep(j, 501) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, n + 1) {
			rep(k, n + 1){
				cop[j][k] = -INF;
		    }
		}
		rep(j, i + 1) {
			rep(k, i+ 1) {
				//cut
				ld ad = (rsum[i + 1] - rsum[k]) / (ld)(i + 1 - k);
				cop[j + 1][i+1] = max(cop[j + 1][i+1], dp[j][k] + ad);
				//non cut
				cop[j][k] = max(cop[j][k], dp[j][k]);
			}
		}
		rep(j, n + 1) {
			rep(k, n + 1) {
				dp[j][k] = cop[j][k];
			}
		}
	}
	ld ans = 0;
	rep(i, m + 1) {
		//cout << dp[i][n] << endl;
		ans = max(ans, dp[i][n]);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	solve();
	//stop
	return 0;
}
