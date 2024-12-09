#include <bits/stdc++.h>
const int maxn = 305;
const int inf = 0x7fffffff;
struct node {
  int data[maxn][maxn], n;
  node(int a = 0) : n(a) {}
  node operator*(const node &ot) {
    node ret(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret.data[i][j] = -inf;
        for (int h = 0; h < n; h++) {
          if (data[i][h] == -inf || ot.data[h][j] == -inf) continue;
          if (data[i][h] + ot.data[h][j] > ret.data[i][j])
            ret.data[i][j] = data[i][h] + ot.data[h][j];
        }
      }
    }
    return ret;
  }
} f, g;
int n, m;
node power(int a) {
  if (a == 1) return f;
  node t = power(a / 2);
  return a & 1 ? t * t * f : t * t;
}
void init() {
  scanf("%d%d", &n, &m);
  f.n = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) f.data[i][j] = (i != j) * (-inf);
  }
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    scanf("%d%d", &f.data[x][y], &f.data[y][x]);
  }
}
void work() {
  int ans = 0, lower = 2, upper = n;
  while (lower <= upper) {
    int mid = (lower + upper) >> 1, flag = 0;
    node t = power(mid);
    for (int i = 0; i < n; i++) {
      if (t.data[i][i] > 0) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      ans = mid;
      upper = mid - 1;
    } else
      lower = mid + 1;
  }
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
