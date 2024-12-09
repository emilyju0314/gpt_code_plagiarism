#include <bits/stdc++.h>
using namespace std;
long long x, n, k, q;
long long c[10];
map<long long, long long> mp, rmp, t;
long long f[110], pre[110];
bool g[100000010];
long long tp = 0;
struct matrix {
  long long x[110][110];
  matrix() { memset(x, 0, sizeof(x)); }
  matrix unit() {
    matrix res;
    for (int i = 0; i < tp; i++) res.x[i][i] = 1;
    return res;
  }
  matrix operator*(matrix A) {
    matrix res;
    for (int i = 0; i < tp; i++) {
      for (int j = 0; j < tp; j++) res.x[i][j] = 1e18 + 1;
    }
    for (int i = 0; i < tp; i++)
      for (int k = 0; k < tp; k++)
        for (int j = 0; j < tp; j++) {
          res.x[i][j] = min(res.x[i][j], (x[i][k] + A.x[k][j]));
        }
    return res;
  }
  matrix operator^(long long k) {
    if (!k) return unit();
    matrix res, tmp;
    for (int i = 0; i < tp; i++)
      for (int j = 0; j < tp; j++) {
        res.x[i][j] = tmp.x[i][j] = x[i][j];
      }
    k--;
    while (k) {
      if (k & 1) res = res * tmp;
      tmp = tmp * tmp;
      k >>= 1;
    }
    return res;
  }
} mt;
void nextStep(long long mask) {
  if (!(mask & (1 << 0))) {
    mt.x[mp[mask]][mp[mask / 2]] = -1;
    return;
  }
  for (int i = 1; i <= k; i++) {
    if (mask & (1 << i)) continue;
    long long nwmask = mask | (1 << i);
    nwmask /= 2;
    mt.x[mp[mask]][mp[nwmask]] = c[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> k >> n >> q;
  for (int i = 1; i <= k; i++) cin >> c[i];
  long long cnt = 0;
  for (int i = 0; i < (1 << k); i++) {
    if (__builtin_popcount(i) == x) {
      mp[i] = cnt;
      rmp[cnt] = i;
      cnt++;
    }
  }
  long long ans = 1e18;
  for (int i = 0; i < cnt; i++) {
    nextStep(rmp[i]);
  }
  tp = cnt;
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < cnt; j++) {
      if (mt.x[i][j] == 0)
        mt.x[i][j] = 1e18;
      else if (mt.x[i][j] == -1)
        mt.x[i][j] = 0;
    }
  }
  for (int i = 0; i < cnt; i++) {
    if (i != 0) f[i] = 1e18;
  }
  for (int i = 1; i <= q; i++) {
    int u, w;
    cin >> u >> w;
    t[u] = w;
    for (int j = max(0LL, u - k + 1); j <= u; j++) g[j] = 1;
  }
  int tmp = 0;
  for (int i = n - k + 1; i <= n; i++) g[i] = 1;
  for (int i = 2; i <= n - x + 1; i++) {
    if (g[i] == 0) {
      tmp++;
    } else {
      if (tmp != 0) {
        matrix temp = mt ^ tmp;
        tmp = 0;
        for (int j = 0; j < cnt; j++) {
          pre[j] = 1e18;
          for (int z = 0; z < cnt; z++) {
            pre[j] = min(pre[j], f[z] + temp.x[z][j]);
          }
        }
        for (int j = 0; j < cnt; j++) {
          f[j] = pre[j];
        }
      }
      for (int j = 0; j < cnt; j++) pre[j] = 1e18;
      for (int j = 0; j < cnt; j++) {
        long long mask = rmp[j];
        if ((mask & (1 << 0)) == 0) {
          pre[mp[mask / 2]] = min(pre[mp[mask / 2]], f[j]);
          continue;
        }
        for (int z = 1; z <= k; z++) {
          if (mask & (1 << z)) continue;
          long long nwmask = mask | (1 << z);
          long long nwpo = i + z - 1;
          nwmask /= 2;
          pre[mp[nwmask]] = min(pre[mp[nwmask]], f[j] + c[z] + t[nwpo]);
        }
      }
      for (int j = 0; j < cnt; j++) f[j] = pre[j];
      if (i >= n - k + 1) {
        int mask = 0;
        for (int j = n - x + 1; j <= n; j++) {
          int diff = j - i;
          mask = mask | (1 << diff);
        }
        ans = min(ans, f[mp[mask]]);
      }
    }
  }
  if (1 >= n - k + 1) {
    int mask = 0;
    for (int j = n - x + 1; j <= n; j++) {
      int diff = j - 1;
      mask = mask | (1 << diff);
    }
    ans = min(ans, f[mp[mask]]);
  }
  cout << ans;
}
