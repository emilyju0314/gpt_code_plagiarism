#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long double r, x, y, p[100], PI = 3.14159265358979l; int n;
struct Point { long double px, py; };
long double crs(const Point& a, const Point& b) { return a.px * b.py - a.py * b.px; }
long double area(vector<Point> v) {
	long double ret = 0.0L;
	for (int i = 0; i < v.size(); i++) ret += crs(v[i], v[(i + 1) % v.size()]);
	return ret / 2;
}
int main() {
	cin >> r >> x >> y >> n; long double s = 450.0l;
	for (int i = 0; i < n; i++) { cin >> p[i]; p[i] *= 3.6l; }
	for (int i = 0; i < n; i++) {
		if (i)cout << ' ';
		long double W1 = r*r*(p[i] / 360.0l)*PI;
		long double W3 = -p[i];
		Point p1 = { 0,0 };
		Point p2 = { r*cos(s*PI / 180.0l),r*sin(s*PI / 180.0l) };
		Point p3 = { x,y }; s += W3;
		Point p4 = { r*cos(s*PI / 180.0l),r*sin(s*PI / 180.0l) };
		long double W2 = area(vector<Point>{p1, p2, p3, p4});
		cout << (int)(100.0l*(W1 + W2) / W1);
	}
	cout << endl;
	return 0;
}