#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 500010;
long long t, n, cnt, x, x2, m, a[maxn], b[maxn], tag[maxn], ans[75], pos,
    c[maxn], l, r, mid, y, z, mx, k, mod1 = 1000000007, mod2 = 998244353, cnt1,
                                     cnt2, cnt3, cnt4, cnt5, cnt6, mn,
                                     vis[maxn], sum, pos1, pos2, dis[maxn];
long long dif[maxn], isx[maxn], is0[maxn], k2;
long long yy[200005], zz[200005];
long long item[300][4];
long long matrix[300][300];
long long tw1[maxn], tw2[maxn];
set<long long> se;
vector<pair<long long, long long> > v[maxn], v2[maxn];
vector<long long> gr[maxn];
string s, s1, s2, s3, s4;
char cc[1005][1005], abc[205];
pair<long long, long long> p[maxn], pp;
map<pair<long long, long long>, long long> mp;
char ch;
void build(long long l, long long r, long long v) {
  if (l == r) {
    b[v] = 0;
    return;
  }
  long long mid = (l + r) >> 1;
  build(l, mid, v << 1);
  build(mid + 1, r, v << 1 | 1);
  b[v] = 0;
}
long long qu(long long l, long long r, long long v, long long l2,
             long long r2) {
  if (l == l2 && r == r2) {
    return b[v];
  }
  long long mid = (l + r) >> 1;
  if (mid >= r2) {
    return qu(l, mid, v << 1, l2, r2);
  } else if (mid + 1 <= l2) {
    return qu(mid + 1, r, v << 1 | 1, l2, r2);
  } else {
    return max(qu(l, mid, v << 1, l2, mid),
               qu(mid + 1, r, v << 1 | 1, mid + 1, r2));
  }
}
void modify(long long l, long long r, long long v, long long l2, long long r2,
            long long m) {
  if (l == l2 && r == r2) {
    b[v] = max(b[v], m);
    return;
  }
  long long mid = (l + r) >> 1;
  if (mid >= r2) {
    modify(l, mid, v << 1, l2, r2, m);
  } else if (mid + 1 <= l2) {
    modify(mid + 1, r, v << 1 | 1, l2, r2, m);
  } else {
    modify(l, mid, v << 1, l2, mid, m);
    modify(mid + 1, r, v << 1 | 1, mid + 1, r2, m);
  }
  b[v] = max(b[v << 1], b[v << 1 | 1]);
}
bool isp(long long x) {
  if (x == 1) {
    return 0;
  }
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
void findpair(long long xx) {
  if (xx == x) {
    for (long long j = 0; j < x; j++) {
      item[cnt][j] = a[j];
    }
    cnt++;
    return;
  }
  if (!xx) {
    for (long long i = 1; i <= k; i++) {
      a[0] = i;
      findpair(1);
    }
  } else {
    for (long long i = 1; i <= k; i++) {
      if (i != a[xx - 1]) {
        a[xx] = i;
        findpair(xx + 1);
      }
    }
  }
}
signed main() {
  long long y2, z2;
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s >> s1;
  x = 10;
  n = s1.size();
  cnt1 = rng();
  cnt1 = abs(cnt1);
  cnt1 %= 1000000000;
  mod1 = 1000000000 + cnt1;
  while (!isp(mod1)) {
    mod1++;
  }
  cnt2 = rng();
  cnt2 = abs(cnt2);
  cnt2 %= 1000000000;
  mod2 = 1000000000 + cnt2;
  while (!isp(mod2)) {
    mod2++;
  }
  y = 0;
  yy[0] = 0;
  for (long long i = 0; i < n; i++) {
    y *= x;
    y += (s1[i] - '0');
    y %= mod1;
    yy[i + 1] = y;
  }
  y2 = y - mod1;
  z = 0;
  zz[0] = 0;
  for (long long i = 0; i < n; i++) {
    z *= x;
    z += (s1[i] - '0');
    z %= mod2;
    zz[i + 1] = z;
  }
  z2 = z - mod2;
  k = s.size();
  a[0] = 0;
  b[0] = 0;
  tw1[0] = 1;
  tw2[0] = 1;
  for (long long i = 0; i < k; i++) {
    a[i + 1] = a[i] * x + (s[i] - '0');
    a[i + 1] %= mod1;
    b[i + 1] = b[i] * x + (s[i] - '0');
    b[i + 1] %= mod2;
    tw1[i + 1] = tw1[i] * x;
    tw1[i + 1] %= mod1;
    tw2[i + 1] = tw2[i] * x;
    tw2[i + 1] %= mod2;
  }
  n--;
  for (long long i = 0; i <= k - 2 * (n); i++) {
    m = a[i + n] - a[i] * tw1[n] + a[i + 2 * n] - a[i + n] * tw1[n];
    m %= mod1;
    if (m == y || m == y2) {
      m = b[i + n] - b[i] * tw2[n] + b[i + 2 * n] - b[i + n] * tw2[n];
      m %= mod2;
      if (m == z || m == z2) {
        cout << i + 1 << " " << i + n << '\n';
        cout << i + n + 1 << " " << i + n * 2 << '\n';
        return 0;
      }
    }
  }
  n++;
  for (long long i = 0; i <= k - n; i++) {
    l = 0;
    r = n;
    while (l < r) {
      mid = (l + r + 1) / 2;
      x = (a[mid + i] - a[i] * tw1[mid]) % mod1;
      if (x < 0) {
        x += mod1;
      }
      if ((yy[mid] - x == 0 || yy[mid] - x == 1 ||
           (yy[mid] == 0 && x == mod1 - 1))) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    x = (a[i + n] - a[i] * tw1[n]);
    if (i >= n - r && n - r > 0) {
      m = (x + a[i] - a[i - n + r] * tw1[n - r]) % mod1;
      if ((m == y || m == y2)) {
        cout << i - n + r + 1 << " " << i << '\n';
        cout << i + 1 << " " << i + n << '\n';
        return 0;
      }
    }
    if (i >= n - r + 1 && n - r + 1 > 0) {
      m = (x + a[i] - a[i - n + r - 1] * tw1[n - r + 1]) % mod1;
      if ((m == y || m == y2)) {
        cout << i - n + r << " " << i << '\n';
        cout << i + 1 << " " << i + n << '\n';
        return 0;
      }
    }
    if (k - i - n >= n - r && n - r > 0) {
      m = (x + a[i + n * 2 - r] - a[i + n] * tw1[n - r]) % mod1;
      if ((m == y || m == y2)) {
        cout << i + 1 << " " << i + n << '\n';
        cout << i + n + 1 << " " << i + 2 * n - r << '\n';
        return 0;
      }
    }
    if (k - i - n >= n - r + 1 && n - r + 1 > 0) {
      m = (x + a[i + n * 2 - r + 1] - a[i + n] * tw1[n - r + 1]) % mod1;
      if ((m == y || m == y2)) {
        cout << i + 1 << " " << i + n << '\n';
        cout << i + n + 1 << " " << i + 2 * n - r + 1 << '\n';
        return 0;
      }
    }
  }
}
