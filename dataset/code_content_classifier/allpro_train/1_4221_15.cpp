#include <bits/stdc++.h>
using namespace std;

const long long maxn = 2e5+10, inf = 1e18+10;
long long n, d, a;
pair<long long,long long> p[maxn];
long long tag[maxn];

signed main() {
	cin >> n >> d >> a;
	for (long long i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p+n);
	p[n].first = inf;
	long long cur = 0, ans = 0;
	for (long long i = 0; i < n; ++i) {
		cur += tag[i];
//		cout << i << ' ' << cur << ' ' << ans << endl;
		if (cur < p[i].second) {
			long long y = upper_bound(p, p+n, make_pair(p[i].first+2*d, inf))-p, tmp = ((p[i].second-cur+a-1)/a);
			tag[y] -= tmp*a, cur += tmp*a;
			ans += tmp;
		}
	}
	cout << ans << endl;
	return 0;
}
