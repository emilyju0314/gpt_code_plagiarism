#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
const double inf = 9999999.0;

const double pi = acos(-1.0);
struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y) {}
};

point operator + (const point& p1, const point& p2) { return point(p1.x + p2.x, p1.y + p2.y); }
point operator - (const point& p1, const point& p2) { return point(p1.x - p2.x, p1.y - p2.y); }
point operator * (const point& p1, double d) { return point(p1.x * d, p1.y * d); }
point operator / (const point& p1, double d) { return point(p1.x / d, p1.y / d); }

double sqr(double x) { return x * x; }
double dist(point p1, point p2) { return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y)); }
double dot(point p1, point p2) { return p1.x * p2.x + p1.y * p2.y; }
double det(point p1, point p2) { return p1.x * p2.y - p1.y * p2.x; }
int dcmp(double x) { return fabs(x) <= eps ? 0 : (x > 0 ? 1 : -1); }

point rot(point p) { return point(-p.y, p.x); }
point mid(point p, point q) { return (p + q) / 2.0; }
point inter(point p, point v, point q, point w)
{
	point u = p - q;
	double t = det(w, u) / det(v, w);
	return p + v * t;
}

double calc(double t, double v0, double v1, double a)
{
	double x = (v1 - v0 + a * t) / (2 * a);
	double vm = v0 + a * x;
	return (v0 + vm) * x / 2.0 + (vm + v1) * (t - x) / 2.0; 
}

double find(double v1, double v2, double L, double a)
{
	double l = fabs(v1 - v2) / a, r = inf;
	for (int i = 1; i <= 100; i ++)
	{
		double mid = (l + r) / 2.0;
		if (calc(mid, v1, v2, a) <= L) l = mid;
		else r = mid;
	}
	return l;
}

int n;
double amax;

point a[100001], b[100001];
double theta[100001], r[100001], l[100001];
double vr[100001];
double len[100001], rad[100001];
double ans = 0.0;

int main( )
{
	scanf("%d", &n);
	scanf("%lf", &amax);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lf %lf %lf %lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
		len[i] = dist(a[i], b[i]);
	}
	for (int i = 1; i < n; i ++)
	{
		point tmpx = b[i], tmpy = a[i + 1];
		point p = mid(tmpx, tmpy), rev = rot(tmpy - tmpx);
		
		point o = inter(p, rev, b[i], rot(a[i] - b[i]));
		rad[i] = dist(b[i], o);
		tmpx = b[i] - a[i];
		tmpy = b[i + 1] - a[i + 1];
		theta[i] = atan2(tmpy.y, tmpy.x) - atan2(tmpx.y, tmpx.x);
		if (dcmp(theta[i]) < 0) theta[i] += 2 * pi;
		if (dcmp(det(b[i] - a[i], a[i + 1] - a[i])) < 0) theta[i] = 2.0 * pi - theta[i];
		double vmax = sqrt(amax * rad[i]);
		r[i] = vmax, l[i + 1] = vmax;
	}
	l[1] = 0, r[n] = 0;
	for (int i = n - 1; i >= 1; i --)
		r[i] = min(r[i], sqrt(2.0 * len[i + 1] * amax + sqr(r[i + 1])));
	for (int i = 2; i <= n; i ++)
		l[i] = sqrt(2.0 * len[i] * amax + sqr(r[i]));
	double now = 0.0; 
	for (int i = 1; i <= n; i ++)
	{
		ans += find(now, r[i], len[i], amax);
		now = min(sqrt(sqr(now) + 2.0 * len[i] * amax), r[i]);
		if (i != n) ans += theta[i] * rad[i] / now;
	}
	printf("%.9f\n", ans);
	return 0;
}
// a = sqr(v) / r;
// r[i] maxv enter the seg
// l[i] 