#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int n, t;
	cin >> n >> t;
	int lst = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ans += t - max(0LL, lst - a);
		lst = a + t;
	}
	cout << ans << '\n';
	return 0;
}
