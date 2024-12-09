#include <bits/stdc++.h>
const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};
const int N = (int)1e5 + 228;
const int inf = (int)1e9 + 228;
using namespace std;
struct Vertex {
  Vertex *l = NULL, *r = NULL;
  int val = 0;
  Vertex() {}
};
Vertex* t[N];
void upd(int x, Vertex* v, int tl, int tr) {
  if (tl == tr) {
    v->val++;
    return;
  }
  int mid = (tl + tr) >> 1;
  if (!v->l || !v->r) {
    v->l = new Vertex();
    v->r = new Vertex();
  }
  if (x <= mid)
    upd(x, v->l, tl, mid);
  else
    upd(x, v->r, mid + 1, tr);
  v->val = v->l->val + v->r->val;
}
int get(int l, int r, Vertex* v, int tl, int tr) {
  if (tl > r || tr < l) return 0;
  if (!v) return 0;
  if (tl >= l && tr <= r) return v->val;
  int mid = (tl + tr) >> 1;
  return get(l, r, v->l, tl, mid) + get(l, r, v->r, mid + 1, tr);
}
struct Robot {
  int x, r, q;
} a[N];
bool cmp(Robot x, Robot y) { return x.r < y.r; }
int n, m, k, b[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].q);
  for (int i = 1; i <= n; i++) b[++m] = a[i].q;
  sort(b + 1, b + m + 1);
  m = unique(b + 1, b + m + 1) - b - 1;
  for (int i = 1; i <= m; i++) t[i] = new Vertex();
  sort(a + 1, a + n + 1, &cmp);
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    int id = lower_bound(b + 1, b + m + 1, a[i].q) - b;
    for (int j = id; j <= m; j++) {
      if (b[j] > b[id] + k) break;
      ans +=
          get(max(0, a[i].x - a[i].r), min(inf, a[i].x + a[i].r), t[j], 0, inf);
    }
    for (int j = id - 1; j >= 1; j--) {
      if (b[j] < b[id] - k) break;
      ans +=
          get(max(0, a[i].x - a[i].r), min(inf, a[i].x + a[i].r), t[j], 0, inf);
    }
    upd(a[i].x, t[id], 0, inf);
  }
  cout << ans << endl;
  return 0;
}
