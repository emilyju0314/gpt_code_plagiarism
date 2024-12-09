#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long mod2 = 998244353;
long long mod3 = 1000003;
long long mod4 = 998244853;
long long mod5 = 1000000009;
long long inf = 1LL << 62;
int iinf = 1 << 30;
double pi = 3.141592653589793238462643383279L;
double eps = 1e-8;
int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};
int ddh[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddw[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long c = gcd(a, b);
  return a * b / c;
}
long long Pow(long long n, long long k) {
  if (k < 0) return 0;
  long long ret = 1;
  long long now = n;
  while (k > 0) {
    if (k & 1) ret *= now;
    now *= now;
    k /= 2;
  }
  return ret;
}
long long beki(long long n, long long k, long long md) {
  long long ret = 1;
  long long now = n;
  now %= md;
  while (k > 0) {
    if (k % 2 == 1) {
      ret *= now;
      ret %= md;
    }
    now *= now;
    now %= md;
    k /= 2;
  }
  return ret;
}
long long gyaku(long long n, long long md) { return beki(n, md - 2, md); }
long long popcount(long long n) {
  long long ret = 0;
  long long u = n;
  while (u > 0) {
    ret += u % 2;
    u /= 2;
  }
  return ret;
}
struct MaST {
 private:
  long long n;
  vector<pair<long long, long long> > dat;

 public:
  MaST(vector<long long> v) {
    long long sz = v.size();
    n = 1;
    while (n < sz) n *= 2;
    pair<long long, long long> p = {-inf, -inf};
    dat.resize(2 * n - 1, p);
    for (int i = 0; i < sz; i++) dat[i + n - 1] = {v[i], i};
    for (long long i = n - 2; i >= 0; i--) {
      dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  void add(long long k, long long x) {
    long long i = k + n - 1;
    dat[i] = {x, k};
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = max(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }
  pair<long long, long long> que(long long a, long long b, long long k = 0,
                                 long long l = 0, long long r = -1) {
    if (r < 0) r = n;
    if (b <= l || a >= r) return {-inf, -inf};
    if (a <= l && b >= r) return dat[k];
    pair<long long, long long> m1 = que(a, b, 2 * k + 1, l, (l + r) / 2);
    pair<long long, long long> m2 = que(a, b, 2 * k + 2, (l + r) / 2, r);
    return max(m1, m2);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt[26];
    fill(cnt, cnt + 26, 0);
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    bool bo = false;
    for (int i = 0; i < n; i++) {
      cnt[t[i] - 'a']--;
      if (cnt[t[i] - 'a'] < 0) {
        cout << -1 << endl;
        bo = true;
        break;
      }
    }
    if (bo) continue;
    MaST seg(vector<long long>(n + 1, 0));
    long long dp[n + 1];
    fill(dp, dp + n + 1, 0);
    bool ok[n];
    fill(ok, ok + n, false);
    int now = n;
    for (long long i = n - 1; i >= 0; i--) {
      for (long long j = n - 1; j >= 0; j--) {
        if (ok[j]) continue;
        if (t[j] == s[i]) {
          ok[j] = true;
          break;
        }
      }
      while (now > 0 && ok[now - 1]) now--;
      for (int j = now; j < n; j++) {
        if (s[i] == t[j]) {
          pair<long long, long long> p = seg.que(j + 1, n + 1);
          dp[j] = max(dp[j], p.first + 1);
          seg.add(j, dp[j]);
        }
      }
    }
    pair<long long, long long> p = seg.que(0, n + 1);
    cout << n - p.first << endl;
  }
}
