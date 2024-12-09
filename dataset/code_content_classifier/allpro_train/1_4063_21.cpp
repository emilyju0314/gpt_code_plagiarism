#include <bits/stdc++.h>
#define PI M_PI
#define EPS 1e-14
using namespace std;
typedef complex<double> point;
namespace std {
  bool operator < (const point& a, const point& b){
    return fabs(real(a)-real(b)) <EPS  ? imag(a) < imag(b) : real(a) < real(b);
  }
  bool operator == (const point& a,const point& b){
    return abs(real(a)-real(b))<EPS&&abs(imag(a)-imag(b))<EPS;
  }
  bool operator != (const point& a,const point& b){
    return !(abs(real(a)-real(b))<EPS&&abs(imag(a)-imag(b))<EPS);
  }
  
}
int n;
double cross(point a,point b){return a.real()*b.imag()-a.imag()*b.real();}

point rot(point a,double rad){
  return a*conj(point(cos(rad),sin(rad)));
}

point crosspoint(point a,point b,point c,point d){
  a-=d;b-=d;c-=d;
  return d+a+(b-a)*imag(a/c)/imag(a/c-b/c);
}
double getArea3(point a,point b,point c){return abs(cross(b-a,c-a)/2);}

double solve(){
  vector <point> a;
  double base=2*PI/3;
  point A=point(0,1/sqrt(3));
  a.push_back(A);
  a.push_back(rot(A,base));  
  a.push_back(rot(A,base*2));

  double rad=2*PI/n;
  for(int i=1;i<=n;i++)
    for(int j=0;j<3;j++)a.push_back(rot(a[j],rad*i));
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());
  
  double dis=1e9;
  point B;
  for(int i=0;i<a.size();i++)
    if(A!=a[i]&&real(a[i])>0&&abs(A-a[i])<dis)dis=abs(A-a[i]),B=a[i];
  point C=crosspoint(A,rot(A,base),B,rot(B,base*2));
  double s=getArea3(A,B,C);
  double S=(dis/2)*(dis/2)/tan(PI/a.size());
  return (S-s)*a.size();
}


int main(){
  while(cin>>n,n)printf("%.15f\n",solve());
  return 0;
}