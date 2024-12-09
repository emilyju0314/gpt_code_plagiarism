#include <cstdio>
#include <vector>
#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

using P = complex<double>;

double cross(const P& a, const P& b){
  return a.real()*b.imag() - a.imag()*b.real();
}

double area(const vector<P>& pol){
  int n = pol.size();
  double ret = 0;
  for(int i = 0; i < n; ++i){
    ret += cross(pol[i],pol[(i+1)%n]);
  }
  ret *= 0.5;
  return ret;
}

int main(){
  int n;
  cin >> n;
  vector<P> star = {P(-10.00, -6.48),
                    P(-10.79, -8.91),
                    P(-13.34, -8.91),
                    P(-11.28, -10.41),
                    P(-12.07, -12.84),
                    P(-10.00, -11.34),
                    P(-7.93, -12.84),
                    P(-8.72, -10.41),
                    P(-6.66, -8.91),
                    P(-9.21, -8.91)};
  // for(auto p : star)
  //   cerr << p << endl;

  double r = sqrt(area(star));
  // cerr << r << endl;
  P g(0,0);
  for(auto& p : star){
    p /= r;
    g += p;
  }
  g /= 10;
  for(auto& p : star)
    p -= g;
  double Xmin = -5e3, Ymin = -5e3;
  for(int i = 0; i < n; ++i){
    P c(Xmin + 500 + (i/10)*1e3, Ymin + 500 + (i%10)*1e3);
    double a;
    cin >> a;
    a += 1e-2;
    double rr = sqrt(a);
    vector<P> star_ = star;
    for(auto& p : star_){
      p *= rr;
      p += c;
    }
    printf("%d\n",i+1);
    // printf("%.9f %.9f\n",c.real(),c.imag());
    for(auto p : star_)
      printf("%.9lf %9lf\n",p.real(),p.imag());
  }
}

