#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;
const double EPS = 1e-8;
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
        return !EQ(a.X,b.X) ? a.X<b.X : a.Y+EPS<b.Y;
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

P projection(const L& l, const P& p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}
double distanceLP(const L &l, const P &p) {
    return abs(cross(l[1]-l[0], p-l[0])) /abs(l[1]-l[0]);
}
double distanceSP(const L &s, const P &p) {
    if(dot(s[1]-s[0], p-s[0]) < EPS) return abs(p-s[0]);
    if(dot(s[0]-s[1], p-s[1]) < EPS) return abs(p-s[1]);
    return distanceLP(s, p);
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
VP convex_cut(const VP& p, const L& l){
    VP ret;
    int n = p.size();
    for(int i=0; i<n; i++){
        P curr = p[i];
        P next = p[(i+1)%n];
        if(ccw(l[0], l[1], curr) != -1) ret.push_back(curr);
        if(ccw(l[0], l[1], curr) *ccw(l[0], l[1], next) == -1){
            ret.push_back(crosspointLL(L(curr, next), l));
        }
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

    double mindist = INF;
    VP cp;
    for(int i=0; i<n; i++){
        L edge(poly[i], poly[(i+1)%n]);
        VP ret = crosspointCS(c, edge);
        cp.insert(cp.begin(), ret.begin(), ret.end());
        if(abs(poly[i]) < c.r) cp.push_back(poly[i]);
        mindist = min(mindist, distanceSP(edge, c.p));
    }
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    if(mindist +EPS > c.r && in_poly(c.p, poly) > 0){
        return PI *c.r *c.r;
    }

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
    int dn;
    cin >> dn;
    for(int rep=0; rep<dn; rep++){
        double r,l;
        int n;
        cin >> r >> l >> n;
        VP poly{P(-r-1, -r-1), P(r+1, -r-1), P(r+1, r+1), P(-r-1, r+1)};
        C circle(P(0, 0), r);
        double rem = r*r*PI;
        for(int i=0; i<n; i++){
            double theta, v;
            cin >> theta >> v;
            theta *= PI/180;
            v /= l;
            P base = rotate(P(1, 0), theta);
            P dir = base *P(0, 1);
            double lb=-r, ub=r;
            for(int j=0; j<50; j++){
                double mid = (lb +ub)/2;
                L cut(mid*base, mid*base +dir);
                VP tmp = convex_cut(poly, cut);
                if(rem -commonarea_circle_convex(circle, tmp) > v){
                    lb = mid;
                }else{
                    ub = mid;
                }
            }
            L cut(lb*base, lb*base +dir);
            poly = convex_cut(poly, cut);
            rem = commonarea_circle_convex(circle, poly);
        }

        vector<double> angle;
        vector<VP> cp(poly.size());
        for(int i=0; i<(int)poly.size(); i++){
            L edge(poly[i], poly[(i+1)%poly.size()]);
            VP ret = crosspointCS(circle, edge);
            for(P p: ret){
                angle.push_back(arg(p));
                cp[i].push_back(p);
            }
            cp[i].push_back(poly[i]);
            cp[i].push_back(poly[(i+1)%poly.size()]);
            sort(cp[i].begin(), cp[i].end());
        }
        if(!angle.empty()){
            sort(angle.begin(), angle.end());
            angle.push_back(angle[0] +2*PI);
        }

        double lenstraight=0, lencurve=0;
        for(int i=0; i<(int)cp.size(); i++){
            for(int j=0; j<(int)cp[i].size()-1; j++){
                P mp = (cp[i][j] +cp[i][j+1])/2.0;
                if(abs(mp) < r){
                    lenstraight += abs(cp[i][j+1] -cp[i][j]);
                }
            }
        }
        for(int i=0; i<(int)angle.size()-1; i++){
            double mid = (angle[i] +angle[i+1])/2;
            P mp = rotate(P(r, 0), mid);
            if(in_poly(mp, poly) == 1){
                lencurve += (angle[i+1] -angle[i]) *r;
            }
        }
        cout << fixed << setprecision(10);
        cout << lenstraight << " " << lencurve << endl;
    }
    return 0;
}
