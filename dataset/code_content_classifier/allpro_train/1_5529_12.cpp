#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

typedef double P_type; //座標(integer or real)
typedef double G_real; //実数の戻り値(float or double or long double)
typedef complex<P_type> P;
const G_real P_eps = 1e-8; //整数の時はゼロ

namespace std{
  template<class T> bool operator<(const complex<T> &a, const complex<T> &b){
    return abs(a.real() - b.real()) < P_eps ? a.imag() + P_eps < b.imag() : a.real() + P_eps < b.real();
  }
};

P rotate(P p, double theta){
  return p * P(cos(theta), sin(theta));
}

//内積
P_type dot(P a, P b) {
  return (a * conj(b)).real();
}

//外積
P_type cross(P a, P b) {
  return (conj(a) * b).imag();
}

//反時計回り
int ccw(P a, P b, P c){
  if(cross(b-a, c-a) > P_eps) return 1; //COUNTER_CLOCKWISE(center:a)
  if(cross(b-a, c-a) < -P_eps) return -1; //CLOCKWISE(center:a)
  if(dot(b-a, c-a) < -P_eps) return -2; //c -> a -> b
  if(dot(a-b, c-b) < -P_eps) return 2; //a -> b -> c
  return 0; //a -> c -> b
}

/* 線分abと点cの距離 */
G_real distanceSP(P a, P b, P c) {
  if ( dot(b-a, c-a) < P_eps ) return abs(c-a);
  if ( dot(a-b, c-b) < P_eps ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

/* 直線abと点cの距離 */
G_real distanceLP(P a, P b, P c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}

/* 円の点包含判定 */
bool isContainedCP(P c, P_type r, P p){
  return abs(c-p) < r - P_eps; //円周上を含まない
  //return abs(c-p) <= r + P_eps; //円周上を含む
}

/* 直線交差判定 */
bool isIntersectedLL(P a1, P a2, P b1, P b2){
  return abs(cross(a1-a2, b1-b2)) > P_eps;
}

/* 線分交差判定 */
bool isIntersectedSS(P a1, P a2, P b1, P b2){
  
  //線分a と 直線b
  int a = ccw(b1, b2, a1);
  int b = ccw(b1, b2, a2);
  
  //線分b と 直線a
  int c = ccw(a1, a2, b1);
  int d = ccw(a1, a2, b2);
  
  return a * b <= 0 && c * d <= 0; // T字を除く時は (** < 0)
}

/* 直線線分交差判定 */
bool isIntersectedLS(P a1, P a2, P b1, P b2){
  int a = ccw(a1, a2, b1);
  int b = ccw(a1, a2, b2);
  
  // 直線上のとき a or b = 0 or -2 or 2
  return (a % 2) * (b % 2) <= 0; // T字を除く時は (** < 0)
}

/* 円交差判定 */
bool isIntersectedCC(P c1, G_real r1, P c2, P_type r2){
  G_real dist = abs(c1 - c2);
  
  return abs(r1 - r2) <= dist + P_eps && dist - P_eps <= r1 + r2; //外接内接を含む
  //return abs(r1 - r2) < dist - P_eps && dist + P_eps < r1 + r2; //外接内接を除く
}

/* 円直線交差判定 */
bool isIntersectedCL(P c, G_real r, P a1, P a2){
  return distanceLP(a1, a2, c) <= r + P_eps; //接する場合を含まない場合 < r - P_eps
}

/* 円線分交差判定 */
bool isIntersectedCS(P c, P_type r, P a1, P a2){
  return (!isContainedCP(c, r, a1) || !isContainedCP(c, r, a2)) &&
    distanceLP(a1, a2, c) <= r + P_eps; //接する場合を含まない場合 < r - P_eps
}

/* 直線/線分交点 */
P getCrosspointLL(P a1, P a2, P b1, P b2) {
  //assert(isIntersectedLL(a1, a2, b1, b2));
  P a = a2 - a1;
  P b = b2 - b1;
  return a1 + a * cross(b, b1 - a1) / cross(b, a);
}

P getCrosspointSS(P a1, P a2, P b1, P b2){
  //assert(isIntersectedSS(a1, a2, b1, b2));
  return getCrosspointLL(a1, a2, b1, b2);
}

/* 円交点 */
pair<P,P> getCrosspointCC(P c1, P_type r1, P c2, P_type r2){
  //assert(isIntersectedCC(c1, r1, c2, r2));
  
  P_type dist = abs(c1 - c2);
  P_type a = acos((r1*r1 + dist*dist - r2*r2) / (2 * r1 * dist));
  return {c1 + polar(r1, arg(c2 - c1) + a), c1 + polar(r1, arg(c2 - c1) - a)};
}

/* 円線分交点 */
vector<P> getCrosspointCL(P c, P_type r, P a1, P a2){
  if(!isIntersectedCL(c, r, a1, a2)) return {};
  
  P base1 = a2 - a1;
  P proj = a1 + base1 * dot(c - a1, base1) / norm(base1); //射影
  P e = (a2 - a1) / abs(a2 - a1);
  P base2 = sqrt(r*r - norm(proj - c));
  return {proj - e*base2, proj + e*base2};
}

vector<P> getCrosspointCS(P c, P_type r, P a1, P a2){
  if(!isIntersectedCL(c, r, a1, a2)) return {};
  
  vector<P> res;
  for(P p : getCrosspointCL(c, r, a1, a2))
    if(dot(a1-p, a2-p) <= P_eps) res.push_back(p);
  return res;
}

/* 多角形-点包含 */
bool iscontainedPolyP(vector<P> &g, P p){
  int n = g.size();
  bool f = false;
  for(int i=0;i<n;i++){
    P a = g[i] - p, b = g[(i+1)%n] - p;
    if(abs(cross(a,b)) < P_eps && dot(a,b) < P_eps) return true; //辺上
    if(a.imag() > b.imag()) swap(a,b);
    if(a.imag() < P_eps && P_eps < b.imag() && cross(a,b) > P_eps) f = !f;
  }
  return f; //内部 or 外部
}

/* 射影(直線abとpからの垂線との交点) */
P getProject(P a, P b, P p){
  P base = b - a;
  return a + base * dot(p - a, base) / norm(base);
}

/* 反射(直線abを対称軸としたpの線対称の位置) */
P getReflection(P a, P b, P p){
  return p + (getProject(a, b, p) - p) * (P_type)2.0;
}


/* 多角形面積 */
G_real getAreaPoly(vector<P> &g){
  P_type res = 0;
  for(int i=0;i<g.size();i++)
    res += cross(g[i], g[(i+1)%g.size()]);
  return abs(res/2.0);
}


/* 円-直線(中心との三角形) 共通面積 */
G_real getAreaCS(P c, P_type r, P a1, P a2){
  if(min({abs(a1 - a2), abs(c - a1), abs(c - a2), r}) <= P_eps) return 0;
  
  G_real res = 0;
  vector<P> vec = {a1};
  for(auto p : getCrosspointCS(c, r, a1, a2)) vec.push_back(p);
  vec.push_back(a2);
  
  for(int i=0;i+1<vec.size();i++){
    P p1 = vec[i] - c, p2 = vec[i+1] - c;
    if(max(abs(p1), abs(p2)) <= r + P_eps)
      res += cross(p1, p2) / 2.0;
    else
      res += r*r*arg(conj(p1)*p2) / 2.0;
  }
  
  return res;
}

/* 円-多角形共通面積 */
G_real getAreaPolyC(vector<P> &g, P c, P_type r){
  G_real res = 0;
  for(int i=0;i<g.size();i++)
    res += getAreaCS(c, r, g[i], g[(i+1)%g.size()]);
  return abs(res);
}



int main(){
  int n, r;
  int h[310] = {};

  scanf("%d%d", &n, &r);
  
  for(int i=0;i<n;i++){
    int x, w, _h;
    cin >> x >> w >> _h;
    x += 100;
    for(int j=0;j<w;j++) h[j+x] = max(h[j+x], _h);
  }

  vector<P> vec;
  
  for(int i=0;i<=300;i++){
    vec.push_back(P(i-100, h[i]));
    vec.push_back(P(i-99,  h[i]));
  }

  vec.push_back(P(201, -300));
  vec.push_back(P(-100, -300));

  double L = 0, R = 200;

  while(R-L > 1e-7){
    double mid = (L+R)/2;

    if(getAreaPolyC(vec, P(0, mid), r) > r*r*M_PI/2.0)
      L = mid;
    else
      R = mid;
  }

  printf("%.10lf\n", L);
  
  return 0;
}



