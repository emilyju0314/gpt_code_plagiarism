#include <bits/stdc++.h>
using namespace std;
#define int long long
int P = 1000000007;
#define F first
#define S second
#define pb push_back
#define mp make_pair

void solve () {
	int n, c; cin >> n >> c; int a[n], b[n-1];
	int mi=INT_MAX;
	for (int i=0; i<n; ++i) {cin >> a[i];}
	for (int i=0; i<n-1; ++i) {cin >> b[i];}
	int cum=0, day=0;
	for (int i=0; i<n; ++i) {
		int k = (c-cum+a[i]-1)/a[i]+day;
		mi=min(mi,k);
		if (i==n-1) {break;}
		int x=(b[i]-cum+a[i]-1)/a[i];
		day+=x+1;
		cum=cum+x*a[i]-b[i];
		// cout << i << " " << cum << " " << day << " " << mi << '\n';
	}
	cout << mi << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    int t = 1;
    cin >> t;
    for (int _t=0; _t<t;++_t) {
        // cout << "Case #" << _t+1 << ": ";
        solve();
    }
}