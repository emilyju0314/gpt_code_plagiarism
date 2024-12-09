#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define INF 0x7FFFFFFF
const double EPS = 1e-10;


inline bool eq(double a, double b) { return fabs(b - a) < EPS;}

struct p_t{
  double x;
  double y;
  double norm() { return x * x + y * y; }
  double abs() { return sqrt(norm()); }
};
struct l_t{
	p_t a, b;
};

double cross(p_t p,p_t q);
p_t line(p_t p,p_t q);

bool asc(p_t left,p_t right) {
    return left.x == right.x ? left.y < right.y : left.x < right.x;
}
p_t Crosspoint(l_t l,l_t m);

int main(){
  int n;
  p_t z;
  vector<p_t> a;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>z.x>>z.y;
    a.push_back(z);
  }
  int q;
  cin>>q;
  p_t u,v;
  for(int t=0;t<q;t++){
    double ans=0;
    cin>>v.x>>v.y>>u.x>>u.y;
    // if(u.y>v.y){
    //   z=u;
    //   u=v;
    //   v=z;
    // }
    int c,d;
    int f=0;
    for(c=0;c<2*n;c++){
      if(cross(line(u,v),line(a[c%n],v))<0){
        f=1;
      }
      else if(f==1) break;
    }
    f=0;
    for(d=0;d<2*n;d++){
      if(cross(line(u,v),line(a[d%n],v))>=0){
        f=1;
      }
      else if(f==1) break;
    }
    if(d==2*n&&f==0){
      cout<< fixed <<ans<<endl;
      continue;
    }
    if(d==2*n&&f==1){
      for(int i=0;i<(int)a.size();i++){
        ans+=cross(a[i],a[(i+1)%a.size()]);
      }
      ans/=2.0;
      if(ans<0){
        ans=-ans;
      }
      cout<< fixed <<ans<<endl;
      continue;
    }
    l_t uc,ud,uv;
    uc.a=a[(c-1)%n];
    uc.b=a[c%n];
    ud.a=a[(d-1)%n];
    ud.b=a[d%n];
    uv.a=u;
    uv.b=v;
    vector<p_t> b;
    b.push_back(Crosspoint(uc,uv));
    d%=n;
    for(int i=c%n;i<(c%n<d?d:d+n);i++){
      b.push_back(a[i%n]);
    }
    b.push_back(Crosspoint(ud,uv));
    for(int i=0;i<(int)b.size();i++){
      ans+=cross(b[i],b[(i+1)%b.size()]);
    }
    ans/=2.0;
    if(ans<0){
      ans=-ans;
    }
    cout<< fixed <<ans<<endl;
  }
}


p_t line(p_t p,p_t q){
  p_t z;
  z.x=q.x-p.x;
  z.y=q.y-p.y;
  return z;
}


double cross(p_t p,p_t q){
  return p.x*q.y-p.y*q.x;
}

p_t Crosspoint(l_t l,l_t m){
  p_t aa,bb,cc,dd,ee;
  aa.x=l.b.x-l.a.x;
  aa.y=l.b.y-l.a.y;
  bb.x=m.b.x-m.a.x;
  bb.y=m.b.y-m.a.y;
  cc=aa;
  dd.x=l.b.x-m.a.x;
  dd.y=l.b.y-m.a.y;
	double A = cross(aa,bb);
	double B = cross(cc,dd);
	if (abs(A) < EPS && abs(B) < EPS) return m.a;
  ee.x=m.a.x+(m.b.x-m.a.x)*B/A;
  ee.y=m.a.y+(m.b.y-m.a.y)*B/A;
	return ee;
}

