#include<bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll a[200000];

int main() {
	ll d, n, m;
	while (scanf("%lld", &d), d) {
		scanf("%lld%lld", &n, &m);
		rep(i, n - 1)scanf("%lld", &a[i]);
		a[n - 1] = 0; a[n] = d;
		sort(a, a + n + 1);
		a[n + 1] = a[n - 1] - d;
		sort(a, a + n + 2);
		ll cnt = 0;
		rep(i, m) {
			ll k; scanf("%lld", &k);
			ll*p = lower_bound(a, a + n + 2, k);
			cnt += min(*p - k, k - *(p - 1));
		}
		printf("%lld\n", cnt);
	}
}