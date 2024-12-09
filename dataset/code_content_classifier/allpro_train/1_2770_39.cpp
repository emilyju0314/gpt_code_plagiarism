#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

class Point
{
public:
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}

	Point operator + (Point p) { return Point(x + p.x, y + p.y); }
	Point operator - (Point p) { return Point(x - p.x, y - p.y); }
	Point operator * (double a) { return Point(a * x, a * y); }
	Point operator / (double b) { return Point(x / b, y / b); }
	friend istream& operator >> (istream & s, Point p) { s >> p.x >> p.y; }

	double dot(Point a, Point b) { return a.x* b.x + a.y * b.y; }
	double abs() { return sqrt(norm()); }
	double norm() { return x * x + y * y; }

	bool operator <(const Point & p)const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const Point & p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};
typedef Point Vector;

struct Segment {
	Point p1, p2;
	Segment() {}
	Segment(Point p1, Point p2) :p1(p1), p2(p2) {}
};
typedef Segment Line;

double norm(Vector a) { return a.x* a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }

double dot(Vector a, Vector b) { return a.x* b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x* b.y - a.y * b.x; }

int ccw(Point p0, Point p1, Point p2) {        //判断有三个点构成的两个向量之间的关系（相反，同向（谁更大），逆时针方向，顺时针方向）
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;   //如果外积为正，那么就是顺时针
	if (cross(a, b) < -EPS) return CLOCKWISE;                             //如果外积为负，那么就是逆时针
	if (dot(a, b) < -EPS) return ONLINE_BACK;              //上面两种情况都不符合的时候，就一定在一条直线上，如果内积为负，那就是相反方向
	if (a.norm() < b.norm()) return ONLINE_FRONT;  //如果上面条件还不符合的话，那就按看谁的大了，
	return ON_SEGMENT;                 
}



bool intersect(Point p1, Point p2, Point p3, Point p4) {
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

int main()
{
	int q;
	cin >> q;
	double x0, y0, x1, y1, x2, y2, x3, y3;
	while (q--)
	{
		cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		Point p0 = Point(x0, y0), p1 = Point(x1, y1), p2 = Point(x2, y2), p3 = Point(x3, y3);
		cout << intersect(p0, p1, p2, p3) << endl;
	}
	return 0;
}
