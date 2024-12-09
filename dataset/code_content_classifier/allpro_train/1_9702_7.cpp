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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

int h, w;
void solve() {
	cin >> h >> w;
	vector<vector<int>> v(h);
	rep(i, h) {
		rep(j, w) {
			char t; cin >> t;
			if (t == 'B') {
				v[i].push_back(j);
			}
		}
		if (v[i].size() > 2) {
			v[i] = vector<int>{ v[i][0],v[i].back() };
		}
	}
	int ans = 0;
	rep(i, h) {
		Rep(j, i, h) {
			rep(k, v[i].size()) {
				rep(l, v[j].size()) {
					int dist = j - i + abs(v[i][k] - v[j][l]);
					ans = max(ans, dist);
				}
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}



