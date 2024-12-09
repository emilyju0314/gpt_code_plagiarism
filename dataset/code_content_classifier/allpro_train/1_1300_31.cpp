#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

#define REP(i,n) for(int i=0; i<(int)(n); i++)

#define f first
#define s second
#define mp make_pair

using namespace std;

typedef pair<pair<double,double>,double> data;

template<class T> inline T dbl(T a){ return a * a; }

inline double dist(const data &a, const data &b){
  return sqrt(dbl(a.f.f - b.f.f) + dbl(a.f.s - b.f.s)) - (a.s + b.s);
}


int main(){
  int n;
  while(scanf("%d",&n), n){
    vector<data> v(n);

    REP(i,n)
      scanf("%lf%lf%lf", &v[i].s, &v[i].f.f, &v[i].f.s);

    double a1 = 0.0; REP(i,n) a1 += v[i].f.f; a1 /= n;
    double a2 = 0.0; REP(i,n) a2 += v[i].f.s; a2 /= n;

    double b1 = 0.0; REP(i,n) b1 += dbl(v[i].f.f - a1); b1 /= n;
    double b2 = 0.0; REP(i,n) b2 += dbl(v[i].f.s - a2); b2 /= n;

    if(b1 < b2) REP(i,n) swap(v[i].f.f, v[i].f.s);

    sort(v.begin(), v.end());

    double ans = 1e20;

    double r  = 0.0; REP(i,n) r = max(r, v[i].s); r *= 2;


    for(int i = 0; i < n; i++){
      double x1 = v[i].f.f;
      for(int j = i + 1; j < n; j++){
	double x2 = v[j].f.f;

	if((x2 - x1 - r) > ans) break;

	ans = min(ans, dist(v[i], v[j]));
      }
    }
    
    printf("%.6f\n", ans);
  }
  return 0;
}