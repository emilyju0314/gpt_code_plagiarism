#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long double eps = 1e-12;
long long dx[] = {0, 0, 1, -1};
long long dy[] = {1, -1, 0, 0};
long long n, res = 0, k = 0, h, ans = 0, m, level = 0;
;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long x, long long y) { return (x * y) / gcd(x, y); }
long long pot(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b % 2) r = (r * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return r % mod;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
vector<long long> v[300005], vnode;
void add_edge(long long x, long long y) {
  v[x].push_back(y);
  v[y].push_back(x);
}
string s2, ch = "", s[5000], s1 = "", t;
vector<pair<string, long long> > vm;
vector<pair<pair<long long, long long>, long long> > vvvl, vvvr;
vector<pair<long long, long long> > vv, vv2;
long long a[500][500], b[500500];
map<long long, long long> mp;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long i = 0, x = 0, z = 0, y = 0, j = 0, q, mx = 0, mm, idx = 0, ok = 0,
            l = 0, r, negatif = 0, positif = 0, l1, r1, p;
  set<long long>::iterator it, it2;
  multiset<long long>::iterator it1;
  multiset<long long> mst1, mst2;
  cin >> n >> m >> k >> x >> y;
  long long cnt = n * m;
  if (n > 1) cnt += (n - 2) * m;
  long long d = k / cnt;
  long long rest = k % cnt;
  for (i = 1; i <= (long long)(n); i++) {
    for (j = 1; j <= (long long)(m); j++) {
      if (i > 1 && i < n)
        a[i][j] = 2 * d;
      else
        a[i][j] = d;
    }
  }
  for (i = 1; i <= (long long)(n); i++) {
    for (j = 1; j <= (long long)(m); j++) {
      if (rest) {
        a[i][j]++;
        rest--;
      }
    }
  }
  for (i = n - 1; i >= 2; i--) {
    for (j = 1; j <= m; j++) {
      if (rest) {
        a[i][j]++;
        rest--;
      }
    }
  }
  mx = 0;
  mm = 1e18;
  for (i = 1; i <= (long long)(n); i++) {
    for (j = 1; j <= (long long)(m); j++) {
      mx = max(mx, a[i][j]);
      mm = min(mm, a[i][j]);
    }
  }
  cout << mx << " " << mm << " " << a[x][y] << endl;
  return 0;
}
