#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define dbg(x) cout << #x << " : " << x << endl;
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

void solve() {
	int n, k, x; cin >> n >> k >> x;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	vector<int> needed;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > x) needed.push_back((a[i] - a[i - 1] - 1) / x);
	}
	sort(needed.begin(), needed.end());
	for (int i = 1; i < needed.size(); i++) {
		needed[i] += needed[i - 1];
	}
	int idx = upper_bound(needed.begin(), needed.end(), k) - needed.begin();
	int ans = needed.size() - idx + 1;
	cout << ans << endl;
}

int32_t main() {
	fio();
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
	return 0;
}