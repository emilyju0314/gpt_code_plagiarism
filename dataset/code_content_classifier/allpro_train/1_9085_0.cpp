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

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
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

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<VP> rect(n, VP(4));
        vector<C> circle(2*n);
        for(int i=0; i<n; i++){
            double xs,ys,xt,yt,r;
            cin >> xs >> ys >> xt >> yt >> r;
            P s(xs, ys), t(xt, yt);
            P cn = unit(t -s) *r *P(0, 1);
            rect[i][0] = t +cn;
            rect[i][1] = s +cn;
            rect[i][2] = s -cn;
            rect[i][3] = t -cn;
            circle[2*i +0] = C(s, r);
            circle[2*i +1] = C(t, r);
        }

        double lbx=-5, ubx=5;
        double lby=-5, uby=5;
        int splitnum = 1e3;
        double dx = (ubx -lbx) /splitnum;
        double ans = 0;
        for(int i=0; i<splitnum; i++){
            double x = lbx +(i+0.5)*dx;
            L seg(P(x, lby), P(x, uby));
            VP cp{seg[0], seg[1]};
            for(int j=0; j<n; j++){
                for(int k=0; k<4; k++){
                    L edge(rect[j][k], rect[j][(k+1)%4]);
                    if(!isParallel(seg, edge) && intersectSS(seg, edge)){
                        cp.push_back(crosspointLL(seg, edge));
                    }
                }
            }
            for(int j=0; j<2*n; j++){
                VP ret = crosspointCS(circle[j], seg);
                cp.insert(cp.end(), ret.begin(), ret.end());
            }
            sort(cp.begin(), cp.end());
            cp.erase(unique(cp.begin(), cp.end()), cp.end());
            double len = 0;
            for(int j=0; j<(int)cp.size()-1; j++){
                P mid = (cp[j] +cp[j+1]) /2.0;
                bool in = false;
                for(int k=0; k<n && !in; k++){
                    if(in_poly(mid, rect[k]) > 0){
                        in = true;
                    }
                }
                for(int k=0; k<2*n && !in; k++){
                    if(abs(mid -circle[k].p) < circle[k].r){
                        in = true;
                    }
                }
                if(in){
                    len += abs(cp[j+1] -cp[j]);
                }
            }
            ans += dx*len;
        }
        cout << fixed << setprecision(5);
        cout << ans << endl;
    }
    return 0;
}

