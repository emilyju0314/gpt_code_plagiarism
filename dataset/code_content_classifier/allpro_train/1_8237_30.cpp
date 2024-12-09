#include <bits/stdc++.h>
long long dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
long long dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
using namespace std;
class pa3 {
 public:
  long long x;
  long long y, z;
  pa3(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  bool operator<(const pa3 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator>(const pa3 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    return z > p.z;
  }
  bool operator==(const pa3 &p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  bool operator!=(const pa3 &p) const {
    return !(x == p.x && y == p.y && z == p.z);
  }
};
class pa4 {
 public:
  long long x;
  long long y, z, w;
  pa4(long long x = 0, long long y = 0, long long z = 0, long long w = 0)
      : x(x), y(y), z(z), w(w) {}
  bool operator<(const pa4 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    if (z != p.z) return z < p.z;
    return w < p.w;
  }
  bool operator>(const pa4 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    if (z != p.z) return z > p.z;
    return w > p.w;
  }
  bool operator==(const pa4 &p) const {
    return x == p.x && y == p.y && z == p.z && w == p.w;
  }
};
class pa2 {
 public:
  long long x, y;
  pa2(long long x = 0, long long y = 0) : x(x), y(y) {}
  pa2 operator+(pa2 p) { return pa2(x + p.x, y + p.y); }
  pa2 operator-(pa2 p) { return pa2(x - p.x, y - p.y); }
  bool operator<(const pa2 &p) const { return y != p.y ? y < p.y : x < p.x; }
  bool operator>(const pa2 &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const pa2 &p) const {
    return abs(x - p.x) == 0 && abs(y - p.y) == 0;
  }
  bool operator!=(const pa2 &p) const {
    return !(abs(x - p.x) == 0 && abs(y - p.y) == 0);
  }
};
string itos(long long i) {
  ostringstream s;
  s << i;
  return s.str();
}
long long gcd(long long v, long long b) {
  if (v > b) return gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return gcd(v, b % v);
}
long long mod;
long long extgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
pair<long long, long long> operator+(const pair<long long, long long> &l,
                                     const pair<long long, long long> &r) {
  return {l.first + r.first, l.second + r.second};
}
pair<long long, long long> operator-(const pair<long long, long long> &l,
                                     const pair<long long, long long> &r) {
  return {l.first - r.first, l.second - r.second};
}
long long pr[200010];
long long inv[200010];
long long beki(long long wa, long long rr, long long warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
long long comb(long long nn, long long rr) {
  if (rr < 0 || rr > nn || nn < 0) return 0;
  long long r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(long long ert) {
  pr[0] = 1;
  for (long long i = 1; i <= ert; i++) {
    pr[i] = (pr[i - 1] * i) % mod;
  }
  inv[ert] = beki(pr[ert], mod - 2, mod);
  for (long long i = ert - 1; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % mod;
  }
}
vector<pair<long long, long long>> G[200020];
map<pair<long long, long long>, long long> ma;
priority_queue<pa3, vector<pa3>, greater<pa3>> pq;
multiset<long long> se;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 0; i < m; i++) {
    long long y, yy, yyy;
    cin >> y >> yy >> yyy;
    if (y > yy) swap(y, yy);
    G[y].push_back({yy, yyy});
    G[yy].push_back({y, yyy});
    pq.push((pa3){yyy, y, yy});
    ma[make_pair(y, yy)] = yyy;
    se.insert(yyy);
  }
  while (se.size() > k) se.erase(--se.end());
  long long ima = 1000000007 * 10000000ll;
  for (long long K = 0; K < k; K++) {
    pa3 z;
  lll:;
    z = pq.top();
    pq.pop();
    if (ma[make_pair(z.y, z.z)] == -1) goto lll;
    ma[make_pair(z.y, z.z)] = -1;
    if (K == k - 1) {
      cout << z.x << endl;
      return;
    }
    for (auto v : G[z.y]) {
      long long fr = z.z;
      long long to = v.first;
      if (fr == to) continue;
      if (fr > to) swap(fr, to);
      if (ima <= z.x + v.second) continue;
      if (ma.count(make_pair(fr, to)) == false) {
        se.insert(z.x + v.second);
        while (se.size() > k) se.erase(--se.end());
        if (se.size() == k) ima = *se.rbegin();
        pq.push((pa3){z.x + v.second, fr, to});
        ma[make_pair(fr, to)] = z.x + v.second;
      } else if (ma[make_pair(fr, to)] > z.x + v.second) {
        pq.push((pa3){z.x + v.second, fr, to});
        ma[make_pair(fr, to)] = z.x + v.second;
      }
    }
    for (auto v : G[z.z]) {
      long long fr = z.y;
      long long to = v.first;
      if (fr == to) continue;
      if (fr > to) swap(fr, to);
      if (ima <= z.x + v.second) continue;
      if (ma.count(make_pair(fr, to)) == false) {
        se.insert(z.x + v.second);
        while (se.size() > k) se.erase(--se.end());
        if (se.size() == k) ima = *se.rbegin();
        pq.push((pa3){z.x + v.second, fr, to});
        ma[make_pair(fr, to)] = z.x + v.second;
      } else if (ma[make_pair(fr, to)] > z.x + v.second) {
        pq.push((pa3){z.x + v.second, fr, to});
        ma[make_pair(fr, to)] = z.x + v.second;
      }
    }
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = 1;
  for (long long i = 0; i < n; i++) {
    solve();
  }
}
