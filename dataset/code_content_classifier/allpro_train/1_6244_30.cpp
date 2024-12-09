#include <bits/stdc++.h>
using namespace std;
long long int cnt[1000009], revcnt[1000009];
long long int val[1000009], revval[1000009];
long long int nm[1000009], vec[1000009];
vector<long long int> ans, pp;
bool vis[10000009];
int main() {
  long long int a, b, c, d, e, i, j, k, l, n, m, x, y, t, p, r, sz, cc, aa;
  long long int tcc, taa, tbb;
  scanf("%lld", &n);
  x = 0;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &nm[i]);
    x += nm[i];
    vec[i] = nm[i];
    nm[i] += nm[i - 1];
  }
  if (x <= 1) {
    printf("-1\n");
    return 0;
  }
  for (i = 1; i <= n; i++) {
    cnt[i] = cnt[i - 1] + vec[i];
    val[i] = val[i - 1] + cnt[i - 1];
  }
  for (i = n; i >= 1; i--) {
    revcnt[i] += revcnt[i + 1] + vec[i];
    revval[i] = revval[i + 1] + revcnt[i + 1];
  }
  a = 1000000;
  b = 1000;
  pp.push_back(2);
  memset(vis, true, sizeof(vis));
  for (i = 3; i <= b; i += 2) {
    if (vis[i]) {
      for (j = i * i; j <= a; j += (i + i)) {
        vis[j] = false;
      }
    }
  }
  for (i = 3; i <= a; i += 2) {
    if (vis[i]) {
      pp.push_back(i);
    }
  }
  l = pp.size();
  sz = x;
  for (i = 0; i < l; i++) {
    if (x % pp[i] == 0) {
      while (x % pp[i] == 0) {
        x = x / pp[i];
      }
      ans.push_back(pp[i]);
    }
  }
  if (x != 1) {
    ans.push_back(x);
  }
  x = 999999999999999999;
  m = ans.size();
  for (i = 0; i < m; i++) {
    c = ans[i];
    y = 0;
    a = b = 0;
    l = r = 1;
    for (j = 0; j < sz; j += c) {
      l = r;
      cc = nm[l] - nm[l - 1] - b;
      aa = cc / c;
      if (cc % c == 0) {
        j += (aa - 1) * c;
        b = 0;
        r = l + 1;
        continue;
      } else {
        j += (aa * c);
      }
      for (k = l + 1; k <= n; k++) {
        if (nm[k] >= j + c) {
          r = k;
          break;
        }
      }
      a = j - nm[l - 1];
      b = nm[r] - (j + c);
      cc = 999999999999999999;
      for (k = l; k <= r; k++) {
        d = (val[k] - val[l - 1]) - (cnt[l - 1] * (k - (l - 1))) -
            (a * (k - l));
        e = (revval[k] - revval[r + 1]) - (revcnt[r + 1] * ((r + 1) - k)) -
            (b * (r - k));
        d += e;
        cc = min(cc, d);
      }
      y += cc;
      if (j + c < nm[r]) {
        b = j + c - nm[r - 1];
      } else {
        b = 0;
        r++;
      }
    }
    x = min(x, y);
  }
  printf("%lld\n", x);
}
