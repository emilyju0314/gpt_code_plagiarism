#include <bits/stdc++.h>
using namespace std;
int SET(int n, int pos) { return n = n | (1 << pos); }
int RESET(int n, int pos) { return n = n & ~(1 << pos); }
int CHECK(int n, int pos) { return (bool)(n & (1 << pos)); }
int str2int(string s) {
  stringstream ss(s);
  int x;
  ss >> x;
  return x;
}
string int2str(int a) {
  stringstream ss;
  ss << a;
  string str = ss.str();
  return str;
}
string char2str(char a) {
  stringstream ss;
  ss << a;
  string str = ss.str();
  return str;
}
long long int bigMod(long long int n, long long int power, long long int MOD) {
  if (power == 0) return 1;
  if (power % 2 == 0) {
    long long int ret = bigMod(n, power / 2, MOD);
    return ((ret % MOD) * (ret % MOD)) % MOD;
  } else
    return ((n % MOD) * (bigMod(n, power - 1, MOD) % MOD)) % MOD;
}
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m, t, q;
  long long int x0 = 0, x1 = 1;
  if (m == 1) return 0;
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0) x1 += m0;
  return x1;
}
int POW(int x, int y) {
  int res = 1;
  for (; y;) {
    if ((y & 1)) {
      res *= x;
    }
    x *= x;
    y >>= 1;
  }
  return res;
}
int inverse(int x) {
  double p = ((double)1.0) / x;
  return (p) + 1e-9;
}
int gcd(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
int nC2(int n) { return n * (n - 1) / 2; }
long long int MOD(long long int n, long long int mod) {
  if (n >= 0)
    return n % mod;
  else if (-n == mod)
    return 0;
  else
    return mod + (n % mod);
}
long long int data[100005];
int main() {
  int t, cas = 0;
  int n, m;
  long long int l;
  cin >> n >> m >> l;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &data[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (data[i] <= l) continue;
    for (int j = i; j < n; j++) {
      if (data[j] <= l) {
        break;
      }
      i = j;
    }
    ans++;
  }
  while (m--) {
    int tt;
    scanf("%d", &tt);
    if (tt == 0) {
      printf("%d\n", ans);
    } else {
      int p;
      long long int d;
      scanf("%d %lld", &p, &d);
      p--;
      if (data[p] > l) continue;
      if (data[p] + d <= l) {
        data[p] += d;
        continue;
      }
      int x = 0, y = 0;
      if (p > 0 && data[p - 1] > l) x++;
      if (p < n - 1 && data[p + 1] > l) y++;
      if (x && y) ans--;
      if (!x && !y) ans++;
      data[p] += d;
    }
  }
  return 0;
}
