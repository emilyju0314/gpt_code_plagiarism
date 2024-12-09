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
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> VP;
struct L : array<P, 2>{
    L(const P& a, const P& b){ at(0)=a; at(1)=b; }
    L(){}
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

P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
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

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        VP p(n);
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            p[i] = P(x,y);
        }

        VP con{P(0,0), P(1e4,0), P(1e4,1e4), P(0,1e4)};
        for(int i=0; i<n; i++){
            con = convex_cut(con, L(p[i], p[(i+1)%n]));
        }
        cout << !con.empty() << endl;
    }
    return 0;
}

