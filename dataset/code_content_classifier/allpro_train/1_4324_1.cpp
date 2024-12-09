#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef double R;

int n, m;

const int MK = 550*550;
const R PI = acos((R)-1);
const R EPS = 1e-9;

int k;
R ar[MK];
ll buf[MK], sm[MK];

ll solve(int x, int y) {



	k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == x && j == y) continue;
			ar[k] = arg(complex<R>(i-x, j-y));
			ar[k] += EPS;
			k++;
		}
	}
	sort(ar, ar+k);
	for (int i = 0; i < k; i++) {
//		printf("%lf ", ar[i] / PI);
		buf[i] = lower_bound(ar, ar+k, ar[i]+PI+EPS) - ar;
//		printf("%lld\n", buf[i]);
	}// printf("\n");

	sm[0] = 0;
	for (int i = 1; i <= k; i++) {
		sm[i] = sm[i-1] + buf[i-1];
	}

	ll res = 0;//n*m - 1 C 2

	for (int i = 0; i < k; i++) {
		ll l = lower_bound(ar, ar+k, ar[i]+EPS) - ar;
		ll r = lower_bound(ar, ar+k, ar[i]+PI-EPS) - ar;
		res += sm[r]-sm[l];
		res -= (r-l)*r;

		ll l2 = lower_bound(ar, ar+k, ar[i]+PI-EPS) - ar;
		ll r2 = lower_bound(ar, ar+k, ar[i]+PI+EPS) - ar;
		//rr-ll
		res += (r2-l2) * (k-r2);

		res += (k-(r2-l2 + l));
//		printf("%lf %d %lld %lld %d %lld\n", ar[i], k, r2, l2, i, (k-(r2-l2+l)));
	}
//	printf("a\n");
	return res;
}

int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
//	printf("%lld %lld\n", solve(x1, y1), solve(x2, y2));
	cout << abs(solve(x1, y1) - solve(x2, y2)) << endl;
    return 0;
}