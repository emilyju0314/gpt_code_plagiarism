#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n;
map<int, int> ss;
int l[maxn], r[maxn], d[maxn * 2];
long long f[2][maxn * 2];
int cnt;
long long inf = 1LL << 60;
int po;
long long baoli() {
  for (int i = 1; i <= cnt; ++i) f[0][i] = inf;
  f[0][po] = 0;
  int p = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= cnt; ++j) f[p ^ 1][j] = inf;
    for (int j = 1; j <= cnt; ++j)
      for (int k = 1; k <= cnt; ++k) {
        if (k <= l[i])
          f[p ^ 1][k] =
              min(f[p ^ 1][k], f[p][j] + abs(d[j] - d[k]) + d[l[i]] - d[k]);
        else if (k >= r[i])
          f[p ^ 1][k] =
              min(f[p ^ 1][k], f[p][j] + abs(d[j] - d[k]) + d[k] - d[r[i]]);
        else
          f[p ^ 1][k] = min(f[p ^ 1][k], f[p][j] + abs(d[j] - d[k]));
      }
    p ^= 1;
  }
  long long ans = inf;
  for (int i = 1; i <= cnt; ++i) ans = min(ans, f[p][i]);
  cout << ans << endl;
  return ans;
}
int maxs = 10;
int main() {
  srand(time(0));
  while (1) {
    ss.clear();
    scanf("%d%d", &n, &po);
    ss[po] = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", l + i, r + i);
      if (l[i] > r[i]) swap(l[i], r[i]);
      if (ss.find(l[i]) == ss.end()) ss[l[i]] = 1;
      if (ss.find(r[i]) == ss.end()) ss[r[i]] = 1;
    }
    cnt = 0;
    for (map<int, int>::iterator i = ss.begin(); i != ss.end(); ++i) {
      ++cnt;
      i->second = cnt;
      d[cnt] = i->first;
      f[0][cnt] = f[1][cnt] = inf;
    }
    for (int i = 1; i <= n; ++i) l[i] = ss[l[i]], r[i] = ss[r[i]];
    po = ss[po];
    f[0][po] = 0;
    int p = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= cnt; ++j) f[p ^ 1][j] = inf;
      long long mm = inf;
      for (int j = 1; j <= l[i]; ++j) {
        mm = min(mm, f[p][j] + d[l[i]] - d[j]);
        f[p ^ 1][j] = min(f[p ^ 1][j], mm);
      }
      for (int j = l[i] + 1; j < r[i]; ++j) f[p ^ 1][j] = f[p][j];
      mm = inf;
      for (int j = cnt; j >= r[i]; --j) {
        mm = min(mm, f[p][j] + d[j] - d[r[i]]);
        f[p ^ 1][j] = min(f[p ^ 1][j], mm);
      }
      p ^= 1;
    }
    long long ans = inf;
    for (int i = 1; i <= cnt; ++i) ans = min(ans, f[p][i]);
    cout << ans << endl;
    break;
  }
  return 0;
}
