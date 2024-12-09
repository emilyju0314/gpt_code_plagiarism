#include <bits/stdc++.h>
using namespace std;
const int MAX = 300005;
const int inf = 999999999;
int rec[MAX][3];
string a;
int n, m, ans;
int fa[MAX << 1], cnt[MAX << 1];
int father(int x) { return x == fa[x] ? x : fa[x] = father(fa[x]); }
void merge(int x, int y) {
  x = father(x), y = father(y);
  if (x == y) return;
  fa[x] = y;
  cnt[y] += cnt[x];
}
int choose(int x) { return min(cnt[father(x)], cnt[father(x + m)]); }
int main() {
  scanf("%d %d", &n, &m);
  cin >> a, a = " " + a;
  for (int x, i = 1; i <= m; i++) {
    scanf("%d", &x);
    for (int y, j = 1; j <= x; j++) {
      scanf("%d", &y);
      rec[y][++rec[y][0]] = i;
    }
  }
  for (int i = 1; i <= 2 * m; i++) fa[i] = i, cnt[i] = (i > m);
  cnt[0] = inf;
  for (int i = 1; i <= n; i++) {
    if (rec[i][0] == 1) {
      int x = rec[i][1] + (a[i] == '1') * m;
      ans -= choose(rec[i][1]), merge(x, 0), ans += choose(rec[i][1]);
    } else if (rec[i][0] == 2) {
      if (a[i] == '1') {
        if (father(rec[i][1]) != father(rec[i][2])) {
          ans -= choose(rec[i][1]), ans -= choose(rec[i][2]);
          merge(rec[i][1], rec[i][2]), merge(rec[i][1] + m, rec[i][2] + m);
          ans += choose(rec[i][1]);
        }
      } else {
        if (father(rec[i][1]) != father(rec[i][2] + m)) {
          ans -= choose(rec[i][1]), ans -= choose(rec[i][2]);
          merge(rec[i][1], rec[i][2] + m), merge(rec[i][1] + m, rec[i][2]);
          ans += choose(rec[i][1]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
