#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPS = 1e-5;
const double INF = 1e12;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()
typedef complex<double> P;
typedef vector<P> VP;

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

double getangle(P a, P b){
    return abs(arg(a/b));
}
double getarea(const VP &poly){
    double ret = 0;
    for (int i=0; i<(int)poly.size(); i++){ 
        ret += cross(poly[i], poly[(i+1)%poly.size()]);
    }
    return ret*0.5;
}

int main(){
    int n;
    while(cin >> n){
        VP p(n);
        for(int i=0; i<n; i++){
            double x,y;
            cin >> x >> y;
            p[i] = P(x, y);
        }
        if(p[0] == p.back()){
            p.pop_back();
            n--;
        }

        bool ng = false;
        double len = abs(p[1] -p[0]);
        for(int i=0; i<n; i++){
            double a = getangle(p[i] -p[(i+1)%n], p[(i+2)%n] -p[(i+1)%n]);
            a *= 5/PI;
            double l = abs(p[(i+1)%n] -p[i]);
            if(!EQ(len, l)) len = -1;
            if(!EQ(a, round(a)) || !EQ(l, round(l))){
                ng = true;
                break;
            }
        }
        if(len != -1 && n == 5) ng = true;
        if(ng){
            cout << -1 << " " << -1 << endl;
            continue;
        }

        double area = getarea(p);
        double thin = sin(PI/5);
        double thick = sin(2*PI/5);
        int a=-1, b=-1;
        for(int i=0; thin*i < area +EPS; i++){
            double rem = area -thin*i;
            double j = rem/thick;
            if(EQ(j, round(j))){
                a = i;
                b = round(j) +EPS;
                break;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
