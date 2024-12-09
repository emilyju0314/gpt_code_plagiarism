#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int l[200010], r[200010], s[800010];
struct SEG_Tree {
  struct SEG {
    int l;
    int r;
    int sum;
    bool ls;
    bool rs;
    bool lazy;
  } t[4000000];
  void push_up(int cur) {
    t[cur].sum = t[((cur) << 1)].sum + t[((cur) << 1 | 1)].sum;
    t[cur].ls = t[((cur) << 1)].ls;
    t[cur].rs = t[((cur) << 1 | 1)].rs;
    if (t[((cur) << 1)].rs && t[((cur) << 1 | 1)].ls) t[cur].sum--;
  }
  void push_down(int cur) {
    if (t[cur].lazy) {
      t[((cur) << 1)].sum = t[((cur) << 1 | 1)].sum = 1;
      t[((cur) << 1)].ls = t[((cur) << 1 | 1)].ls = t[((cur) << 1)].rs =
          t[((cur) << 1 | 1)].rs = true;
      t[((cur) << 1)].lazy = t[((cur) << 1 | 1)].lazy = true;
      t[cur].lazy = false;
    }
  }
  void build(int cur, int l, int r) {
    t[cur].l = l;
    t[cur].r = r;
    t[cur].sum = 0;
    t[cur].ls = t[cur].rs = false;
    t[cur].lazy = false;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(((cur) << 1), l, mid);
    build(((cur) << 1 | 1), mid + 1, r);
  }
  void modify(int cur, int l, int r) {
    if (t[cur].l > r || t[cur].r < l) return;
    if (t[cur].l >= l && t[cur].r <= r) {
      t[cur].sum = 1;
      t[cur].ls = t[cur].rs = true;
      t[cur].lazy = true;
      return;
    }
    push_down(cur);
    modify(((cur) << 1), l, r);
    modify(((cur) << 1 | 1), l, r);
    push_up(cur);
  }
} t;
int main() {
  int n = inp();
  for (int i = 1; i <= n; i++) {
    l[i] = inp();
    r[i] = inp() - 1;
    s[(i << 2) - 3] = l[i] - 1;
    s[(i << 2) - 2] = l[i];
    s[(i << 2) - 1] = r[i];
    s[i << 2] = r[i] + 1;
  }
  std::sort(s + 1, s + (n << 2) + 1);
  int cnt = std::unique(s + 1, s + (n << 2) + 1) - s - 1;
  t.build(1, 1, cnt);
  for (int i = 1; i <= n; i++) {
    l[i] = std::lower_bound(s + 1, s + cnt + 1, l[i]) - s;
    r[i] = std::lower_bound(s + 1, s + cnt + 1, r[i]) - s;
    if (l[i] <= r[i]) t.modify(1, l[i], r[i]);
    printf("%d ", t.t[1].sum);
  }
  putchar('\n');
}
