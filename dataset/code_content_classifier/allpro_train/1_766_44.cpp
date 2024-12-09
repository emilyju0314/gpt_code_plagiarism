#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <algorithm>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;
typedef complex<double> Point;

int n;
double sx, sy, ex, ey;
double lx[50], ly[50], rx[50], ry[50], h[50];

double dot(Point a, Point b) {
	return a.real() * b.real() + a.imag() * b.imag();
}

double cross(Point a, Point b) {
	return a.real() * b.imag() - a.imag() * b.real();
}

int ccw(Point a, Point b, Point c) {
	b -= a;
	c -= a;
	if (cross(b, c) > 0) return +1;		//counter clockwise
	if (cross(b, c) < 0) return -1;		//clockwise
	if (dot(b, c) < 0) return +2;		//c--a--b on line.
	if (norm(b) < norm(c)) return -2;	//a--b--c on line.
	return 0;
}

bool is_intersect(Point a, Point b, Point c, Point d) {
	return ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0;
}

//in:2, on:1, out:0
int is_cover(vector<Point> poly, Point p) {
	int n = poly.size() - 1;
	int i;
	
	bool in = false;
	rep(i, n) {
		Point a = poly[i] - p;
		Point b = poly[i + 1] - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
			if (cross(a, b) > 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
	}
	return in ? 2 : 0;
}

//S:Segment(線分), P:Point(点)
double dist_SP(Point s, Point e, Point p) {
	if (dot(e - s, p - s) < 0) return abs(p - s);
	if (dot(s - e, p - e) < 0) return abs(p - e);
	return abs(cross(e - s, p - s)) / abs(e - s);
}

double dist_SS(Point a, Point b, Point c, Point d) {
	return min({
	dist_SP(a, b, c),
	dist_SP(a, b, d),
	dist_SP(c, d, a),
	dist_SP(c, d, b)});
}

//A: Area(閉面）
double dist_AS(vector<Point> poly, Point a, Point b) {
	int n = poly.size() - 1;
	int i;
	double ret;
	rep(i, n) {
		double res = dist_SS(poly[i], poly[i + 1], a, b);
		if (i == 0) ret = res;
		else ret = min(ret, res);
	}
	return ret;
}

bool pre_check() {
	int i, j;
	Point s = Point(sx, sy);
	Point e = Point(ex, ey);
	
	rep(i, n) {
		vector<Point> poly;
		poly.push_back(Point(lx[i], ly[i]));
		poly.push_back(Point(rx[i], ly[i]));
		poly.push_back(Point(rx[i], ry[i]));
		poly.push_back(Point(lx[i], ry[i]));
		poly.push_back(poly[0]);
		
		rep(j, 4) {
			if (is_intersect(poly[j], poly[j + 1], s, e)) {
				return false;
			}
		}
		if (is_cover(poly, s) >= 1) return false;
		if (is_cover(poly, e) >= 1) return false;
	}
	return true;
}

bool check(double r) {
	int i, j;
	Point s = Point(sx, sy);
	Point e = Point(ex, ey);
	
	//平面幾何 (線分と線分の距離）に帰着する
	rep(i, n) {
		vector<Point> poly;
		poly.push_back(Point(lx[i], ly[i]));
		poly.push_back(Point(rx[i], ly[i]));
		poly.push_back(Point(rx[i], ry[i]));
		poly.push_back(Point(lx[i], ry[i]));
		poly.push_back(poly[0]);
		
		double d = dist_AS(poly, s, e);
		double length;
		if (h[i] >= r) {
			length = d;
		}
		else {
			length = sqrt(d * d + (r - h[i]) * (r - h[i]));
		}
		if (length <= r) return false;
	}
	return true;
}

int main() {
	int i;

	while (cin >> n) {
		if (!n) break;
		cin >> sx >> sy >> ex >> ey;
		rep(i, n) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i] >> h[i];
		if (!pre_check()) { cout << 0 << endl; continue; }
		
		double st = 0, ed = 1e+5, mid;
		rep(i, 150) {
			mid = (st + ed) / 2;
			if (check(mid)) st = mid;
			else ed = mid;
		}
		printf("%.14f\n", st);
	}
	return 0;
}
