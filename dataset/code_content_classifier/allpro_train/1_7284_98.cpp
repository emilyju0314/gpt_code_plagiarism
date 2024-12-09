#include <bits/stdc++.h>
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
using namespace std;
class pa3 {
 public:
  int x;
  int y, z;
  pa3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
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
  int x;
  int y, z, w;
  pa4(int x = 0, int y = 0, int z = 0, int w = 0) : x(x), y(y), z(z), w(w) {}
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
  int x, y;
  pa2(int x = 0, int y = 0) : x(x), y(y) {}
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
string itos(int i) {
  ostringstream s;
  s << i;
  return s.str();
}
int gcd(int v, int b) {
  if (v > b) return gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return gcd(v, b % v);
}
int mod;
int extgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
pair<int, int> operator+(const pair<int, int> &l, const pair<int, int> &r) {
  return {l.first + r.first, l.second + r.second};
}
pair<int, int> operator-(const pair<int, int> &l, const pair<int, int> &r) {
  return {l.first - r.first, l.second - r.second};
}
int pr[1000010];
int inv[1000010];
int beki(int wa, int rr, int warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  wa %= warukazu;
  if (rr % 2 == 1)
    return ((long long)beki(wa, rr - 1, warukazu) * (long long)wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
int comb(int nn, int rr) {
  if (rr < 0 || rr > nn || nn < 0) return 0;
  int r = pr[nn] * inv[rr];
  r %= mod;
  r *= inv[nn - rr];
  r %= mod;
  return r;
}
void gya(int ert) {
  pr[0] = 1;
  for (int i = 1; i <= ert; i++) {
    pr[i] = ((long long)pr[i - 1] * i) % mod;
  }
  inv[ert] = beki(pr[ert], mod - 2, mod);
  for (int i = ert - 1; i >= 0; i--) {
    inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
  }
}
const int N = 140000;
vector<int> G[(1 << 17) + 5];
int dis[(1 << 17) + 5];
int mae[N];
void dfs(int r, int p, int d = 0) {
  mae[r] = p;
  dis[r] = d;
  for (auto v : G[r])
    if (v != p) dfs(v, r, d + 1);
}
vector<int> G2[140000];
int m;
int d2[140000];
void dfs2(int r, int p, int d = 0) {
  d2[r] = d;
  for (auto v : G[r])
    if (v != p) {
      G2[r].push_back(v);
      dfs2(v, r, d + 1);
    }
}
int st[140000] = {};
void dfs3(int r) {
  for (auto v : G2[r]) dfs3(v);
  if (G2[r].size() == 0) {
    st[r] = 1;
    return;
  }
  if (G2[r].size() != 2) {
    st[r] = -1;
    return;
  }
  st[r] = -1;
  int f1 = st[G2[r][0]];
  int f2 = st[G2[r][1]];
  if (f2 == f1) st[r] = f1 + 1;
}
bool kakunin(int r, int d, int n) {
  if (d == n) {
    return G2[r].size() == 0;
  }
  if (G2[r].size() != 2) return 0;
  if (!kakunin(G2[r][0], d + 1, n)) return 0;
  if (!kakunin(G2[r][1], d + 1, n)) return 0;
  return 1;
}
vector<int> ans;
void ch(int n, int r) {
  for (int i = 0; i < 140000; i++) G2[i].clear(), st[i] = 0;
  dfs2(r, r);
  dfs3(r);
  int it = -1, g = -1;
  for (int i = 1; i <= m; i++)
    if (st[i] == -1) {
      if (g < d2[i]) {
        g = d2[i], it = i;
      }
    }
  if (g > n - 2) return;
  if (g == n - 2) {
    G2[it].push_back(0);
  } else {
    if (G2[it].size() != 3) return;
    vector<pair<int, int> > R;
    for (int i = 0; i < 3; i++)
      R.push_back(make_pair(st[G2[it][i]], G2[it][i]));
    sort(R.begin(), R.end());
    if (R[0].first != R[1].first) return;
    if (R[2].first != R[1].first + 1) return;
    G2[it].clear();
    G2[it].push_back(0);
    G2[it].push_back(R[2].second);
    G2[0].push_back(R[0].second);
    G2[0].push_back(R[1].second);
  }
  if (kakunin(r, 1, n)) {
    ans.push_back(it);
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 2) {
    cout << 2 << endl;
    cout << "1 2" << endl;
    return 0;
  }
  for (int i = 0; i < (1 << n) - 3; i++) {
    int y, yy;
    cin >> y >> yy;
    G[y].push_back(yy);
    G[yy].push_back(y);
  }
  m = (1 << n) - 2;
  dfs(1, 1);
  int it = -1, d = -1;
  for (int i = 1; i <= m; i++) {
    if (d < dis[i]) {
      it = i, d = dis[i];
    }
  }
  dfs(it, it);
  it = -1, d = -1;
  for (int i = 1; i <= m; i++) {
    if (d < dis[i]) {
      it = i, d = dis[i];
    }
  }
  if ((d - 1) / 2 + 2 != n) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> path;
  while (1) {
    path.push_back(it);
    it = mae[it];
    if (it == path.back()) break;
  }
  int t = path.size();
  if (t % 2) {
    ch(n, path[t / 2]);
  } else {
    ch(n, path[t / 2]);
    ch(n, path[t / 2 - 1]);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto v : ans) cout << v << " ";
  cout << endl;
  return 0;
}
