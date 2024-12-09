#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <array>
#include <cassert>
using namespace std;

const double EPS = 1e-8;
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

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
}
bool intersectSP(const L& s, const P &p){
    return abs(cross(s[0]-p, s[1]-p))<EPS  && dot(s[0]-p, s[1]-p)<EPS;
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

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        VP p(n);
        for(int i=0; i<n; i++){
            double x,y;
            cin >> x >> y;
            x+=2000; y+=2000;
            p[i] = P(x, y);
        }
        vector<L> edge(n);
        for(int i=0; i<n; i++){
            edge[i] = L(p[i], p[(i+1)%n]);
        }

        const int lim = 4000;
        int ans = 0;
        for(int y=0; y<4000; y++){
            L hori[2];
            hori[0] = L(P(0, y+EPS), P(lim, y+EPS));
            hori[1] = L(P(0, y+1-EPS), P(lim, y+1-EPS));
            vector<pair<int, int> > range[2];
            for(int d=0; d<2; d++){
                vector<double> cpx;
                for(int i=0; i<n; i++){
                    if(!isParallel(hori[d], edge[i]) && intersectSS(hori[d], edge[i])){
                        P cp = crosspointLL(hori[d], edge[i]);
                        cpx.push_back(cp.X);
                    }
                }
                sort(cpx.begin(), cpx.end());
                for(int i=0; i<(int)cpx.size(); i+=2){
                    int xlow = cpx[i] +EPS;
                    int xhigh = ceil(cpx[i+1] -EPS) +EPS;
                    range[d].push_back(make_pair(xlow, xhigh));
                }
                range[d].push_back(make_pair(1e4, 1e4));
                sort(range[d].begin(), range[d].end());
            }
            
            assert(range[0].size() == range[1].size());
            for(int i=0; i<(int)range[0].size(); i++){
                range[0][i].first = min(range[0][i].first, range[1][i].first);
                range[0][i].second = max(range[0][i].second, range[1][i].second);
            }
            int low = range[0][0].first;
            int high = range[0][0].second;
            for(int i=1; i<(int)range[0].size(); i++){
                if(range[0][i].first > high){
                    ans += high -low;
                    low = range[0][i].first;
                    high = range[0][i].second;
                }
                high = max(high, range[0][i].second);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
