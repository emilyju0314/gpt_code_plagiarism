#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

signed main() {
	cout << setprecision(20);
	int n; cin >> n;
	vector<int> t(n), a(n);
	for (int i = 0; i < n; ++i)
		cin >> t[i] >> a[i];
	// パフォーマンスの累積をとる
	vector<ld> acc_perf(n + 1);
	acc_perf[0] = 1.0;
	for (int i = 1; i <= n; ++i)
		acc_perf[i] = acc_perf[i - 1] * ((ld)10 - a[i - 1]) / 10;
	// クエリに答える
	t.push_back(1000000001);
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		int il = lower_bound(t.begin(), t.end(), l) - t.begin();
		int ir = upper_bound(t.begin(), t.end(), r) - t.begin();
		ld rt = acc_perf[ir] / acc_perf[il];
		cout << (1e9 * rt) << endl;
	}
	return 0;
}
