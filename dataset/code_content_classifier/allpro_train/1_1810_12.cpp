#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

typedef double Real;

double const EPS = 1e-9;

bool eq(Real a, Real b) {
  return abs(a - b) < EPS;
}

struct p3 {
  Real x, y, z;
  p3 operator + (p3 const& r) const { return p3{x + r.x, y + r.y, z + r.z}; }
  p3 operator - (p3 const& r) const { return p3{x - r.x, y - r.y, z - r.z}; }
  p3 operator * (Real k) const { return p3{k * x, k * y, k * z}; }
  bool operator == (p3 const& r) const { return eq(x, r.x) && eq(y, r.y) && eq(z, r.z); }
};

struct circle {
  p3 p; Real r;
};

struct light_source {
  p3 p; Real brt;
};

typedef vector<p3> line;
typedef line segment;

Real sq(Real x) {
  return x * x;
}

Real dot(p3 a, p3 b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Real norm(p3 p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

Real abs(p3 p) {
  return sqrt(norm(p));
}

p3 project(line const& l, p3 const& p) {
  Real t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + (l[0] - l[1]) * t;
}

bool intersect_sp(segment const& s, p3 const& p) {
  return eq(abs(s[1] - s[0]), abs(s[0] - p) + abs(s[1] - p));
}

Real distance_sp(segment const& s, p3 const& p) {
  p3 r = project(s, p);
  if(intersect_sp(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

bool intersect_cs(circle const& c, segment const& s) {
  return distance_sp(s, c.p) < c.r && (abs(s[0] - c.p) > c.r || abs(s[1] - c.p) > c.r);
}

int N, M, R;
vector<circle> bs;
vector<light_source> ls;
p3 target;
bitset<2000> isect[15];

void precalc() {
  rep(i, 15) isect[i].reset();
  rep(i, M) {
    rep(j, N) {
      if(intersect_cs(bs[j], segment{ls[i].p, target})) {
        isect[i].set(j);
      }
    }
  }
}

Real solve() {
  Real ret{};

  rep(S, 1<<M) {
    Real sum{};
    bitset<2000> bit;
    rep(i, M) {
      if(!(S >> i & 1)) continue;
      auto& lg = ls[i];
      // Tjb / { (Tjx テ「ツ按?Ex)2 + (Tjy テ「ツ按?Ey)2 + (Tjz テ「ツ按?Ez)2 },
      sum += lg.brt / ( sq( lg.p.x - target.x ) + sq( lg.p.y - target.y ) + sq( lg.p.z - target.z ) );
      bit |= isect[i];
    }

    if(bit.count() <= R) {
      maximize(ret, sum);
    }
  }

  return ret;
}

int main() {

  // テァツ崢ョテヲツィツ凖」ツ?ィテ・ツ?嘉ヲツコツ静」ツ?ィテ」ツつ津ァツケツ凝」ツ?静ァツキツ堙・ツ按?」ツ?ョテゥツ鳴禿」ツ?ォテ、ツコツ、テ・ツキツョテ」ツ?凖」ツつ凝」ツδ静」ツδォテ」ツδシテ」ツδウテ」ツ?ョテヲツ閉ーテ」ツ?軍テ、ツサツ・テ、ツクツ凝」ツ?ァテ」ツ?づ」ツつ凝」ツつ暗」ツ??」ツ?ェテ」ツ??・ツ?嘉ヲツコツ静」ツ?ョテゥツ崢?・ツ青暗」ツつ津・ツ?ィテヲツ篠「テァツエツ「テ」ツ?凖」ツつ凝」ツ??
  // テヲツ敖。テ、ツサツカテ」ツつ津ヲツコツ?」ツ?淌」ツ?凖・ツ?嘉ヲツコツ静」ツ?ョテゥツ崢?・ツ青暗」ツ?ォテ」ツ?、テ」ツ??」ツ?ヲテ」ツ??・ツセツ療」ツつ嘉」ツつ古」ツつ凝・ツセツ療ァツつケテ」ツつ津ヲツ慊?・ツ、ツァテ・ツ個姪」ツ?凖」ツつ凝」ツ??

  while(cin >> N >> M >> R && N) {

    bs.clear();

    rep(i, N) {
      Real x, y, z, r; cin >> x >> y >> z >> r;
      bs.push_back(circle{p3{x, y, z}, r});
    }

    ls.clear();

    rep(i, M) {
      Real x, y, z, b; cin >> x >> y >> z >> b;
      ls.push_back(light_source{p3{x, y, z}, b});
    }

    cin >> target.x >> target.y >> target.z;

    precalc();
    printf("%.15f\n", solve());

  }

  return 0;
}