#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef pair<int,int> pint;
typedef pair<long long, long long> pll;

#define MP make_pair
#define PB push_back
#define ALL(s) (s).begin(),(s).end()
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P) 
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P) 
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P) 
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }



typedef double DD;

const DD INF = 1LL<<30;
const DD EPS = 1e-10;
const DD PI = acos(-1.0);
DD torad(int deg) {return (DD)(deg) * PI / 180;}
DD todeg(DD ang) {return ang * 180 / PI;}

struct Point {
    DD x, y;
    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}
};

Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
Point operator * (const Point &p, DD a) {return Point(p.x * a, p.y * a);}
Point operator * (DD a, const Point &p) {return Point(a * p.x, a * p.y);}
Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
Point operator / (const Point &p, DD a) {return Point(p.x / a, p.y / a);}
Point conj(const Point &p) {return Point(p.x, -p.y);}
Point rot(const Point &p, DD ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
Point rot90(const Point &p) {return Point(-p.y, p.x);}
DD cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
DD dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
DD norm(const Point &p) {return dot(p, p);}
DD abs(const Point &p) {return sqrt(dot(p, p));}
DD amp(const Point &p) {DD res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}
bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

int ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b-a, c-a) > EPS) return 1;
    if (cross(b-a, c-a) < -EPS) return -1;
    if (dot(b-a, c-a) < -EPS) return 2;
    if (norm(b-a) < norm(c-a) - EPS) return -2;
    return 0;
}

struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream& operator << (ostream &s, const Line &l) {return s << '{' << l[0] << ", " << l[1] << '}';}
};


Point proj(Point p, Line l) {
    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
    return l[0] + (l[1] - l[0]) * t;
}
Point refl(Point p, Line l) {
    return p + (proj(p, l) - p) * 2;
}
bool isinterPL(Point p, Line l) {
    return (abs(p - proj(p, l)) < EPS);
}
bool isinterPS(Point p, Line s) {
    return (ccw(s[0], s[1], p) == 0);
}
bool isinterLL(Line l, Line m) {
    return (abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||
            abs(cross(l[1] - l[0], m[0] - l[0])) < EPS);
}
bool isinterSS(Line s, Line t) {
    if (eq(s[0], s[1])) return isinterPS(s[0], t);
    if (eq(t[0], t[1])) return isinterPS(t[0], s);
    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 && 
            ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);
}


int n[2];
Point pos[2][2100];

int main() {
    //freopen( "/Users/macuser/Dropbox/Contest/input.in", "r", stdin );
    
	while (cin >> n[0] >> n[1]) {
		for (int it = 0; it < 2; ++it)
			for (int i = 0; i < n[it]; ++i)
				cin >> pos[it][i].x >> pos[it][i].y;
		
		DD res = INF;
		for (int it = 0; it < 2; ++it) {
			Line l(pos[1-it][0], pos[1-it][1]);		// これと交わってはダメ
			DD dl = abs(pos[1-it][0] - pos[1-it][1]);

			DD dist[2100];
			for (int i = 0; i < n[it]; ++i) dist[i] = INF;
			dist[0] = 0;
			bool seen[2100];
			memset(seen, 0, sizeof(seen));
			for (int i = 0; i < n[it]; ++i) {
				double Min = INF + 10;
				int pMin = -1;
				for (int j = 0; j < n[it]; ++j) {
					if (seen[j]) continue;
					if (chmin(Min, dist[j])) pMin = j;
				}
				//cout << pMin << ", " << Min << endl;
				if (pMin == -1) continue;
				for (int j = 0; j < n[it]; ++j) {
					if ( isinterSS(Line(pos[it][pMin], pos[it][j]), l) ) continue;
					chmin(dist[j], dist[pMin] + abs(pos[it][j] - pos[it][pMin]));
				}
				seen[pMin] = true;
			}
			chmin(res, dist[1] + dl);
		}
		if (res >= INF - EPS) res = -1.000000000000000;
		cout << fixed << setprecision(10) << res << endl;
	}
    return 0;
}
