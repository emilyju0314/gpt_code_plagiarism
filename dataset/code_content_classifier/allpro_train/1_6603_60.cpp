#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define deb(x) cout << #x << " " << x << endl;
#define debtwo(x,y) cout << x << ", " << y << endl;
#define mod 1000000007
#define N 1000001

void solve() {
	ll n; cin >> n;

	if (n < 10) {
		cout << n << endl;
		return;
	}

	string res = "";
	ll val = 9;

	while (n) {
		res += to_string(min(val, n));
		n -= min(val, n);
		val -- ;
		if (val == 0) break;
	}

	if (n) {
		cout << -1 << endl;
		return;
	}

	reverse(res.begin(), res.end());

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t = 1;
	cin >> t;

	while (t--) {
		solve();
	}
}