#include <bits/stdc++.h>
using namespace std;
int n, r, ans = 0x7fffffff;
bool flag = false;
int re[1000010], rex[1000010], num[1000010], cnt[1000010], tot, ct;
void cal() {
  int x = 0;
  for (int i = 1; i <= ct; i++) {
    x += rex[i];
  }
  if (x != n) return;
  int err = 0;
  int pos = n - x;
  reverse(re + 1, re + ct + 1);
  reverse(rex + 1, rex + ct + 1);
  if (re[1] != 0) return;
  for (int i = 1; i <= ct; i++) {
    err += (rex[i] - 1);
  }
  if (err < ans) {
    flag = true;
    ans = err;
    tot = 0;
    for (int i = 1; i <= ct; i++) {
      cnt[++tot] = re[i];
      num[tot] = rex[i];
    }
  }
}
void solve(int x, int y) {
  if (y == 0) return;
  if (x == y) {
    if (y != 1) return;
  }
  if (x == 0) {
    if (y != 1) return;
    cal();
    return;
  }
  if (x == 1) {
    if (y == 1) {
      re[++ct] = 0;
      rex[ct] = 1;
      solve(0, 1);
    } else {
      re[++ct] = 1;
      rex[ct] = y / x - 1;
      solve(1, 1);
    }
  } else if (x > y) {
    re[++ct] = 0;
    rex[ct] = x / y;
    solve(x % y, y);
  } else {
    re[++ct] = 1;
    rex[ct] = y / x;
    solve(x, y % x);
  }
}
int main() {
  tot = 0;
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= r; i++) {
    ct = 0;
    solve(i, r);
    ct = 0;
    solve(r, i);
  }
  if (!flag) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= tot; i++) {
    for (int j = 1; j <= num[i]; j++) {
      if (cnt[i] == 0)
        printf("T");
      else
        printf("B");
    }
  }
  printf("\n");
  return 0;
}
