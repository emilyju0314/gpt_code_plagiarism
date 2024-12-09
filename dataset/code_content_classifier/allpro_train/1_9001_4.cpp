#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> i_i;
typedef pair<ld, int> ld_i;

ll INF = LLONG_MAX / 10;
ld EPS = 1e-18;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : abs(a);
}

struct segtree {
	int n; vector<ll> v;
	segtree(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll>(n * 2 - 1, INF);
	}
	void set(int i, ll x) {
		int k = i + n - 1;
		v[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = min(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	ll _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return INF;
		if (i <= l && r <= j) return v[k];
		ll vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
	ll get(int i, int j) { return _get(i, j, 0, 0, n); }
};

int main() {
	int N; cin >> N;
	vector<int> x(N), y(N), p(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i] >> p[i];
	ll mi = INF;
	map<i_i, int> mp;
	for (int i = 0; i < N; i++)
		if (x[i] || y[i]) {
			int d = gcd(x[i], y[i]);
			i_i xy(x[i] / d, y[i] / d);
			if (!mp.count(xy)) mp[xy] = INT_MAX;
			mp[xy] = min(mp[xy], p[i]);
		}
	vector<int> unko;
	for (auto z: mp) {
		i_i xy = z.first, _xy = i_i(-xy.first, -xy.second);
		if (mp.count(_xy)) {
			unko.push_back(mp[xy] + mp[_xy]);
			mp.erase(_xy);
		}
	}
	if (unko.size() >= 2) {
		sort(unko.begin(), unko.end());
		mi = min(mi, (ll)unko[0] + unko[1]);
	}
	vector<ld_i> v;
	for (int i = 0; i < N; i++)
		if (x[i] || y[i])
			v.push_back(ld_i(atan2l(y[i], x[i]), p[i]));
	N = v.size();
	sort(v.begin(), v.end());
	vector<ld> a(N * 2);
	segtree st(N * 2);
	ld PI = acosl(-1);
	for (int i = 0; i < N; i++) {
		a[i] = v[i].first;
		a[i + N] = a[i] + PI*2;
		st.set(i, v[i].second);
		st.set(i + N, v[i].second);
	}
	for (int i = 0; i < N; i++) {
		ll sum = st.get(i, i + 1);
		int l, r;
		l = upper_bound(a.begin(), a.end(), a[i] + PI/2 + EPS) - a.begin();
		r = lower_bound(a.begin(), a.end(), a[i] + PI - EPS) - a.begin();
		sum += st.get(l, r);
		l = upper_bound(a.begin(), a.end(), a[i] + PI + EPS) - a.begin();
		r = lower_bound(a.begin(), a.end(), a[i] + PI*3/2 - EPS) - a.begin();
		sum += st.get(l, r);
		mi = min(mi, sum);
	}
	if (mi == INF) mi = -1;
	cout << mi << endl;
}