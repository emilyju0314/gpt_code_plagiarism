#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;

int n, q, t, i;
ll s[N], ans[N], f[N] , j, k;

int main () {
	scanf("%d%d", &n, &q);
	s[t = 1] = n;
	for (i = 1; i <= q; ++i) {
		scanf("%lld", &j);
		while (t && j <= s[t]) --t; s[++t] = j;
	}
	f[t] = 1;
	for (i = t; i > 0; --i) {
		k = s[i], j = i;
		while ((j = lower_bound(s + 1, s + j + 1, k) - s - 1) > 0) {
			f[j] += k / s[j] * f[i];
			k %= s[j];
		}
//		ans[n] += k / n * f[i];
//		ans[k % n] += f[i];
		ans[k] += f[i];
	}
	for (i = n - 1; i; --i) ans[i] += ans[i + 1];
	for (i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
	return 0;
}