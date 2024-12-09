#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

int add(int a, int b) {
  int c = a + b;
  if (c < 0) c += M;
  if (c >= M) c -= M;
  return c;
}

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n /= 2;
    } else {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

int inv(int x) {
  return pw(x, M - 2);
}

typedef vector <int> poly;

struct ans {
  poly p, q;
  int c;
  ans() {
    p.clear(), q.clear();
    c = 0;
  }
  ans(poly p, poly q, int c): p(p), q(q), c(c) {
  }
};

poly integrate(poly p) {
  poly q(p.size() + 1);
  for (int i = 0; i < (int) p.size(); i++) {
    q[i + 1] = add(q[i + 1], mul(p[i], inv(i + 1)));
  }
  return q;
}

poly operator + (poly a, poly b) {
  poly c(max(a.size(), b.size()));
  for (int i = 0; i < (int) a.size(); i++) {
    c[i] = add(c[i], a[i]);
  }
  for (int i = 0; i < (int) b.size(); i++) {
    c[i] = add(c[i], b[i]);
  }
  return c;
}

ans operator + (ans a, ans b) {
  return {a.p + b.p, a.q + b.q, add(a.c, b.c)};
}

ans set_one(ans t) {
  int a = 0;
  for (int x : t.p) {
    a = add(a, x);
  }
  int b = 0;
  for (int x : t.q) {
    b = add(b, x);
  }
  b = add(b, t.c);
  ans ret = {{a}, {b}, 0};
  return ret;
}

const int N = 1003;

ans dp[N][2][2][2];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int t = 0; t < 2; t++) {
        for (int x = 0; x < 2; x++) {
          dp[i][j][t][x] = ans();
        }
      }
    }
  }
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int t = 0; t < 2; t++) {
    ans x;
    if (t == 0) {
      x = {{}, {}, 1};
      if (s[0] == 'X') {
        dp[0][0][1][0] = x;
      } else {
        dp[0][0][0][1] = x;
      }
    } else {
      x = {{1}, {}, -1};
      if (s[0] == '-') {
        dp[0][1][1][1] = x;
      }
    }
  }
  //integrate (P(x)+Q(x)/e+c*e^(-x))*(1 - e^(-x))
  vector <int> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  vector <int> rfact(n + 1);
  for (int i = 0; i <= n; i++) {
    rfact[i] = inv(fact[i]);
  }
  vector <int> i0(n + 1);
  vector <int> i1(n + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        i0[i] = add(i0[i], 1);
      }
      i1[i] = add(i1[i], -mul(fact[i], rfact[j]));
    }
  }
  int i2 = inv(2);
  int p = 0, q = 0, r = 0;
  for (int i = 0; i < n; i++) {
    for (int chet = 0; chet < 2; chet++) {
      for (int suf_chet = 0; suf_chet < 2; suf_chet++) {
        for (int suf_nechet = 0; suf_nechet < 2; suf_nechet++) {
          if (i == n - 1) {
            auto ret = dp[i][chet][suf_chet][suf_nechet];
            if (suf_chet) {
              for (int i = 0; i < (int) ret.p.size(); i++) {
                p = add(p, mul(ret.p[i], i0[i]));
                q = add(q, mul(ret.p[i], i1[i]));
              }
              for (int i = 0; i < (int) ret.q.size(); i++) {
                q = add(q, mul(ret.q[i], i0[i]));
                r = add(r, mul(ret.q[i], i1[i]));
              }
              p = add(p, mul(i2, ret.c));
              r = add(r, -mul(i2, ret.c));
            }
            if (suf_nechet) {
              auto okret = ret;
              okret.p = integrate(okret.p);
              okret.q = integrate(okret.q);
              okret.c = mul(okret.c, M - 1);
              auto ok = set_one(okret);
              p = add(p, ok.p[0]);
              q = add(q, ok.q[0]);
              q = add(q, okret.c);
              p = add(p, -okret.c);
              for (int i = 0; i < (int) ret.p.size(); i++) {
                p = add(p, -mul(ret.p[i], i0[i]));
                q = add(q, -mul(ret.p[i], i1[i]));
              }
              for (int i = 0; i < (int) ret.q.size(); i++) {
                q = add(q, -mul(ret.q[i], i0[i]));
                r = add(r, -mul(ret.q[i], i1[i]));
              }
              p = add(p, -mul(i2, ret.c));
              r = add(r, mul(i2, ret.c));
            }
          } else {
            for (int sm = 0; sm < 2; sm++) {
              auto ret = dp[i][chet][suf_chet][suf_nechet];
              ans y = ret;
              if (!sm) {
                y.p = integrate(dp[i][chet][suf_chet][suf_nechet].p);
                y.q = integrate(dp[i][chet][suf_chet][suf_nechet].q);
                y.c = mul(y.c, M - 1);  
                y.p[0] = add(y.p[0], -y.c);
                if (s[i + 1] == 'X' && (chet ^ 1)) continue;
                if (!suf_chet) continue;
                int now_nechet = 1;
                int now_chet = 1;
                if (s[i + 1] == 'X') {
                  now_nechet = 0;
                }
                if (s[i + 1] == '-' && !(chet ^ 1)) {
                  now_chet = 0;
                }
                if (now_chet || now_nechet) {
                  dp[i + 1][chet ^ 1][now_chet][now_nechet] = dp[i + 1][chet ^ 1][now_chet][now_nechet] + y;
                }
              } else {
                y.p = integrate(dp[i][chet][suf_chet][suf_nechet].p);
                y.q = integrate(dp[i][chet][suf_chet][suf_nechet].q);
                y.c = mul(y.c, M - 1);  
                auto go = set_one(y);
                for (int &x : y.p) x = mul(x, M - 1);
                for (int &x : y.q) x = mul(x, M - 1);
                y.c = mul(y.c, M - 1);
                y = y + go;
                int now_nechet = suf_chet;
                int now_chet = suf_nechet;
                if (s[i + 1] == 'X') {
                  now_nechet = 0;
                }
                if (s[i + 1] == '-') {
                  now_chet = 0;
                }
                if (now_chet || now_nechet) {
                  dp[i + 1][0][now_chet][now_nechet] = dp[i + 1][0][now_chet][now_nechet] + y; 
                }
              }
            }
          }
        }
      }
    }
  }
  q = 0;
  cout << p << ' ' << q << ' ' << r << endl;
}
