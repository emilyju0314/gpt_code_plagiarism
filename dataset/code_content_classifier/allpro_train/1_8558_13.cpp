#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const double eps = 1e-8;

class P {
public:
	double x, y, z;
	P(){};
	P(double x, double y, double z) : x(x), y(y), z(z) {};
	P operator+(const P &p) {
		return P(x + p.x, y + p.y, z + p.z);
	}
	P operator-(const P &p) {
		return P(x - p.x, y - p.y, z - p.z);
	}
	P operator*(const double &n) {
		return P(x * n, y * n, z * n);
	}
	P operator/(const double &n) {
		return P(x / n, y / n, z / n);
	}
};

double dot(const P &a, const P &b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

P cross(const P &a, const P &b) {
	return P(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

int main() {
	P p[5];
	for (int i=0; i<5; ++i) cin >> p[i].x >> p[i].y >> p[i].z;

	P z = cross(p[3] - p[2], p[4] - p[2]);
	double a = dot(p[2] - p[0], z);
	double b = dot(p[1] - p[0], z);
	double c = abs(a);
	double d = abs(b) - c;

	if (abs(a) < eps || (b < -eps && eps < a) || (a < -eps && eps < b) || d < -eps) {
		cout << "HIT" << endl;
		return 0;
	}

	P i = (p[0] * d + p[1] * c) / (c + d);
	int plus = 0;
	if (-eps < dot(z, cross(p[3] - p[2], i - p[2]))) ++plus;
	if (-eps < dot(z, cross(p[4] - p[3], i - p[3]))) ++plus;
	if (-eps < dot(z, cross(p[2] - p[4], i - p[4]))) ++plus;
	int minus = 0;
	if (eps > dot(z, cross(p[3] - p[2], i - p[2]))) ++minus;
	if (eps > dot(z, cross(p[4] - p[3], i - p[3]))) ++minus;
	if (eps > dot(z, cross(p[2] - p[4], i - p[4]))) ++minus;

	cout << (plus == 3 || minus == 3 ? "MISS" : "HIT") << endl;
	return 0;
}