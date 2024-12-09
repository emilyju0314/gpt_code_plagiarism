#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;

const double EPS = 1e-10;
const double INF = 1e12;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> VP;
struct L : array<P, 2>{
    L(const P& a, const P& b){ at(0)=a; at(1)=b; }
    L(){}
};
struct C{
    P p;
    double r;
    C(const P& p, const double& r) : p(p), r(r) {}
    C(){}
};

namespace std{
    bool operator < (const P& a, const P& b){
        return (a.X!=b.X) ? a.X<b.X : a.Y<b.Y;
    }
    bool operator == (const P& a, const P& b){
        return abs(a-b) < EPS;
    }
}

double dot(P a, P b){
    return (conj(a)*b).X;
}
double cross(P a, P b){
    return (conj(a)*b).Y;
}
int ccw(P a, P b, P c){
    b -= a;
    c -= a;
    if(cross(b,c) > EPS) return +1; //ccw
    if(cross(b,c) < -EPS) return -1; //cw
    if(dot(b,c) < -EPS) return +2; //c-a-b
    if(abs(c)-abs(b) > EPS) return -2; //a-b-c
    return 0; //a-c-b
}
P unit(const P &p){
    return p/abs(p);
}
P rotate(const P &p, double rad){
    return p *P(cos(rad), sin(rad));
}

bool intersectSP(const L& s, const P &p){
    return abs(cross(s[0]-p, s[1]-p))<EPS  && dot(s[0]-p, s[1]-p)<EPS;
}
bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
}
P projection(const L& l, const P& p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0]-p), abs(s[1]-p));
}

bool isParallel(const P &a, const P &b){
    return abs(cross(a,b)) < EPS;
}
bool isParallel(const L &a, const L &b){
    return isParallel(a[1]-a[0], b[1]-b[0]);
}
P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
}

VP crosspointCL(const C &c, const L &l){
    VP ret;
    P mid = projection(l, c.p);
    double d = distanceLP(l, c.p);
    if(EQ(d, c.r)){
        ret.push_back(mid);
    }else if(d < c.r){
        double len = sqrt(c.r*c.r -d*d);
        ret.push_back(mid +len*unit(l[1]-l[0]));
        ret.push_back(mid -len*unit(l[1]-l[0]));
    }
    return ret;
}
VP crosspointCS(const C &c, const L &s){
    VP ret;
    VP cp = crosspointCL(c,s);
    for(int i=0; i<(int)cp.size(); i++){
        if(intersectSP(s, cp[i])){
            ret.push_back(cp[i]);
        }
    }
    return ret;
}

int in_poly(const P &p, const VP &poly){
    int n = poly.size();
    int ret = -1;
    for(int i=0; i<n; i++){
        P a = poly[i]-p;
        P b = poly[(i+1)%n]-p;
        if(a.Y > b.Y) swap(a,b);
        if(intersectSP(L(a,b), P(0,0))) return 0;
        if(a.Y<=0 && b.Y>0 && cross(a,b)<0) ret = -ret;
    }
    return ret;
}

VP convex(VP v){
    VP ret;
    int n = v.size();
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        while((int)ret.size()>1 && cross(ret.back()-ret[ret.size()-2], v[i]-ret.back()) < EPS){
            ret.pop_back();
        }
        ret.push_back(v[i]);
    }
    int t = ret.size();
    for(int i=n-2; i>=0; i--){
        while((int)ret.size()>t && cross(ret.back()-ret[ret.size()-2], v[i]-ret.back()) < EPS){
            ret.pop_back();
        }
        ret.push_back(v[i]);
    }
    if((int)ret.size() > 1) ret.pop_back();
    return ret;
}

double commonarea_circle_convex(C c, VP poly){
    int n = poly.size();
    for(int i=0; i<n; i++) poly[i] -= c.p;
    c.p = P(0, 0);
    
    VP cp;
    for(int i=0; i<n; i++){
        L edge(poly[i], poly[(i+1)%n]);
        VP ret = crosspointCS(c, edge);
        cp.insert(cp.begin(), ret.begin(), ret.end());
        if(abs(poly[i]) < c.r) cp.push_back(poly[i]);
    }
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    
    double res = 0;
    VP v = convex(cp);
    int m = v.size();
    for(int i=0; i<m; i++){
        P curr = v[i];
        P next = v[(i+1)%m];
        if(EQ(abs(curr), c.r) && EQ(abs(next), c.r)
           && in_poly(c.r *unit(next -curr)*P(0,-1), poly) > 0){
            double theta = arg(next /curr);
            if(theta < 0) theta += 2*PI;
            res += c.r*c.r *theta /2;
        }else{
            res += cross(curr, next) /2;
        }
    }
    return res;
}


int main(){
    int n,r;
    cin >> n >> r;
    VP poly(n);
    int xmax=0, xmin=100;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        poly[i] = P(x, y);
        xmax = max(xmax, x);
        xmin = min(xmin, x);
    }

    double ans = 0;
    double lb=xmin, ub=xmax;
    for(int rep=0; rep<50; rep++){
        double mid[2] = {(2*lb +ub)/3, (lb +2*ub)/3};
        double area[2];
        for(int i=0; i<2; i++){
            vector<double> bound;
            double x = mid[i];
            L div(P(x, -INF), P(x, INF));
            for(int j=0; j<n; j++){
                L edge(poly[j], poly[(j+1)%n]);
                if(!isParallel(div, edge) && intersectSS(div, edge)){
                    bound.push_back(crosspointLL(div, edge).Y);
                }
            }
            sort(bound.begin(), bound.end());
            double lb = bound[0], ub = bound.back();
            for(int rep=0; rep<50; rep++){
                double mid[2] = {(2*lb +ub)/3, (lb +2*ub)/3};
                double area[2];
                for(int i=0; i<2; i++){
                    area[i] = commonarea_circle_convex(C(P(x, mid[i]), r), poly);
                }
                if(area[0] > area[1]){
                    ub = mid[1];
                }else{
                    lb = mid[0];
                }
            }
            area[i] = commonarea_circle_convex(C(P(x, lb), r), poly);
            ans = max(ans, area[i]);
        }
        if(area[0] > area[1]){
            ub = mid[1];
        }else{
            lb = mid[0];
        }
    }
    cout << fixed;
    cout << setprecision(10);
    cout << ans << endl;
    return 0;
}

