#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define dump(a) (cerr << (#a) << " = " << (a) << endl)
#define FOR(it,c) for(__typeof((c).begin())it=(c).begin(); it!=(c).end();++it)
#define RFOR(it,c) for(__typeof((c).rbegin())it=(c).rbegin(); it!=(c).rend();++it)
#define exist(c, v) (find((c).begin(), (c).end(), (v)) != (c).end())

template<class T> inline void chmax(T& a, const T& b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, const T& b) { if(b < a) a = b; }

template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << '(' << p.first << ", " << p.second << ')';
	return os;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
	return os;
}

const double EPS = 1e-9;

struct point {
	double x, y;
	point(double x = 0.0, double y = 0.0):x(x), y(y) {}
	point(const point& p):x(p.x), y(p.y) {}

	point operator+ (const point& p) const {
		return point(x + p.x, y + p.y);
	}

	point operator- (const point& p) const {
		return point(x - p.x, y - p.y);
	}

	point operator* (const double s) const {
		return point(x * s, y * s);
	}

	point operator* (const point& p) const {
		return point(x * p.x - y * p.y, x * p.y + y * p.x);
	}

	point operator/ (const double s) const {
		return point(x / s, y / s);
	}

	bool operator< (const point& p) const {
		return x + EPS < p.x || abs(x - p.x) < EPS && y + EPS < p.y;
	}

