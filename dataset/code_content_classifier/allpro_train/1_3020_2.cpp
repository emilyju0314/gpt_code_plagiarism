#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <complex>
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

double cross(P a, P b){
    return (conj(a)*b).Y;
}
P rotate(const P &p, double rad){
    return p *P(cos(rad), sin(rad));
}

P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
}
double getarea(const VP &poly){
    double ret = 0;
    for (int i=0; i<(int)poly.size(); i++){ 
        ret += cross(poly[i], poly[(i+1)%poly.size()]);
    }
    return ret*0.5;
}

int main(){
    int n,k;
    cin >> n >> k;
    VP v(n);
    for(int i=0; i<n; i++){
        v[i] = rotate(P(0, 1), 2*PI *i/n);
    }
    VP star;
    for(int i=0; i<n; i++){
        star.push_back(v[i]);
        if(k >= 2){
            star.push_back(crosspointLL(L(v[i], v[(i+k)%n]), L(v[(i+1)%n], v[(i+1-k+n)%n])));
        }
    }
    cout << fixed << setprecision(10);
    cout << getarea(star) << endl;
    return 0;
}

