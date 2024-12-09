#include <cstdio>
#include <vector>
#include <iostream>
#include <complex>
#include <algorithm>
using namespace std;
typedef complex<double> P;
namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
}
int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)	return +1;	// counter clockwise
	if (cross(b, c) < 0)	return -1;	// clockwise
	if (dot(b, c) < 0)		return +2;	// c--a--b on line
	if (norm(b) < norm(c))	return -2;	// a--b--c on line
	return 0;
}
vector<P> convex_hull(vector<P> ps) {
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<P> ch(2 * n);
	for (int i = 0; i < n; i++, k++) { // lower-hull
		while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
		ch[k] = ps[i];
	}
	for (int i = n-2, t = k + 1; i >= 0; k++, i--) { // upper-hull
		while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
		ch[k] = ps[i];
	}
	ch.resize(k - 1);
	return ch;
}
int main () {
	int n;
	while (cin >> n, n) {
		vector<P> points(n);
		for (int i = 0; i < n; i ++) {
			double x, y;
			scanf("%lf,%lf", &x, &y);
			points[i] = P(x, y);
		}
		cout << n - convex_hull(points).size() << endl;
	}
	return 0;
}