#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000;
int n;
ll a[maxn + 10], b[maxn + 10], sa, sb, ans, tot;
bool vis[maxn * 2 + 10];
struct node {
	int id; ll v;
	bool operator < (const node &t) const {
		return v < t.v;
	}
}c[maxn * 2 + 10];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &a[i], &b[i]);
		sa += a[i]; sb += b[i];
		c[i * 2 - 1] = (node){i * 2 - 1, a[i]};
		c[i * 2] = (node){i * 2, b[i]};
	}
	ans = min(sa, sb);
	sort(c + 1, c + n * 2 + 1);
	for (int i = 1; i <= n - 2; ++i) {
		tot += c[i].v; vis[c[i].id] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		ll now = tot + a[i] + b[i];
		int cnt = n - 2;
		if (vis[i * 2 - 1]) {
			now -= a[i]; 
			++cnt;
			if (c[cnt].id == i * 2 || c[cnt].id == i * 2 - 1) ++cnt;
			now += c[cnt].v;
		}
		if (vis[i * 2]) {
			now -= b[i]; 
			++cnt;
			if (c[cnt].id == i * 2 || c[cnt].id == i * 2 - 1) ++cnt;
			now += c[cnt].v;
		}
		ans = min(ans, now);
	}
	printf("%lld", ans);
}
