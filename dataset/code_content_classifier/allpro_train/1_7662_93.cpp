#include <bits/stdc++.h>
using namespace std;
const long long N = 200005LL;
long long lazy[6 * N], st[6 * N], a[N];
int n, m;
void unlazy(int id, int l, int r) {
  if (lazy[id]) {
    st[id] += lazy[id];
    if (l != r) {
      lazy[id << 1] += lazy[id];
      lazy[id << 1 | 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}
void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  long long mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  st[id] = min(st[id << 1], st[id << 1 | 1]);
}
void update(int id, int l, int r, int u, int v, long long vl) {
  unlazy(id, l, r);
  if (l > v || r < u) return;
  if (l >= u && r <= v) {
    lazy[id] += vl;
    unlazy(id, l, r);
    return;
  }
  long long mid = (l + r) >> 1;
  update(id << 1, l, mid, u, v, vl);
  update(id << 1 | 1, mid + 1, r, u, v, vl);
  st[id] = min(st[id << 1], st[id << 1 | 1]);
}
long long get(int id, int l, int r, int u, int v) {
  unlazy(id, l, r);
  if (l > v || r < u) return 1000000000;
  if (l >= u && r <= v) return st[id];
  long long mid = (l + r) >> 1;
  return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", a + i);
  build(1, 0, n - 1);
  scanf("%d", &m);
  while (m--) {
    int u, v;
    long long vl;
    scanf("%d %d", &u, &v);
    char c;
    scanf("%c", &c);
    if (c == '\n') {
      if (u <= v)
        printf("%I64d\n", get(1, 0, n - 1, u, v));
      else {
        long long A = get(1, 0, n - 1, u, n - 1);
        long long B = get(1, 0, n - 1, 0, v);
        printf("%I64d\n", min(A, B));
      }
    } else {
      scanf("%I64d", &vl);
      if (u <= v) {
        update(1, 0, n - 1, u, v, vl);
      } else {
        update(1, 0, n - 1, u, n - 1, vl);
        update(1, 0, n - 1, 0, v, vl);
      }
    }
  }
  return 0;
}
