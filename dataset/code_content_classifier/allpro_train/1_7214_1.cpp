#include <bits/stdc++.h>
const int N = 5010, M = 200010;
int tf = 0, tt = 0, b[N], k[N], h[N], x[N], y[N], m[N];
struct data {
  int w, d, x;
} a[M], last[M], f[N], t[N];
void swap(data &a, data &b) {
  data temp = a;
  a = b;
  b = temp;
}
void up() {
  f[0] = f[tf];
  int i = tf, k = i / 2;
  while (k >= 1) {
    if (f[k].w <= f[0].w) break;
    f[i] = f[k];
    i = k;
    k = i / 2;
  }
  f[i] = f[0];
}
void down() {
  f[0] = f[1];
  int i = 1, k = i * 2;
  while (k <= tf) {
    if (k < tf && f[k].w > f[k + 1].w) k++;
    if (f[k].w >= f[0].w) break;
    f[i] = f[k];
    i = k;
    k = i * 2;
  }
  f[i] = f[0];
}
void add(data t) {
  tf++;
  f[tf] = t;
  up();
}
void del() {
  swap(f[1], f[tf]);
  tf--;
  down();
}
int main() {
  int n, sum = 0, pos = 0, s, i, j, ans = 0;
  long long temp, temp2;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d %d %d %d", &k[i], &h[i], &x[i], &y[i], &m[i]);
    sum += k[i];
  }
  for (i = 1; i <= n; i++) {
    temp = h[i];
    s = 0;
    for (j = 1; j <= k[i]; j++) {
      if (sum <= 200000) {
        pos++;
        a[pos].w = temp;
        a[pos].d = i;
        a[pos].x = j;
        if (j == 1) b[i] = pos;
      }
      if (j < k[i]) {
        temp2 = (temp * x[i] + y[i]) % m[i];
        if (temp > temp2) s++;
        temp = temp2;
      }
    }
    if (ans < s) ans = s;
  }
  printf("%d\n", ans);
  if (sum <= 200000) {
    for (i = 1; i <= n; i++) add(a[b[i]]);
    s = 0;
    while (s < sum) {
      while (tf > 0) {
        s++;
        last[s] = f[1];
        del();
        if (last[s].x < k[last[s].d]) {
          int temp = b[last[s].d] + last[s].x;
          if (last[s].w <= a[temp].w)
            add(a[temp]);
          else {
            tt++;
            t[tt] = a[temp];
          }
        }
      }
      if (tt > 0) {
        for (i = 1; i <= tt; i++) add(t[i]);
        tt = 0;
      }
    }
    for (i = 1; i <= sum; i++) printf("%d %d\n", last[i].w, last[i].d);
  }
  return (0);
}
