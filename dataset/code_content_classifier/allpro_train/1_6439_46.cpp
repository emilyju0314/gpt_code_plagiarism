#include <bits/stdc++.h>
using namespace std;
int a[100000];
int last;
int n;
int ans;
int f[1000010];
int cur;
struct node {
  node *pre, *nxt;
  int v;
  void del() {
    pre->nxt = nxt;
    nxt->pre = pre;
  }
};
int val[100000];
node x[1000010], head, tail;
int st, ed;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  n = unique(a, a + n) - a;
  scanf("%d%d", &ed, &st);
  for (int i = 0; i < n; ++i) x[i].v = a[i];
  for (int i = 0; i < n - 1; ++i) x[i].nxt = x + i + 1;
  for (int i = 1; i < n; ++i) x[i].pre = x + i - 1;
  x[0].pre = &head;
  head.nxt = x;
  x[n - 1].nxt = &tail;
  tail.pre = x + n - 1;
  int ans = 0;
  while (ed != st) {
    int gap = ed - st;
    int tmp = 1;
    ++ans;
    node *p = tail.pre;
    while (p != &head) {
      if (p->v <= tmp) break;
      int next = ed % p->v;
      if (next > gap)
        p->del();
      else if (next > tmp)
        tmp = next;
      p = p->pre;
    }
    ed -= tmp;
  }
  printf("%d\n", ans);
}
