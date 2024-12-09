#include <iostream>
#include <complex>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef complex<double> P;
typedef pair<P,P> L;
typedef pair<P,double> C;
typedef vector<P> Poly;
#define X real()
#define Y imag()
const double EPS = (1e-10), INF = (1e15), pi = acos(-1);

//2D version
double dot(P a, P b){ return a.X * b.X + a.Y * b.Y;}
double cross(P a, P b){ return a.X * b.Y - a.Y * b.X;}

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if(cross(b,c) > EPS) return +1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < 0) return +2;
  if(abs(b) + EPS < abs(c)) return -2;
  return 0;
}

P projection(P a, P b){ return dot(a, b)/abs(b)/abs(b)*b;}

double ps_dist(P a, L s){
  if(dot(s.second-s.first,a-s.first) >= 0 && dot(s.first-s.second,a-s.second) >= 0)
    return abs(cross(s.first-s.second,a-s.second))/abs(s.first-s.second);
  return min(abs(a-s.first), abs(a-s.second));
}

double pl_dist(P a, L s){
  return abs(cross(s.first-s.second,a-s.second))/abs(s.first-s.second);
}

L cpcl(C c, L l){
  //円cと直線lの交点
  //接する場合は同一の点を二つ返す
  double d = pl_dist(c.first,l), r = c.second;
  P m = l.first + projection(c.first-l.first,l.second-l.first);
  P x = sqrt(r*r-d*d)/abs(l.second-l.first)*(l.second-l.first);
  if(dot(x,l.second-l.first) < 0) x *= -1;
  return make_pair(m-x,m+x);
}

double common_area_cp(C c, Poly p){
  //円と非凸多角形の共通面積
  double ret = 0, r = c.second;
  int n = p.size();
  for(int i = 0; i < n; ++i) p[i] -= c.first;
  for(int i = 0; i < n; ++i){
    if(abs(p[i]) < EPS || abs(p[(i+1)%n]) < EPS) continue;
    double d = arg(p[(i+1)%n]/p[i]);
    ret += r*r*d/2.0;
    if(ps_dist(P(0,0),L(p[i],p[(i+1)%n])) < r - EPS){
      L cps = cpcl(C(P(0,0),r),L(p[i],p[(i+1)%n]));
      P a, b;
      if(ccw(p[i],p[(i+1)%n],cps.first) == 0 &&
         ccw(p[i],p[(i+1)%n],cps.second) == 0)
        a = cps.first, b = cps.second;
      else if(ccw(p[i],p[(i+1)%n],cps.first) == 0)
        a = cps.first, b = p[(i+1)%n];
      else if(ccw(p[i],p[(i+1)%n],cps.second) == 0)
        a = p[i], b = cps.second;
      else
        a = p[i], b = p[(i+1)%n];
      if(abs(a) < EPS || abs(b) < EPS) continue;
      d = arg(b/a);
      ret += cross(a,b)/2.0 - r*r*d/2.0;
    }
  }
  //cout << r << " " << ret << endl;
  return ret;
}

int main(){
  int N, r;
  cin >> N >> r;
  Poly p;
  for(int i = 0; i < N; ++i){
    double x, y;
    cin >> x >> y;
    p.emplace_back(x,y);
  }
  double ans = 0;
  for(int i = 1; i <= r; ++i){
    if(i%2) ans += common_area_cp(C(P(0,0),i),p) - common_area_cp(C(P(0,0),i-1),p);
    else ans += (2*i-1)*pi - common_area_cp(C(P(0,0),i),p) + common_area_cp(C(P(0,0),i-1),p);
    //cout << common_area_cp(C(P(0,0),i),p) << endl;
  }
  printf("%.9f\n", ans);
  return 0;
}

