#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <complex>
#include <set>
using namespace std;

using W = double;
using P = complex<W>;
using L = pair<P,P>;
using C = pair<P,W>;
using Poly = vector<P>;
#define X real()
#define Y imag()
const W EPS = (1e-10), pi = acos(-1);

namespace std{
  bool operator < (const P& a, const P& b){
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
  bool cmp_y(const P &a, const P &b){
    return a.Y != b.Y ? a.Y < b.Y : a.X < b.X;
  }
  bool operator == (const P& a, const P& b){
    return abs(a-b) < EPS;
  }
}

double dot(P a, P b){ return a.X * b.X + a.Y * b.Y;}
W cross(P a, P b){ return a.X * b.Y - a.Y * b.X;}

Poly convex_hull(Poly v){
  int n = v.size(), k = 0;
  sort(v.begin(), v.end(), cmp_y);
  Poly r(2*n);
  for(int i = 0; i < n; i++){
    while(k>1 && cross(r[k-1]-r[k-2],v[i]-r[k-2]) < -EPS) k--;
    r[k++] = v[i];
  }
  for(int i = n-2, t = k; i >= 0; i--){
    while(k>t && cross(r[k-1]-r[k-2],v[i]-r[k-2]) < -EPS) k--;
    r[k++] = v[i];
  }
  r.resize(k-1);
  return r;
}

int main(){
  int N;
  cin >> N;
  int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
  set<P> s;

  vector<P> sq = {{0,0},{1,0},{1,1},{0,1}};
  vector<vector<P>> D(N);
  D[0] = sq;
  for(int i = 1; i < N; ++i){
    int n, d;
    cin >> n >> d;
    vector<P> t = D[n];
    for(auto& p : t)
      p = p+P(dx[d],dy[d]);
    D[i] = t;
  }
  for(int i = 0; i < N; ++i){
    for(auto p : D[i])
      s.insert(p);
  }

  vector<P> ps;
  for(auto p : s)
    ps.push_back(p);
  vector<P> c = convex_hull(ps);

  // for(auto p : c)
  //   fprintf(stderr,"%lld %lld\n",p.X,p.Y);
  
  int v = c.size();
  int l = 0, r = 0, b = 0;
  P d = c[1] - c[0];
  P n(-d.Y,d.X);
  while(dot(d,c[(l+1)%v]-c[0]) >= dot(d,c[l]-c[0])){
    ++l;
    l %= v;
  }
  while(dot(d,c[(r+v-1)%v]-c[0]) <= dot(d,c[r]-c[0])){
    r = (r+v-1)%v;
  }
  while(dot(n,c[(b+1)%v]-c[0]) >= dot(n,c[b]-c[0])){
    b += 1;
    b %= v;
  }
  double ans = 1e18;
  for(int i = 0; i < v; ++i){
    d = c[(i+1)%v] - c[i];
    n = {-d.Y,d.X};
    while(dot(d,c[(l+1)%v]-c[i]) >= dot(d,c[l]-c[i])){
      ++l;
      l %= v;
    }
    while(dot(d,c[(r+1)%v]-c[i]) <= dot(d,c[r]-c[i])){
      ++r;
      r %= v;
    }
    while(dot(n,c[(b+1)%v]-c[i]) >= dot(n,c[b]-c[i])){
      ++b;
      b %= v;
    }
    // fprintf(stderr,"--------------------\n");
    // fprintf(stderr,"top    : (%lld,%lld) - (%lld,%lld)\n",c[(i+1)%v].X,c[(i+1)%v].Y,c[i].X,c[i].Y);
    // fprintf(stderr,"left   : (%lld,%lld)\n",c[l].X,c[l].Y);
    // fprintf(stderr,"bottom : (%lld,%lld)\n",c[b].X,c[b].Y);
    // fprintf(stderr,"right  : (%lld,%lld)\n",c[r].X,c[r].Y);
    // fprintf(stderr,"area   : %lld\n",dot(n,c[b]-c[i])*(dot(d,c[l]-c[i])-dot(d,c[r]-c[i]))/norm(d));
    // fprintf(stderr,"--------------------\n");
    ans = min(ans,dot(n,c[b]-c[i])*(dot(d,c[l]-c[i])-dot(d,c[r]-c[i]))/norm(d));
  }
  printf("%.12f\n",ans);
}

