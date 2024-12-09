#include <bits/stdc++.h>
using namespace std;
struct Planet {
  int a[105], b[105], c[105];
} p[12];
struct whh {
  int id, diff;
  bool operator<(const whh& a) const { return diff > a.diff; }
} w[105];
int main() {
  string name;
  int n, m, k, ans, money, kk;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> name;
    for (int j = 1; j <= m; j++) cin >> p[i].a[j] >> p[i].b[j] >> p[i].c[j];
  }
  ans = 0x80000000;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) {
        for (int z = 1; z <= m; z++) {
          w[z].id = z;
          w[z].diff = -p[i].a[z] + p[j].b[z];
        }
        sort(w + 1, w + 1 + m);
        money = 0;
        kk = k;
        for (int z = 1; z <= m; z++) {
          int id = w[z].id;
          if (kk <= 0 || w[z].diff <= 0) break;
          money += min(kk, p[i].c[id]) * w[z].diff;
          kk -= min(kk, p[i].c[id]);
        }
        ans = max(ans, money);
      }
  if (ans < 0)
    cout << "0" << endl;
  else
    cout << ans << endl;
  return 0;
}
