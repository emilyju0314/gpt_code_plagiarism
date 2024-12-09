#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef complex<double> P;
typedef pair<P,P> L;
const double INF = 1e12;
const double EPS = 1e-10;
double cross(const P& a, const P& b) {return imag(conj(a)*b);}
double dot(const P& a, const P& b) {return real(conj(a)*b);}
int ccw(P a, P b, P c) {
  b-=a;c-=a;
  if(cross(b,c)>EPS)return +1;
  if(cross(b,c)<-EPS)return -1;
  if(dot(b,c)<-EPS)return +2;
  if(norm(b)<norm(c))return -2;
  return 0;
}
double D(P a, P b){return sqrt((a.real()-b.real())*(a.real()-b.real())+(a.imag()-b.imag())*(a.imag()-b.imag()));}
bool intersectSS(const L &s, const L &t){return ccw(s.F,s.S,t.F)*ccw(s.F,s.S,t.S)<=0&&ccw(t.F,t.S,s.F)*ccw(t.F,t.S,s.S)<=0;}
P projection(const L &l, const P &p){double t=dot(p-l.F,l.F-l.S)/norm(l.F-l.S);return l.F+t*(l.F-l.S);}
P reflection(const L &l, const P &p){return p+2.0*(projection(l,p)-p);}
int main() {
  P p[2];
  for(int i=0; i<2; i++) {
    double x,y;
    cin >> x >> y;
    p[i]=P(x,y);
  }
  int n;
  cin >> n;
  P a[n];
  for(int i=0; i<n; i++) {
    double x,y;
    cin >> x >> y;
    a[i]=P(x,y);
  }
  bool f=0;
  for(int i=0; i<n; i++) f|=intersectSS(L(p[0],p[1]),L(a[i],a[(i+1)%n]));
  set<int> s[2];
  for(int i=0; i<2; i++) {
    for(int j=0; j<n; j++) {
      int cnt=0;
      for(int k=0; k<n; k++) cnt+=intersectSS(L(p[i],a[j]),L(a[k],a[(k+1)%n]));
      if(cnt<=2) s[i].insert(j);
    }
  }
  double ans=INF;
  if(f) {
    for(int i=0; i<n; i++) {
      if(!s[0].count(i)) continue;
      double d=0;
      for(int k=0; k<n; k++) {
        int j=(i+k)%n;
        if(s[1].count(j)) ans=min(ans,D(p[0],a[i])+d+D(a[j],p[1]));
        d+=D(a[j],a[(j+1)%n]);
      }
      d=0;
      for(int k=0; k<n; k++) {
        int j=(i-k+n)%n;
        if(s[1].count(j)) ans=min(ans,D(p[0],a[i])+d+D(a[j],p[1]));
        d+=D(a[j],a[(j-1+n)%n]);
      }
    }
  } else {
    for(int i=0; i<n; i++) {
      P q=reflection(L(a[i],a[(i+1)%n]),p[1]);
      if(intersectSS(L(a[i],a[(i+1)%n]),L(p[0],q))) ans=min(ans,D(p[0],q));
      ans=min(ans,D(p[0],a[i])+D(a[i],p[1]));
    }
  }
  printf("%.10f\n",ans);
  return 0;
}
