#include <bits/stdc++.h>
#define int long long
#define double long double
#define N 20
using namespace std;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
const double g = 1.0;
int p[N],h[N];


double calcX(double radian,double v){
  double vix = v * cos(radian);
  double viy = v * sin(radian);
  double t = 2 * viy / g;
  return vix * t;
}

double calcV(double x,int n,int b,double radian){
  double L = 0, R = 1e10, cnt = 100;
  while(cnt--){
    double M = (L+R)/2;
    if(calcX(radian,M) > x) R = M;
    else L = M;
  }
    
  double v = L,pos = 0;
  for(int i=0;i<b;i++, pos += x){
    for(int j=0;j<n;j++){
      //if(pos == p[j] || p[j] == pos+x) return INF;
      if(!(pos <= p[j] && p[j] <= pos+x)) continue;
      double vix = v * cos(radian);
      double viy = v * sin(radian);
      double t = (p[j] - pos)/vix;
      double y = -(g*t/2 - viy) * t;
      if(y-h[j]+EPS < 0) return INF;
    }
  }
  return v;  
}

double solve(double x,int n,int b){

  double L = PI/4,R = PI/2,cnt = 100;
  while(cnt--){
    double M = (L+R)/2;
    if(calcV(x,n,b,M) < INF) R = M; 
    else L = M;
  }
  return calcV(x,n,b,R);
}


signed main(){
  int D,n,B;
  cin>>D>>n>>B;
  for(int i=0;i<n;i++) cin>>p[i]>>h[i];
  double ans = INF;
  for(int i=1;i<=B+1;i++) Min(ans,solve(1.0*D/i,n,i));
  printf("%.5Lf\n",ans);
  return 0;
}