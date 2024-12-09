#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

struct st {
	ll l, r;
	ll x, d;
};

bool operator<(const st& a, const st& b) {
	return a.l < b.l;
}

int n;
ll k;
ll a[120000];
int b[120000];
set<st> ss;

int main() {
	scanf("%d%lld", &n, &k);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld%d", a + i, b + i);
		a[i] *= 2;
		ans += a[i];
		if (a[i] > k && b[i] == 1) {
			cout << -1 << "\n";
			return 0;
		}
		if (b[i] == 2)
			a[i] %= k;
	}
	ss.insert({0, k, 0, 0});
	ll cur = 0;
	for (int i = 0; i < n; ++i) {
		ll d = a[i];
		ll nx = cur + d;
		if (nx > k)
			nx -= k;
		if (b[i] == 1) {
			if (cur < nx) {
				auto it = ss.lower_bound({cur, 0, 0, 0});
				while (it->r < nx)
					ss.erase(it++);
				st x1 = *it;
				st x2 = *it;
				ss.erase(it);
				x1.l = cur;
				x1.r = nx;
				x2.l = nx;
				x1.d = 1;
				x1.x = x2.x + x2.d * (x2.r - nx);
				ss.insert(x1);
				if (x2.l != x2.r)
					ss.insert(x2);
			}
			else {
				auto it = ss.lower_bound({cur, 0, 0, 0});
				while (it != ss.end())
					ss.erase(it++);
				it = ss.begin();
				while (it->r < nx)
					ss.erase(it++);
				st x1 = *it;
				st x2 = *it;
				ss.erase(it);
				x1.l = 0;
				x1.r = nx;
				x2.l = nx;
				x1.d = 1;
				x1.x = x2.x + x2.d * (x2.r - nx);
				ss.insert(x1);
				if (x2.l != x2.r)
					ss.insert(x2);
				x2.l = cur;
				x2.r = k;
				x2.d = 1;
				x2.x = x1.x + x1.d * x1.r;
				ss.insert(x2);
			}
			cur = (cur + a[i]) % k;
		}
		else {
			cur += a[i];
			cur %= k;
			auto it = ss.lower_bound({cur, 0, 0, 0});
			if (it == ss.begin())
				continue;
			--it;
			if (it->r <= cur)
				continue;
			st x1 = *it;
			st x2 = *it;
			ss.erase(it);
			x2.l = cur;
			x1.x = x2.x + x2.d * (x2.r - cur);
			x1.r = cur;
			ss.insert(x1);
			ss.insert(x2);
		}
	}
	ll mn = ss.begin()->x;
	for (auto x: ss)
		mn = min(mn, x.x);
	cout << ans + mn << "\n";
	return 0;
}


