#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#ifdef DBG
  #define dbg 1
  #define dpf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
  #define dbg 0
  #define dpf(...) 42
#endif
 
#define SIZE(c) int((c).size())
#define REP(i,c) for(auto &i : (c))
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define eb emplace_back
typedef long long i64;
typedef unsigned long long u64;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;

// Input: a, b. Sets x, y: ax+by=GCD(a,b).
// Returns: GCD(a,b), may be negative.
// Tested:
//   https://codeforces.com/contest/1500/submission/109926787
i64 GcdExt(i64 a,i64 b,i64 &x,i64 &y) {
    if(b==0) {
        x=1;y=0;
        return a;
    }
    i64 d=GcdExt(b,a%b,x,y);
    i64 tmp=y;
    y=x-y*(a/b);
    x=tmp;
    return d;
}

// Tested:
//   https://codeforces.com/contest/1525/submission/116969426
struct ModInt {
  static constexpr int MOD= 1e9+7 ;

  int v=0;

  ModInt() {}
  ModInt(i64 x) {
    v = x % MOD;
    if (v < 0) v += MOD;
  }

  ModInt& operator+=(const ModInt& r) { v+=r.v; if(v>=MOD) v-=MOD; return *this; }
  ModInt& operator-=(const ModInt& r) { v-=r.v; if(v<0) v+=MOD; return *this; }
  ModInt& operator*=(const ModInt& r) { v=((i64)v*r.v)%MOD; return *this; }
  ModInt& operator/=(const ModInt& r) { *this*=r.Inv(); return *this; }

  friend ModInt operator+(ModInt l, const ModInt& r) { l+=r; return l; } 
  friend ModInt operator-(ModInt l, const ModInt& r) { l-=r; return l; } 
  friend ModInt operator*(ModInt l, const ModInt& r) { l*=r; return l; }
  friend ModInt operator/(ModInt l, const ModInt& r) { l/=r; return l; }

  ModInt Inv() const {
    i64 x, y;
    assert(GcdExt(v, MOD, x, y) == 1);
    return x;
  }

  ModInt Pow(int n) {
    if (!n) return 1;
    ModInt r = Pow(n >> 1);
    r *= r;
    if (n & 1) r *= v;
    return r;
  }
};

const int MAXN=1e6+5;

int n;

void Init() {
  int n;
  int sg[MAXN][2];
  n=20;
  sg[0][0]=0;sg[0][1]=0;
  sg[1][0]=1;sg[1][1]=0;
  VI nxt;
  for(int i=2;i<=n;++i) {
    for(int j=0;j<=1;++j) {
      nxt.clear();
      for(int i2=0;i2<i;++i2) {
        for(int j2=0;j2<=1;++j2) {
          if(i2==0 && j2==0) continue;
          if(i2==i-1 && j2==j) continue;
          int sg0=sg[i2][j2],sg1=sg[i-1-i2][j^j2];
          nxt.pb(sg0^sg1);
        }
      }
      sort(ALL(nxt));
      nxt.resize(unique(ALL(nxt))-nxt.begin());

      int w=0;
      REP(x, nxt) {
        if(w!=x) break;
        ++w;
      }
      sg[i][j]=w;
    }
    dpf("%d: %d %d\n",i,sg[i][0],sg[i][1]);
  }
}

void Solve() {
  scanf("%d",&n);

  vector<ModInt> f(n+1);
  f[0]=1;
  for(int i=1;i<=n;++i) f[i]=f[i-1]*i;

  --n;
  int i0 = 1 - n % 2;
  ModInt ans;
  for(int i=i0;;i+=2) {
    int d=n-i*2+1;
    if (d < 0) break;
    // C(n-i+1, i)
    ModInt u=f[n-i+1]/f[i]/f[d];
    ans += u * f[n - i];
  } 
  ans*=(n+1)*2;
  printf("%d\n",ans.v);
}

int main() {
  int t=1;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }

  return 0;
}
