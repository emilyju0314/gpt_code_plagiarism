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
struct SEG_Tree {
  struct SEG {
    int l;
    int r;
    int min;
    long long sum;
    long long ans;
    int lazy;
    long long lazy2;
  } t[5000010];
  void push_up(int cur) {
    t[cur].min = std::min(t[((cur) << 1)].min, t[((cur) << 1 | 1)].min);
    t[cur].sum = 0;
    if (t[cur].min == t[((cur) << 1)].min) t[cur].sum += t[((cur) << 1)].sum;
    if (t[cur].min == t[((cur) << 1 | 1)].min)
      t[cur].sum += t[((cur) << 1 | 1)].sum;
  }
  void push_down(int cur) {
    t[((cur) << 1)].min += t[cur].lazy;
    t[((cur) << 1 | 1)].min += t[cur].lazy;
    t[((cur) << 1)].lazy += t[cur].lazy;
    t[((cur) << 1 | 1)].lazy += t[cur].lazy;
    t[cur].lazy = 0;
    if (t[cur].min == t[((cur) << 1)].min) {
      t[((cur) << 1)].ans += t[((cur) << 1)].sum * t[cur].lazy2;
      t[((cur) << 1)].lazy2 += t[cur].lazy2;
    }
    if (t[cur].min == t[((cur) << 1 | 1)].min) {
      t[((cur) << 1 | 1)].ans += t[((cur) << 1 | 1)].sum * t[cur].lazy2;
      t[((cur) << 1 | 1)].lazy2 += t[cur].lazy2;
    }
    t[cur].lazy2 = 0;
  }
  void build(int cur, int l, int r) {
    t[cur].l = l;
    t[cur].r = r;
    if (l == r) {
      t[cur].min = l;
      t[cur].sum = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(((cur) << 1), l, mid);
    build(((cur) << 1 | 1), mid + 1, r);
    push_up(cur);
  }
  void modify(int cur, int l, int r, int c) {
    if (t[cur].l > r || t[cur].r < l) return;
    if (t[cur].l >= l && t[cur].r <= r) {
      t[cur].min += c;
      t[cur].lazy += c;
      return;
    }
    push_down(cur);
    modify(((cur) << 1), l, r, c);
    modify(((cur) << 1 | 1), l, r, c);
    push_up(cur);
  }
  long long query(int cur, int l, int r) {
    if (t[cur].l > r || t[cur].r < l) return 0;
    if (t[cur].l >= l && t[cur].r <= r) return t[cur].ans;
    push_down(cur);
    return query(((cur) << 1), l, r) + query(((cur) << 1 | 1), l, r);
  }
} t;
std::vector<std::pair<int, int> > vec[1200010];
long long ans[1200010];
int a[1200010], s1[1200010], s2[1200000];
signed main() {
  int n = inp();
  for (int i = 1; i <= n; i++) a[i] = inp();
  int q = inp();
  for (int i = 1; i <= q; i++) {
    int l = inp();
    int r = inp();
    vec[r].push_back(std::make_pair(l, i));
  }
  int top1 = 0, top2 = 0;
  t.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    t.modify(1, 1, n, -1);
    while (top1 && a[s1[top1]] > a[i]) {
      t.modify(1, s1[top1 - 1] + 1, s1[top1], a[s1[top1]] - a[i]);
      top1--;
    }
    s1[++top1] = i;
    while (top2 && a[s2[top2]] < a[i]) {
      t.modify(1, s2[top2 - 1] + 1, s2[top2], a[i] - a[s2[top2]]);
      top2--;
    }
    s2[++top2] = i;
    t.t[1].ans += t.t[1].sum;
    t.t[1].lazy2++;
    for (int j = 0; j < vec[i].size(); j++)
      ans[vec[i][j].second] = t.query(1, vec[i][j].first, i);
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
