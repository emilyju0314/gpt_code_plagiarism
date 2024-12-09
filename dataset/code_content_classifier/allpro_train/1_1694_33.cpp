#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int bg[N], nx[N * 2], to[N * 2], va[N * 2], tl;
inline void add(int x, int y, int v) {
  nx[++tl] = bg[x];
  bg[x] = tl;
  to[tl] = y;
  va[tl] = v;
}
long long ans;
int n, m, siz[N], book[N], p10[N], inv10[N];
inline int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % m;
    x = 1ll * x * x % m;
    y >>= 1;
  }
  return ret;
}
map<int, int> mp;
void dfs_prep(int now, int f) {
  siz[now] = 1;
  for (int i = bg[now]; i; i = nx[i]) {
    int aim = to[i];
    if (aim == f || book[aim]) continue;
    dfs_prep(aim, now);
    siz[now] += siz[aim];
  }
}
int ctr;
void dfs_dp(int now, int f, int out) {
  if (out > (out + siz[now]) / 2) return;
  int mx = 0;
  for (int i = bg[now]; i; i = nx[i]) {
    int aim = to[i];
    if (aim == f || book[aim]) continue;
    dfs_dp(aim, now, out + siz[now] - siz[aim]);
    mx = max(mx, siz[aim]);
  }
  if (mx <= (out + siz[now]) / 2) ctr = now;
}
void ctb(int now, int f, int dep, int dis, int typ) {
  if (typ == 0)
    mp[dis]++;
  else {
    int tmp = 1ll * (m - dis) * inv10[dep] % m;
    ans += mp[tmp] * typ;
  }
  for (int i = bg[now]; i; i = nx[i]) {
    int aim = to[i];
    if (aim == f || book[aim]) continue;
    if (typ == 0)
      ctb(aim, now, dep + 1, (dis + 1ll * p10[dep] * va[i] % m) % m, 0);
    else
      ctb(aim, now, dep + 1, (10ll * dis % m + va[i]) % m, typ);
  }
}
void DAC(int now) {
  book[now] = 1;
  ctb(now, -1, 0, 0, 0);
  ctb(now, -1, 0, 0, 1);
  mp.clear();
  for (int i = bg[now]; i; i = nx[i]) {
    int aim = to[i];
    if (book[aim]) continue;
    ctb(aim, now, 1, va[i] % m, 0);
    ctb(aim, now, 1, va[i] % m, -1);
    mp.clear();
  }
  for (int i = bg[now]; i; i = nx[i]) {
    int aim = to[i];
    if (book[aim]) continue;
    dfs_prep(aim, now);
    dfs_dp(aim, now, 0);
    DAC(ctr);
  }
}
int isp[N], pri[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    add(x, y, v), add(y, x, v);
  }
  int up = sqrt(m);
  for (int i = 2; i <= up; i++) {
    if (!isp[i]) pri[++pri[0]] = i;
    for (int j = 1; j <= pri[0] && i * pri[j] <= up; j++) {
      isp[i * pri[j]] = 1;
      if (!(i % pri[j])) break;
    }
  }
  int eu = m, tmp = m;
  for (int i = 1; i <= pri[0]; i++) {
    if (!(tmp % pri[i])) eu /= pri[i], eu *= pri[i] - 1;
    while (!(tmp % pri[i])) tmp /= pri[i];
  }
  if (tmp != 1) eu /= tmp, eu *= tmp - 1;
  int inv = qpow(10, eu - 1);
  p10[0] = inv10[0] = 1;
  for (int i = 1; i <= n; i++)
    p10[i] = 1ll * p10[i - 1] * 10 % m, inv10[i] = 1ll * inv10[i - 1] * inv % m;
  dfs_prep(0, -1);
  dfs_dp(0, -1, 0);
  DAC(ctr);
  printf("%lld", ans - n);
  return 0;
}
