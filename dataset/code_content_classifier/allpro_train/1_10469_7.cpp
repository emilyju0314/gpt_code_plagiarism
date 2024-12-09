#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const double INF = 1e18;
constexpr double EPS = 1e-8;

using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
struct Segment { Point a, b; };
struct Circle{ Point c; double r; };

template<class T> bool eq(const T &a, const T &b) { return abs(a - b) < EPS; }
namespace std {
bool operator == (const Point &a, const Point &b) { return eq(X(a), X(b)) and eq(Y(a), Y(b)); }
bool operator <  (const Point &a, const Point &b) { return X(a) == X(b) ? Y(a) < Y(b) : X(a) < X(b); }
istream& operator >> (istream &is, Point &a) { double x, y; is >> x >> y; a.X(x); a.Y(y); return is; }
double norm(const Point &p) { assert(0); } // complex ??? norm ?????????
}
double dot     (const Point &a, const Point &b) { return a.X() * b.X() + a.Y() * b.Y(); }
double cross   (const Point &a, const Point &b) { return a.X() * b.Y() - a.Y() * b.X(); }
double length2 (const Point &p         ) { return p.X() * p.X() + p.Y() * p.Y(); }
double length  (const Point &p         ) { return sqrt(length2(p)); }
double distance(const Point &a, const Point &b) { return length(a - b); }
double arg     (const Point &a)          { return atan2(Y(a), X(a)); } // -> [-pi, pi],  (0, 0) is invalid!
Point  unit    (const Point &p         ) { return p / length(p); }
Point orthonormal(Point &p) { // ??£?????´???????????????
    Point p2 = Point(-1 * p.Y(), p.X()); // = rotate(p, 90);
    return p2 / length(p2);
}
enum ccw_t { // ??????????????¢??¨????????§ ccw_t ??? int ??§??????????????????????????¨???
    COUNTER_CLOCK_WISE = 1,
    CLOCK_WISE = -1,
    STRAIGHT_C_A_B = 2,
    STRAIGHT_A_B_C = -2,
    STRAIGHT_A_C_B = 0
};
ccw_t ccw(const Point &a, const Point &b, const Point &c){
    Point ab = b - a, ac = c - a;
    if( cross(ab,ac) > EPS ) return COUNTER_CLOCK_WISE; // +1 a-b-c ???????¨???????
    if( cross(ab,ac) < -EPS ) return CLOCK_WISE;        // -1 a-b-c ????¨???????
    if( dot(ab,ac) < -EPS ) return STRAIGHT_C_A_B;      // +2 c-a-b
    if( length2(ab) < length2(ac) )return STRAIGHT_A_B_C;     // -2 a-b-c or a==b
    return STRAIGHT_A_C_B;                              //  0 a-c-b or b==c or a==c
}
// Segment
bool operator == (Segment a, Segment b) { return a.a == b.a and a.b == b.b; }
bool operator != (Segment a, Segment b) { return a.a == b.a and a.b == b.b; }
istream &operator >> (istream& is, Segment& s){ return is >> s.a >> s.b;}
ostream &operator << (ostream& os, const Segment& s){ return os << s.a << "->" << s.b;}

double length(Segment s) { return distance(s.a, s.b); }
double distance( Segment s ,const Point &p) {
    if( dot( s.b - s.a , p - s.a ) < EPS ) return distance(p, s.a);
    if( dot( s.a - s.b , p - s.b ) < EPS ) return distance(p, s.b);
    return abs(cross( s.b - s.a , p - s.a ) / distance(s.b, s.a));
}
bool does_intersect(Segment a, Segment b){
    return (int)ccw(a.a, a.b, b.a) * (int)ccw(a.a, a.b, b.b) <= 0 &&
           (int)ccw(b.a, b.b, a.a) * (int)ccw(b.a, b.b, a.b) <= 0;
}

bool does_include(Segment s, const Point &p){
    Point a = p - s.a , b = s.b - s.a;
    return ( abs(cross(a,b)) < EPS and dot(a,b) > -EPS and length(s)  > dot(a,b) / length(s) - EPS);
}
Point intersection(Segment a, Segment b) {
    assert(does_intersect(a, b));
    double p = cross(a.b - a.a, b.b - b.a);
    double q = cross(a.b - a.a, a.b - b.a);
    if(abs(p) < EPS and abs(q) < EPS) return a.a;
    if(abs(p) < EPS) assert(0);
    return q / p * (b.b - b.a) + b.a;
}
Point projection(Segment l, const Point &p) {
    double t = dot(p-l.a, l.a-l.b) / length2(l.a - l.b);
    Point ret = (l.a-l.b);
    return ret * t + l.a;
}

vector<Point> cross_points(Circle c1, Circle c2) {
    double d = distance(c1.c, c2.c);
    assert(d > 0);
    // c1.c ?????????c1,c2????????????????????´?????¨c1.c->c2.c ??????????????§????????¢
    double x = (pow(c1.r, 2) - pow(c2.r, 2) + pow(d, 2)) / (2 * d);
    if(c1.r < x) return {};
    double h = sqrt(pow(c1.r, 2) - pow(x, 2));    
    Point mid = unit(c2.c - c1.c) * x;
    if(eq(h, 0.0)) return { c1.c + mid };
    Point vertical = unit(Point(-Y(mid), X(mid))) * h; // ???????????????????????????
    return { c1.c + mid + vertical, c1.c + mid - vertical };
}

