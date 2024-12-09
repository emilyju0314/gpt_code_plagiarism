#include <bits/stdc++.h>
using namespace std;
int ara[1200][1200], collef[1200][1200], colright[1200][1200], stup[1200][1200],
    stdown[1200][1200], n, m;
void pre() {
  int my;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      if (ara[i][j] == 0)
        my = j;
      else
        collef[i][j] = my;
    }
    for (int j = m + 1; j >= 0; j--) {
      if (ara[i][j] == 0)
        my = j;
      else
        colright[i][j] = my;
    }
  }
  for (int j = 0; j <= m + 1; j++) {
    for (int i = 0; i <= n + 1; i++) {
      if (ara[i][j] == 0) {
        my = i;
      } else
        stup[i][j] = my;
    }
    for (int i = n + 1; i >= 0; i--) {
      if (ara[i][j] == 0)
        my = i;
      else
        stdown[i][j] = my;
    }
  }
}
void takecare(int v, int w) {
  int my;
  ara[v][w] ^= 1;
  for (int i = 0; i <= m; i++) {
    if (ara[v][i] == 0)
      my = i;
    else
      collef[v][i] = my;
  }
  for (int i = 0; i <= n; i++) {
    if (ara[i][w] == 0) {
      my = i;
    } else
      stup[i][w] = my;
  }
  for (int i = m + 1; i >= 1; i--) {
    if (ara[v][i] == 0)
      my = i;
    else
      colright[v][i] = my;
  }
  for (int i = n + 1; i >= 0; i--) {
    if (ara[i][w] == 0)
      my = i;
    else
      stdown[i][w] = my;
  }
}
int nicherdike(int v, int w) {
  int ans = 0, l;
  int mi = 0, ma = m + 1;
  for (int i = v; i <= n; i++) {
    if (ara[i][w] == 0) break;
    mi = max(mi, collef[i][w]);
    ma = min(ma, colright[i][w]);
    l = (((ma - 1) - (mi + 1)) + 1) * (i - v + 1);
    ans = max(ans, l);
  }
  return ans;
}
int uporerdike(int v, int w) {
  int ans = 0, l;
  int mi = 0, ma = m + 1;
  for (int i = v; i >= 1; i--) {
    if (ara[i][w] == 0) break;
    mi = max(mi, collef[i][w]);
    ma = min(ma, colright[i][w]);
    l = (((ma - 1) - (mi + 1)) + 1) * (v - i + 1);
    ans = max(ans, l);
  }
  return ans;
}
int bamerdike(int v, int w) {
  int ans = 0, l;
  int mi = 0, ma = n + 1;
  for (int i = w; i >= 1; i--) {
    if (ara[v][i] == 0) break;
    mi = max(mi, stup[v][i]);
    ma = min(ma, stdown[v][i]);
    l = (((ma - 1) - (mi + 1)) + 1) * (w - i + 1);
    ans = max(ans, l);
  }
  return ans;
}
int danerdike(int v, int w) {
  int ans = 0, l;
  int mi = 0, ma = n + 1;
  for (int i = w; i <= m; i++) {
    if (ara[v][i] == 0) break;
    mi = max(mi, stup[v][i]);
    ma = min(ma, stdown[v][i]);
    l = (((ma - 1) - (mi + 1)) + 1) * (i - w + 1);
    ans = max(ans, l);
  }
  return ans;
}
int main() {
  int i, j, k, l, q, op, ma;
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &ara[i][j]);
    }
  }
  pre();
  while (q--) {
    scanf("%d", &op);
    if (op == 1) {
      cin >> l >> k;
      takecare(l, k);
      continue;
    }
    scanf("%d%d", &l, &k);
    ma = nicherdike(l, k);
    ma = max(ma, uporerdike(l, k));
    ma = max(ma, danerdike(l, k));
    ma = max(ma, bamerdike(l, k));
    printf("%d\n", ma);
  }
}