	bool operator== (const point& p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
};

inline point rotate90(const point& p) {
	return point(-p.y, p.x);
}

inline point rotate(const point& p, const double theta) {
	const double s = sin(theta), c = cos(theta);
	return point(c * p.x - s * p.y, s * p.x + c * p.y);
}

inline double angle(const point& p) {
	return atan2(p.y, p.x);
}

inline double abs(const point& p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

inline double norm(const point& p) {
	return p.x * p.x + p.y * p.y;
}

inline double dot(const point& l, const point& r) {
	return l.x * r.x + l.y * r.y;
}

inline double cross(const point& l, const point& r) {
	return l.x * r.y - l.y * r.x;
}

struct line {
	point a, b;
	line(point a, point b):a(a), b(b){}
};

struct segment {
	point a, b;
	segment(point a, point b):a(a), b(b){}
};

struct circle {
	point c;
	double r;
	circle(point c, double r):c(c), r(r){}
};

typedef vector<point> polygon;

inline int ccw(const point& a, point b, point c) {
	b = b - a;
	c = c - a;
	const double tmp = cross(b, c);
	if(tmp > EPS) return 1; // ccw
	if(tmp < -EPS) return -1; // cw
	if(dot(b, c) < 0) return 2; // c, a, b 順に一直線上
	if(norm(b) < norm(c)) return -2; // a, b, c 順に一直線上
	return 0; //a, c, b 順で一直線上
}

inline point projection(const line& l, const point& p) {
	const point dif = l.b - l.a;
	const double tmp = dot(p - l.a, dif) / norm(dif);
	return l.a + dif * tmp;
}

inline bool intersect(const line& l, const line& m) {
	return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

inline bool intersect(const line& l, const segment& s) {
	return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

inline bool intersect(const line& l, const point& p) {
	return abs(ccw(l.a, l.b, p)) != -1;
}

inline bool intersect(const segment& s, const segment& t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

inline bool intersect(const segment& s, const point& p) {
	return ccw(s.a, s.b, p) == 0;
}

inline bool intersect(const circle& c, const point& p) {
	return abs(c.c - p) <= c.r + EPS;
}

inline bool intersect(const circle& c, const circle& d) {
	return abs(c.c - d.c) <= c.r + d.r && abs(c.c - d.c) >= abs(c.r - d.r);
}

inline double dist(const line& l, const point& p) {
	return abs(cross((l.b - l.a), (p - l.a))) / abs(l.b - l.a);
}

inline double dist(const line& l, const line& m) {
	return intersect(l, m) ? 0 : dist(l, m.a);
}

inline double dist(const line& l, const segment& s) {
	return intersect(l, s) ? 0 : min(dist(l, s.a), dist(l, s.b));
}

inline double dist(const segment& s, const point& p) {
	if(dot((s.b - s.a), (p - s.a)) < 0) return abs(p - s.a);
	if(dot((s.a - s.b), (p - s.b)) < 0) return abs(p - s.b);
	return dist(line(s.a, s.b), p);
}

inline double dist(const segment& s, const segment& t) {
	if(intersect(s, t))
		return 0;
	return min(min(dist(s, t.a), dist(s, t.b)), min(dist(t, s.a), dist(t, s.b)));
}

inline double dist(const point& a, const point& b) {
	return abs(a - b);
}

inline bool intersect(const circle& c, const segment& s) {
	return dist(s, c.c) < c.r + EPS;
}

inline point crosspoint(const line& l, const line& m) {
	const double tmp = cross(l.b - l.a, m.b - m.a);
	if(abs(tmp) < EPS) // 平行
		return l.a;
	return m.a + (m.b - m.a) * cross(l.b - l.a, l.a - m.a) * (1.0 / tmp);
}

inline point crosspoint(const segment& s, const segment& t) {
	if(!intersect(s, t)) // 交点を持たない
		return s.a; // 用改善

	const double tmp = cross(s.b - s.a, t.b - t.a);
	if(abs(tmp) < EPS) { // 一直線上
		if(intersect(s, t.a)) return t.a;
		if(intersect(s, t.b)) return t.b;
		if(intersect(t, s.a)) return s.a;
		return s.b;
	}

	return t.a + (t.b - t.a) * cross(s.b - s.a, s.b - t.a) * (1.0 / tmp);
}

//先に，intersectを用いて交差判定を行うこと
inline vector<point> crosspoint(const circle &c, const circle& d) {
	vector<point> res;
	if(abs(c.c - d.c) < EPS) // 中心の座標が同じ
		return res;

	const double tmp = abs(c.c - d.c);
	const double rc = (tmp * tmp + c.r * c.r - d.r * d.r) / (tmp + tmp);
	const double rs = sqrt(c.r * c.r - rc * rc);
	const point diff = (d.c - c.c) / tmp;
	res.push_back(point(c.c + diff * point(rc, rs)));
	res.push_back(point(c.c + diff * point(rc, -rs)));
	return res;
}

inline vector<point> crosspoint(const circle& c, const line& l) {
	vector<point> res;
	const point h = projection(l, c.c);
	const double d = abs(h - c.c);
	if(d > c.r - EPS) {
		res.push_back(h);
	}
	else if(d <= c.r - EPS) {
		point v = l.b - l.a;
		v = v * sqrt(c.r * c.r - d * d) / abs(v);
		res.push_back(h + v);
		res.push_back(h - v);
	}

	return res;
}

inline vector<point> crosspoint(const circle& c, const segment& s) {
	vector<point> res;
	vector<point> tmp = crosspoint(c, line(s.a, s.b));
	for(int i = 0; i < tmp.size(); ++i)
		if(intersect(s, tmp[i]))
			res.push_back(tmp[i]);

	return res;
}

inline double areaTriangle(point a, point b, const point& c) {
	a = a - c;
	b = b - c;
	return fabs(a.x * b.y - b.x * a.y) / 2.0;
}

inline double area(const polygon& p) {
	const int num = p.size();
	if(num < 3)
		return 0;

	if(num == 3)
		return areaTriangle(p[0], p[1], p[2]);

	double res = cross(p[num - 1], p[0]);
	for(int i = 1; i < num; ++i)
		res += cross(p[i - 1], p[i]);

	return abs(res) * 0.5;
}

// L.aからL.bの方向を見た場合に，点aが左側に来る．
inline line bisector(const point& a, const point& b) {
	return line(point((a.x - a.y + b.x + b.y) / 2.0, (a.y + a.x + b.y - b.x) / 2.0),
				point((a.x + a.y + b.x - b.y) / 2.0, (a.y - a.x + b.y + b.x) / 2.0));
}

// 点集合 pointsの凸包を求める．
inline polygon convex_hull(vector<point> points) {
	const int n = points.size();
	if(n <= 3)
		return points;

	sort(points.begin(), points.end());
	int k = 0;
	polygon res;
	res.resize(2 * n);
	for(int i = 0; i < n; res[k++] = points[i++])
		while(k >= 2 && ccw(res[k - 2], res[k - 1], points[i]) <= 0)
			--k;

	const int t = k + 1;
	for(int i = n - 2; i >= 0; res[k++] = points[i--])
		while(k >= t && ccw(res[k - 2], res[k - 1], points[i]) <= 0)
			--k;

	res.resize(k - 1);
	return res;
}

// L.aからL.bを向いた時の左側を残して切断する．
inline polygon convex_cut(const polygon& p, const line& l) {
	const int num = p.size();
	polygon res;
	for(int i = 0; i < num; ++i) {
		const int next = (i + 1) % num;
		const int tmp = ccw(l.a, l.b, p[i]);
		if(tmp != -1)
			res.push_back(p[i]);

		if(tmp * ccw(l.a, l.b, p[next]) < 0)
			res.push_back(crosspoint(l, line(p[i], p[next])));
	}

	return res;
}

vector<point> tangent(const circle& c, const point& p) {
	const double x = norm(p - c.c);
	double d = x - c.r * c.r;
	if(d < -EPS) return vector<point>();
	d = max(d, 0.0);
	const point q1 = (p - c.c) * (c.r * c.r / x);
	const point q2 = rotate90((p - c.c) * (-c.r * sqrt(d) / x));
	vector<point> res;
	res.push_back(c.c + q1 - q2);
	res.push_back(c.c + q1 + q2);
	return res;
}

vector<line> tangent(const circle &a, const circle& b) {
	vector<line> res;
	if(abs(a.r - b.r) < EPS) {
		point dir = b.c - a.c;
		dir = rotate90(dir * (a.r / abs(dir)));
		res.push_back(line(a.c + dir, b.c + dir));
		res.push_back(line(a.c - dir, b.c - dir));
	}
	else {
		point p = a.c * (-b.r) + b.c * a.r;
		p = p * (1.0 / (a.r - b.r));
		vector<point> ps = tangent(a, p), qs = tangent(b, p);
		for(int i = 0; i < min<int>(ps.size(), qs.size()); ++i)
			res.push_back(line(ps[i], qs[i]));
	}

	point p = a.c * b.r + b.c * a.r;
	p = p * (1.0 / (a.r + b.r));
	vector<point> ps = tangent(a, p), qs = tangent(b, p);
	for(int i = 0; i < min<int>(ps.size(), qs.size()); ++i)
		res.push_back(line(ps[i], qs[i]));

	return res;
}

// 三角形と点の包含関係，境界は含まない．
// 含める場合は == -1を <= 0とする．
bool contain_triangle(const polygon& triangle, const point& p) {
	const int d1 = ccw(p, triangle[0], triangle[1]), d2 = ccw(p, triangle[1], triangle[2]), d3 = ccw(p, triangle[2], triangle[0]);
	return !(d1 * d2 == -1 || d2 * d3 == -1 || d3 * d1 == -1);
}

// 多角形と点の包含関係．境界を含む．
bool contain(const polygon& P, const point& p) {
	const int n = P.size();
	bool res = false;
	for(int i = 0; i < n; ++i) {
		point v1 = P[i] - p, v2 = P[(i + 1) % n] - p;
		if(v1.y > v2.y)
			swap(v1, v2);

		if(v1.y < EPS && EPS < v2.y && cross(v1, v2) > EPS)
			res = !res;

		if(abs(cross(v1, v2)) < EPS && dot(v1, v2) < EPS)
			return true; // 境界を含まないなら，falseにする．
	}

	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	const int small = 0, large = 10000;
	polygon all;
	all.push_back(point(small, small));
	all.push_back(point(small, large));
	all.push_back(point(large, large));
	all.push_back(point(large, small));

	const double allS = area(all);
	int cnt = 0;

	for(int x1, y1, x2, y2, x3, y3; scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3), x1;) {
		polygon IC(all);
		IC = convex_cut(IC, bisector(point(x1, y1), point(x2, y2)));
		IC = convex_cut(IC, bisector(point(x1, y1), point(x3, y3)));
		const double ICS = area(IC);
		printf("%d %.5lf\n", ++cnt, ICS / allS);
	}

	return EXIT_SUCCESS;
}