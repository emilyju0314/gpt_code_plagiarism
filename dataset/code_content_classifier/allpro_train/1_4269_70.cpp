#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tt;
	cin >> tt;

	while (tt--) {
		int x, y;
		cin >> x >> y;

		int k = 1, ans = 0;

		while (min(y, (x-k)/k) - k > 0) {
			ans += min(y, (x-k)/k) - k;

			k++;
		}

		cout << ans << '\n';
	}	
}