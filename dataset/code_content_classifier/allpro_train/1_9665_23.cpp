#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int h[20], p[1000], res[1000];
int ans = 1e9;
void attack(int &a, int &b, int &c) {
  a -= y;
  if (a < 0) a = 0;
  b -= x;
  if (b < 0) b = 0;
  c -= y;
  if (c < 0) c = 0;
}
void go(int cur, int a, int b, int c, int lvl) {
  if (lvl >= ans) return;
  if (cur == n) {
    if (a + b + c == 0) {
      ans = lvl;
      for (int i = 0; i < ans; i++) res[i] = p[i];
    }
    return;
  }
  while (a > 0) {
    attack(a, b, c);
    p[lvl++] = cur;
  }
  go(cur + 1, b, c, h[cur + 2], lvl);
  while (b + c > 0) {
    attack(a, b, c);
    p[lvl++] = cur;
    go(cur + 1, b, c, h[cur + 2], lvl);
  }
}
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
    h[i]++;
  }
  go(2, h[1], h[2], h[3], 0);
  printf("%d\n", ans);
  for (int i = 0; i < ans; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
  return 0;
}
