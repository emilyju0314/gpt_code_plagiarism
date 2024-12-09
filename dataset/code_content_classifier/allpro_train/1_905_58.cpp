#include <bits/stdc++.h>
using namespace std;
struct node {
  int fa, tot;
} a[100001];
struct node1 {
  int num, ind;
  bool operator<(node1 b) const { return num > b.num; }
} c[100001];
int b[100001], v[100001], e[300001][2];
bool used[100001], inlist[100001];
int q[100001];
int getfather(int o) {
  if (a[o].fa == o) return o;
  a[o].fa = getfather(a[o].fa);
  return a[o].fa;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    c[i].num = b[i];
    c[i].ind = i;
    a[i].fa = i;
    a[i].tot = 1;
  }
  sort(c + 1, c + 1 + n);
  int tot = 0;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    tot++;
    e[tot][0] = x;
    e[tot][1] = v[y];
    v[y] = tot;
    tot++;
    e[tot][0] = y;
    e[tot][1] = v[x];
    v[x] = tot;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = c[i].ind;
    used[x] = true;
    q[0] = 0;
    int p = v[x], num = 0;
    while (p) {
      int y = getfather(e[p][0]);
      if ((!inlist[y]) && (used[y])) {
        q[++q[0]] = y;
        num += a[y].tot;
        inlist[y] = true;
      }
      p = e[p][1];
    }
    ans += (long long)(num) * (long long)(b[x] * 2);
    for (int j = 1; j <= q[0]; j++) {
      int y = q[j];
      inlist[y] = false;
      ans += (long long)(b[x]) * (long long)(num - a[y].tot) *
             (long long)(a[y].tot);
      a[x].tot += a[y].tot;
      a[y].tot = 0;
      a[y].fa = x;
    }
  }
  double ansreal = ans;
  ansreal /= (double)(n);
  ansreal /= (double)(n - 1);
  printf("%.4f\n", ansreal);
  return 0;
}
