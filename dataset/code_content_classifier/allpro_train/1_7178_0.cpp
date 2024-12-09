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

double distanceLP(const L &l, const P &p) {
    return abs(cross(l[1]-l[0], p-l[0])) /abs(l[1]-l[0]);
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
double gettriarea(P a, P b, P c){
    return (cross(a,b) +cross(b,c) +cross(c,a))*0.5;
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

vector<L> split_to_lines(VP &p){
	int n = p.size();
    double halfarea = getarea(p)/2;
    vector<VP> cps(n);
    for(int i=0; i<n; i++){
        double currarea = 0;
        int opp;
        for(int j=2; j<n; j++){
        	double tmparea = gettriarea(p[i], p[(i+j-1)%n], p[(i+j)%n]);
        	if(currarea +tmparea > halfarea){
                opp = (i+j-1)%n;
                break;
            }
            currarea += tmparea;
        }
        double remarea = halfarea -currarea;
        double h = distanceLP(L(p[opp], p[(opp+1)%n]), p[i]);
        cps[opp].push_back(p[opp] +2*remarea/h *unit(p[(opp+1)%n] -p[opp]));
    }
    vector<L> ret;
    for(int i=0; i<n; i++){
    	cps[i].push_back(p[i]);
    	cps[i].push_back(p[(i+1)%n]);
    	sort(cps[i].begin(), cps[i].end());
    	cps[i].erase(unique(cps[i].begin(), cps[i].end()), cps[i].end());
    	if(cps[i][0] != p[i]){
    		reverse(cps[i].begin(), cps[i].end());
    	}
    	for(int j=0; j<(int)cps[i].size()-1; j++){
    		ret.emplace_back(cps[i][j], cps[i][j+1]);
    	}
    }
    return ret;
}

pair<double, double> minmax_cut(VP &p){
	vector<L> lines = split_to_lines(p);
    int n = lines.size();
    double halfarea = getarea(p)/2;
    double ansmin = INF;
    double ansmax = 0;
    for(int i=0; i<n/2; i++){
    	L s = lines[i];
    	L t = lines[(i+n/2)%n];
        ansmax = max(ansmax, max(abs(t[0]-s[0]), abs(t[1]-s[1])));
        double remarea = halfarea -getarea(convex_cut(p, L(t[0], s[1])));
        P lb = s[0];
        P ub = s[1];
        for(int r=0; r<100; r++){
        	P mid[2];
        	mid[0] = (lb+lb+ub) /3.0;
        	mid[1] = (lb+ub+ub) /3.0;
        	double len[2];
        	for(int d=0; d<2; d++){
        		double h = distanceLP(L(t[0], t[1]), mid[d]);
        		double l = 2*(remarea -gettriarea(mid[d], s[1], t[0])) /h;
        		len[d] = abs(mid[d] -(t[0] +l*unit(t[1]-t[0])));
        	}
        	if(len[0] < len[1]){
                ub = mid[1];
            }else{
            	lb = mid[0];
            }
            ansmin = min(ansmin, len[0]);
        }
    }
    return make_pair(ansmin, ansmax);
}

int main(){
    int n;
    cin >> n;
    VP p(n);
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        p[i] = P(x, y);
    }
    auto ans = minmax_cut(p);
    cout << fixed << setprecision(10);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}
