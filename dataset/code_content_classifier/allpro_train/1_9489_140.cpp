#include <bits/stdc++.h>
using namespace std;
const int maxn = 400005;
int N, M, h[maxn];
struct que {
  int id, pos, v;
  friend bool operator<(que a, que b) { return a.pos < b.pos; }
} q[maxn];
int g[maxn], _g[maxn], cnt, _cnt, ans[maxn], len, vis[maxn];
struct mlink {
  static const int max_sz = 400005;
  int np, w[maxn], first[maxn], next[maxn];
  mlink() {
    np = 0, w[0] = next[0] = 0;
    memset(first, 0, sizeof(first));
  }
  void ins(int i, int x) { w[++np] = x, next[np] = first[i], first[i] = np; }
  void del(int i) { first[i] = next[first[i]]; }
  int val(int i) { return w[first[i]]; }
} dd;
void _scanf(int &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
int out_cnt, out[15];
void _printf(int x) {
  out_cnt = 0;
  out[++out_cnt] = x % 10, x /= 10;
  while (x) out[++out_cnt] = x % 10, x /= 10;
  while (out_cnt) putchar('0' + out[out_cnt--]);
}
void data_in() {
  _scanf(N);
  _scanf(M);
  for (int i = 1; i <= N; i++) _scanf(h[i]);
  for (int i = 1; i <= M; i++) {
    _scanf(q[i].pos), _scanf(q[i].v);
    q[i].id = i;
  }
  sort(q + 1, q + M + 1);
}
bool cmp(int x, int y) { return x > y; }
void work() {
  for (int i = 1; i <= N; i++) {
    int j = lower_bound(q + 1, q + M + 1, (que){0, i, 0}) - q;
    while (j <= M && q[j].pos == i)
      ans[q[j].id] = lower_bound(g + 1, g + cnt + 1, q[j].v) - g, j++;
    int x = lower_bound(g + 1, g + cnt + 1, h[i]) - g;
    if (x > cnt) cnt = x;
    g[x] = h[i];
  }
  for (int i = N; i >= 1; i--) {
    int j = lower_bound(q + 1, q + M + 1, (que){0, i, 0}) - q;
    while (j <= M && q[j].pos == i)
      ans[q[j].id] += lower_bound(_g + 1, _g + _cnt + 1, q[j].v, cmp) - _g - 1,
          j++;
    int x = lower_bound(_g + 1, _g + _cnt + 1, h[i], cmp) - _g;
    if (x > _cnt) _cnt = x;
    _g[x] = h[i];
    dd.ins(x, _g[x]);
  }
  memset(g, 0, sizeof(g));
  len = cnt, cnt = 0;
  int x = lower_bound(_g + 1, _g + _cnt + 1, h[1], cmp) - _g, sum = 0;
  dd.del(x);
  _g[x] = dd.val(x);
  if (_g[len]) vis[0] = 1, sum++;
  for (int i = 1; i <= N; i++) {
    int j = lower_bound(q + 1, q + M + 1, (que){0, i, 0}) - q;
    while (j <= M && q[j].pos == i)
      ans[q[j].id] = max(ans[q[j].id], len - (sum == 0)), j++;
    int x1 = lower_bound(g + 1, g + cnt + 1, h[i]) - g;
    if (x1 > cnt) cnt = x1;
    g[x1] = h[i];
    int x2 = lower_bound(_g + 1, _g + _cnt + 1, h[i + 1], cmp) - _g;
    dd.del(x2);
    _g[x2] = dd.val(x2);
    if (!_g[x2]) _cnt--;
    if ((x1 == len || g[x1] < _g[len - x1]) && !vis[x1]) vis[x1] = 1, sum++;
    if (g[len - x2] >= _g[x2] && vis[len - x2]) vis[len - x2] = 0, sum--;
  }
  for (int i = 1; i <= M; i++) _printf(ans[i]), putchar('\n');
}
int main() {
  data_in();
  work();
  return 0;
}
