#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)


struct Point3 {
	long double x;
	long double y;
	long double z;
	Point3() :x(0), y(0), z(0) {}
	Point3(const long double _x, const long double _y, const long double _z) :x(_x), y(_y), z(_z) {}
};

Point3 operator+(const Point3&l, const Point3& r) {
	return Point3(l.x + r.x, l.y + r.y, l.z + r.z);
}
Point3 operator+=(Point3&l, const Point3& r) {
	return l = Point3(l.x + r.x, l.y + r.y, l.z + r.z);
}
Point3 operator-(const Point3&l, const Point3& r) {
	return Point3(l.x - r.x, l.y - r.y, l.z - r.z);
}
Point3 operator-=(Point3&l, const Point3& r) {
	return l = Point3(l.x - r.x, l.y - r.y, l.z - r.z);
}
Point3 operator*(const Point3&l, const long double r) {
	return Point3(l.x * r, l.y * r, l.z * r);
}
Point3 operator*(const long double r, const Point3&l) {
	return l*r;
}
Point3 operator*=(Point3&l, const long double r) {
	return l = Point3(l.x * r, l.y * r, l.z * r);
}
Point3 operator/(const Point3&l, const long double r) {
	return Point3(l.x / r, l.y / r, l.z / r);
}
Point3 operator/=(Point3&l, const long double r) {
	return l = Point3(l.x / r, l.y / r, l.z / r);
}
const long double  pi = acos(-1.0);
const long double dtop = pi / 180.;
const long double ptod = 1. / dtop;

namespace std {
	bool operator<(const Point3 &lhs, const Point3 &rhs) {
		if (lhs.x< rhs.x - eps) return true;
		if (lhs.x > rhs.x + eps) return false;
		if (lhs.y< rhs.y - eps) return true;
		if (lhs.y > rhs.y + eps) return false;
		return lhs.z < rhs.z;
	}
}

// ????????\???
Point3 input_point() {
	long double x, y, z;
	cin >> x >> y >> z;
	return Point3(x, y, z);
}

// ????????????????????????
bool eq(const long double a, const long double b) {
	return (abs(a - b) < eps);
}

// ??????
long double dot(const Point3& a, const Point3& b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

// ??????
Point3 cross(const Point3& a, const Point3& b) {
	return Point3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}



//?????????
long double norm(const Point3&p) {
	return (p.x*p.x + p.y*p.y + p.z*p.z);
}

long double abs(const Point3&p) {

	return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}
//?????????????????????
Point3 unit(const Point3& a) {
	return a / (abs(a));
}




//???
struct Sphere {
	Point3 p;
	long double r;
	Sphere() :p(), r(0) {}
	Sphere(const Point3 _point, const long double _radius) :p(_point), r(_radius) {}
};

// ??´????????????
class Line3 {
public:
	Point3 a, b;
	Line3() : a(Point3(0, 0, 0)), b(Point3(0, 0, 0)) {}
	Line3(Point3 a, Point3 b) : a(a), b(b) {}
	Point3 operator[](const int _num)const {
		if (_num == 0)return a;
		else if (_num == 1)return b;
		else assert(false);
	}
};

// ?????????????????????
bool isis_sp(const Line3& s, const Point3& p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

// ??????????¶?
Point3 proj(const Line3 &l, const Point3& p) {
	long double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}
// ??´?????¨???????????¢
long double dist_lp3(const Line3& l, const Point3& p) {
	return abs(p - proj(l, p));
}
// ?????¨??´????????????
vector<Point3> is_lsp(const Sphere& c, const Line3& l) {
	vector<Point3> res;
	long double d = dist_lp3(l, c.p);
	if (d < c.r + eps) {
		long double len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;
		Point3 nor = (l.a - l.b) / abs(l.a - l.b);
		res.push_back(proj(l, c.p) + len * nor);
		res.push_back(proj(l, c.p) - len * nor);
	}
	return res;
}
// ?????¨???????????????
vector<Point3> is_ssp(const Sphere& c, const Line3& l) {
	vector<Point3> res(is_lsp(c, l));
	vector<Point3> nres;
	for (auto p : res) {
		if (isis_sp(l, p))nres.emplace_back(p);
	}
	return nres;
}
// ????????????????????¢(??????)??§???????°?
Point3 reflect(const Point3& vec, const Point3& no) {
	return vec - 2 * dot(vec, no) / abs(no)*unit(no);

}
const int moon_rad = 1800;
const int moon_orbit = 380000;
const ld moon_rtime = 2500000/60.;
const int kaguya_height = 100+moon_rad;
const int kaguya_rtime = 120;
int main() {
	int M, T; cin >> M >> T;
	const ld m_ini_theta = M*dtop;
	const ld k_ini_theta =  pi/2;
	int hides = 0;
	int sum = 0;
	for (ld t = 0; t < T; t += 0.01) {
		const ld m_now_theta = m_ini_theta + 2 * pi*t / moon_rtime;
		sum++;
		Sphere moon(Point3(moon_orbit*cos(m_now_theta), moon_orbit*sin(m_now_theta), 0), moon_rad);
		const ld k_now_theta = k_ini_theta + 2*pi*t / kaguya_rtime;
		Point3 kaguya(moon.p.x + (kaguya_height)*cos(k_now_theta), moon.p.y, moon.p.z + (kaguya_height)*sin(k_now_theta));
		Line3 l(Point3(), kaguya);
		vector<Point3> a(is_ssp(moon, l));
		if (!is_ssp(moon, l).empty()) {
			hides++;
		}
	}
	ld ans = hides / 100.;
	cout << ans << endl;
	return 0;
}