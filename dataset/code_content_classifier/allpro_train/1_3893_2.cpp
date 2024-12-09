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

#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl
template<class T1, class T2> ostream& operator<<(ostream &s, pair<T1,T2> P){return s<<'<'<<P.first<<", "<<P.second<<'>';}
template<class T> ostream& operator<<(ostream &s, vector<T> P) {s<<"{ ";for(int i=0;i<P.size();++i){if(i>0)s<<", ";s<<P[i];}return s<<" }"<<endl;}
template<class T1, class T2> ostream& operator<<(ostream &s, map<T1,T2> P) {s<<"{ ";for(__typeof__(P.begin()) it=P.begin();it!=P.end();++it){if(it!=P.begin())s<<", ";s<<'<'<<it->first<<"->"<<it->second<<'>';}return s<<" }"<<endl;}




typedef long double DD;

const DD INF = 1LL<<29;
const DD EPS = 1e-6;
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
};



Line bisector(const Point &p, const Point &q) {
    Point c = (p + q) / 2.0L;
    Point v = (q - p) * Point(0.0L, 1.0L);
    v = v / abs(v);
    return Line(c - v, c + v);
}


typedef vector<Point> Polygon;
vector<Point> crosspoint(const Line &l, const Line &m) {
    vector<Point> res;
    DD d = cross(m[1] - m[0], l[1] - l[0]);
    if (abs(d) < EPS) return vector<Point>();
    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);
    return res;
}
Polygon convexcut(const Polygon &pol, const Line &l) {
    Polygon res;
    for (int i = 0; i < pol.size(); ++i) {
        Point p = pol[i], q = pol[(i+1)%pol.size()];
        if (ccw(l[0], l[1], p) != -1) {
            if (res.size() == 0) res.push_back(p);
            else if (!eq(p, res[res.size()-1])) res.push_back(p);
        }
        if (ccw(l[0], l[1], p) * ccw(l[0], l[1], q) < 0) {
            vector<Point> temp = crosspoint(Line(p, q), l);
            if (temp.size() == 0) continue;
            else if (res.size() == 0) res.push_back(temp[0]);
            else if (!eq(temp[0], res[res.size()-1])) res.push_back(temp[0]);
        }
    }
    return res;
}

Polygon Voronoi(Polygon pol, const vector<Point> &ps, int ind) {
    for (int i = 0; i < ps.size(); ++i) {
        if (i == ind) continue;
        Line l = bisector(ps[ind], ps[i]);
        pol = convexcut(pol, l);
    }
    return pol;
}


Point proj(Point p, Line l) {
    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
    return l[0] + (l[1] - l[0]) * t;
}

pair<DD,DD> exp(Polygon pol, Point p) {
    DD exp = 0.0L, sum = 0.0L;
    for (int i = 0; i < pol.size(); ++i) {
        DD temp, area;
        Point a = pol[i], b = pol[(i+1)%pol.size()];
        Point h = proj(p, Line(a, b));
        DD H = abs(p-h), A = abs(a-h), B = abs(b-h);
        
        if (ccw(a, b, h) == 0) temp = (H*H*3.0L + A*A - A*B + B*B) / 6.0L;
        else temp = temp = (H*H*3.0L + A*A + A*B + B*B) / 6.0L;
        area = abs(a-b) * H / 2.0L;
        
        exp += temp * area;
        sum += area;
    }
    exp /= sum;
    return make_pair(exp, sum);
}


int M, N;
Polygon pol;
vector<Point> ps;
vector<Polygon> vol;
double x, y;


int main() {
    while (cin >> M >> N) {
        pol.clear(); pol.resize(M);
        for (int i = 0; i < M; ++i) {
            cin >> x >> y;
            pol[i] = Point(x, y);
        }
        ps.clear(); ps.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            ps[i] = Point(x, y);
        }
        vol.clear(); vol.resize(N);
        for (int i = 0; i < N; ++i) {
            vol[i] = Voronoi(pol, ps, i);
        }
        
        DD res = 0.0, area = 0.0;
        for (int i = 0; i < N; ++i) {
            pair<DD,DD> temp = exp(vol[i], ps[i]);
            res += temp.first * temp.second;
            area += temp.second;
            
            //cout << i << " : " << temp << ", " << ps[i] << ", " << vol[i];
        }
        res /= area;
        
        //cout << res << endl;
        cout << fixed << setprecision(8) << res << endl;
    }
    
    return 0;
}
