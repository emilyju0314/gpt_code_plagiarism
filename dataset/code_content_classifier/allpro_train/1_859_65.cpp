#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
#include <cstdio>
using namespace std;

typedef complex<double> P;
typedef pair<P,P> L;
const double EPS = 1e-7;
const int MAX = 30000;
int n,m;

P dat[100];
double ans[100];

double equal(double a, double b){ return fabs(a-b) < EPS;}

double dot(P a, P b){ return real(conj(a)*b);}

double cross(P a, P b){ return imag(conj(a)*b);}

double calcArea(vector<P> v){
  double sum = 0.0;
  int n = v.size();
  for(int i=0;i<n;i++) sum += (v[i].real() - v[(i+1)%n].real()) * (v[i].imag() + v[(i+1)%n].imag());
  return fabs(sum) / 2;
};

int ccw(P a, P b, P c){
  b -= a;
  c -= a;
  if(cross(b,c) > EPS) return 1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < -EPS) return 2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}

P crossPoint(L l, L m){
  double A = cross(l.second - l.first, m.second - m.first);
  double B = cross(l.second - l.first, l.second - m.first);
  if(fabs(A) < EPS && fabs(B) < EPS) return m.first;
  else if(fabs(A) >= EPS) return m.first + B / A * (m.second - m.first);
}

vector<P> convex_cut(vector<P> G, L l){
  vector<P> ans;
  for(int i=0;i<G.size();i++){
    P A = G[i];
    P B = G[(i+1)%G.size()];
    if(ccw(l.first, l.second, A) != -1) ans.push_back(A);
    if(ccw(l.first, l.second, A) * ccw(l.first, l.second, B) < 0){
      L l2(A,B);
      ans.push_back(crossPoint(l2, l));
    }
  }
  return ans;
}

P rotate(P p, double theta){
  theta *= M_PI / 180.0;
  double x = p.real() * cos(theta) - p.imag() * sin(theta);
  double y = p.real() * sin(theta) + p.imag() * cos(theta);
  return P(x,y);
}

L bisector(L l){
  P p = (l.first + l.second) / 2.0;
  return L(p, p + rotate(l.second-l.first,90));
}

void solve(vector<P> v){
  for(int i=0;i<m;i++){
    vector<P> area = v;
    for(int j=0;j<m;j++){
      if(i == j) continue;
      area = convex_cut(area, bisector(L(dat[i], dat[j])));
    }
    printf("%f\n",calcArea(area));
  }
}

int main(){
  while(cin >> n >> m && (n|m)){
    vector<P> v;
    for(int i=0;i<n;i++){
      int x,y;
      cin >> x >> y;
      v.push_back(P(x,y));
    }
    for(int i=0;i<m;i++){
      int x,y;
      cin >> x >> y;
      dat[i] = P(x,y);
    }

    solve(v);
  }
}