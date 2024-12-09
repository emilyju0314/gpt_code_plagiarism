#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <complex>
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
P rotate(const P &p, double rad){
    return p *P(cos(rad), sin(rad));
}

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
}
P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
}
bool isParallel(const P &a, const P &b){
    return abs(cross(a,b)) < EPS;
}
bool isParallel(const L &a, const L &b){
    return isParallel(a[1]-a[0], b[1]-b[0]);
}

//(0,0)-center
bool in_convex(const P &p, const VP &poly){
	int n = poly.size();
	int a = 0, b = n;
	while(a+1 < b){
		int c = (a + b)/2;
		if(cross(poly[a], poly[c]) > 0){
			if(cross(poly[a], p)>0 && cross(poly[c], p)<0) b = c;
			else a = c;
		}else{
			if(cross(poly[a], p)<0 && cross(poly[c], p)>0) a = c;
			else b = c;
		}
	}
	b %= n;
	if(cross(poly[b] -poly[a], p -poly[a]) > -EPS) return true;
	return false;
}

VP makeMagicCircle(int m, int k){
	VP v(m);
	for(int i=0; i<m; i++){
		v[i] = rotate(P(0, 1), 2*PI *i/m);
	}
	VP ret;
	for(int i=0; i<m; i++){
		ret.push_back(v[i]);
		if(k >= 2){
			ret.push_back(crosspointLL(L(v[i], v[(i+k)%m]), L(v[(i+1)%m], v[(i+1-k+m)%m])));
		}
	}
	return ret;
}
bool canEnclose(int pidx, int eidx, double scale, const VP &v, const VP &poly){
	int n = v.size();
	int m = poly.size();
	L edge(-scale *poly[eidx] +v[pidx], -scale *poly[(eidx+1)%m] +v[pidx]);
	for(int pidx2=0; pidx2<n; pidx2++){
		VP cand;
		for(int i=0; i<m; i++){
			L e(-scale *poly[i] +v[pidx2], -scale *poly[(i+1)%m] +v[pidx2]);
			if(!isParallel(e, edge) && intersectSS(e, edge)){
				cand.push_back(crosspointLL(e, edge));
			}
		}
		
		for(int i=0; i<(int)cand.size(); i++){
			VP mc = poly;
			for(int j=0; j<m; j++){
				mc[j] = scale *poly[j];
			}
			bool enclose = true;
			for(int j=0; j<n; j++){
				if(!in_convex(v[j]-cand[i], mc)){
					enclose = false;
					break;
				}
			}
			if(enclose) return true;
		}
	}
	return false;
}
double solve(int m, int k, const VP &v){
	double ret = 2000;
	VP poly = makeMagicCircle(m, k);
	for(int i=0; i<(int)v.size(); i++){
		for(int j=0; j<(int)poly.size(); j++){
			if(canEnclose(i, j, ret, v, poly)){
				double lb = 0, ub = ret;
				while(ub-lb > 1e-6){
					double mid = (lb + ub)/2;
					if(canEnclose(i, j, mid, v, poly)){
						ub = mid;
					}else{
						lb = mid;
					}
				}
				ret = (lb + ub)/2;
			}
		}
	}
	return ret;
}

int main(){
	cout << fixed;
	cout << setprecision(10);
	while(1){
		int n,m,k;
		cin >> n >> m >> k;
		if(n==0) break;
		
		VP v(n);
		for(int i=0; i<n; i++){
			int x,y;
			cin >> x >> y;
			v[i] = P(x, y);
		}
		cout << solve(m, k, v) << endl;
	}
	return 0;
}