Point nearest_grid_point(const Point &p) {
    return Point{round(p.X()), round(p.Y())};
}

class Solver {
  public:
    bool solve() {
        Point a, b, c; cin >> a >> b >> c;
        if(a.X() == 0 and a.Y() == 0 and
           b.X() == 0 and b.Y() == 0 and
           c.X() == 0 and c.Y() == 0) return 0;
        // if(ccw(a, b, c) != COUNTER_CLOCK_WISE) swap(b, c);
        // assert(ccw(a, b, c) == COUNTER_CLOCK_WISE);
        // assert(ccw(b, c, a) == COUNTER_CLOCK_WISE);
        // assert(ccw(c, a, b) == COUNTER_CLOCK_WISE);
        // a, b, c is ccw
        
        auto calc_height = [&] (const Point &p1, const Point &p2, const Point &p3) -> double {
            Point p1p = projection(Segment{a, c}, p1);
            Point p2p = projection(Segment{a, b}, p2);
            Segment p1_ac = Segment{p1, p1 + (p1p - p1) * 1e3};
            Segment p2_ab = Segment{p2, p2 + (p2p - p2) * 1e3};
            if(not does_intersect(p1_ac, p2_ab)) return INF;
            Point p = intersection(p1_ac, p2_ab);
            if(p == p1 or p == p2 or p == p3) return INF;
            auto calc = [&] (Point aa, Point pp) {
                double l_ah = distance(aa, pp);
                double l_ap = distance(aa, p);
                if(p == aa) return l_ah;
                if(l_ah <= l_ap) return INF;
                return sqrt(l_ah * l_ah - l_ap * l_ap);
            };
            double res = calc(a, p1);
            // if(not eq(res, calc(a, p2))) return INF;
            // if(not eq(res, calc(b, p2))) return INF;
            // if(not eq(res, calc(b, p3))) return INF;
            // if(not eq(res, calc(c, p3))) return INF;
            // if(not eq(res, calc(c, p1))) return INF;
            return res;
        };        
        double ans = INF;
        repeat(x1, -100, 100 + 1) {
            repeat(y1, -100, 100 + 1) {
                Point p1 = Point(x1, y1);
                if(ccw(a, c, p1) != COUNTER_CLOCK_WISE) continue;
                double l12 = length2(a - p1);
                double l1 = sqrt(l12);
                int y2_mx = min<int>(100, a.Y() + l1 + 0.5);
                int y2_mn = max<int>(-100, a.Y() - l1 - 0.5);               
                repeat(y2, y2_mn, y2_mx + 1) {
                    double dy = abs(a.Y() - y2);
                    double dx = sqrt(l12 - dy * dy);                    
                    for(Point p2_cand : {Point{a.X() + dx, (double)y2}, Point{a.X() - dx, (double)y2}}) {
                        Point p2 = nearest_grid_point(p2_cand);
                        if(abs(p2.X()) > 100 or abs(p2.Y()) > 100) continue;

                        if(not eq(length2(a - p2), l12)) continue;
                        if(ccw(b, a, p2) != COUNTER_CLOCK_WISE) continue;

                        if(p1 == p2) continue;
                        if(ccw(b, a, p1) == COUNTER_CLOCK_WISE and ccw(p2, a, p1) != COUNTER_CLOCK_WISE) continue;
                        
                        double l2 = distance(p1, c);
                        double l3 = distance(p2, b);

                        Point p3;

                        bool ok = false;
                        for(Point p3_cand : cross_points(Circle{c, l2}, Circle{b, l3})) {
                            p3 = nearest_grid_point(p3_cand);
                            if(abs(p3.X()) > 100 or abs(p3.Y()) > 100) continue;
                            if(ccw(c, b, p3) != COUNTER_CLOCK_WISE) continue;                            
                            if(p1 == p3 or p2 == p3) continue;
                            if(ccw(c, b, p2) == COUNTER_CLOCK_WISE and ccw(p3, b, p2) != COUNTER_CLOCK_WISE) continue;
                            if(ccw(a, c, p3) == COUNTER_CLOCK_WISE and ccw(p1, c, p3) != COUNTER_CLOCK_WISE) continue;
                            
                            if(eq(distance(c, p3), l2) and eq(distance(b, p3), l3)) {
                                ok = true;
                                break;
                            }
                        }
                        if(not ok) continue;
                        // assert(not does_include({a, c}, p1));
                        // assert(not does_include({b, c}, p2));
                        // assert(not does_include({c, a}, p3));
                        // assert(eq(distance(c, p3), l2) and eq(distance(b, p3), l3));
                        // assert(eq(distance(a, p1), l1) and eq(distance(c, p1), l2));
                        // assert(eq(distance(a, p2), l1) and eq(distance(b, p2), l3));
                        set_min(ans, calc_height(p1, p2, p3));
                    }
                }
            }
        }
        printf("%.10lf\n", (ans == INF ? -1 : ans));
        return 1;
    }
};

int main() {
    while(Solver().solve());
    return 0;
}