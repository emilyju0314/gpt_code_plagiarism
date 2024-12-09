#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, op = 1;
  while (ch < '0' || '9' < ch) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return op * x;
}
const int maxn = 200009;
const int MOD = 1000000007;
struct segment {
  int u, l, r, s;
  bool operator<(const segment &a) const { return u < a.u; }
} a[maxn];
vector<int> del[maxn];
set<int> T[maxn << 2];
int h, w, n, L[maxn], R[maxn], cnt[maxn];
int search(int x) {
  int l = 1, r = n, Mid;
  while (l < r) {
    Mid = (l + r + 1) >> 1;
    if (a[Mid].u <= x)
      l = Mid;
    else
      r = Mid - 1;
  }
  return l;
}
void add(int &a, int b) { a = (a + b) % MOD; }
void update(int o, int l, int r, int x, int y, int z) {
  if (l == x && y == r) {
    if (z > 0)
      T[o].insert(z);
    else
      T[o].erase(-z);
    return;
  }
  if (x <= ((l + r) >> 1))
    update((o << 1), l, ((l + r) >> 1), x, min(y, ((l + r) >> 1)), z);
  if (((l + r) >> 1) + 1 <= y)
    update((o << 1 | 1), ((l + r) >> 1) + 1, r, max(x, ((l + r) >> 1) + 1), y,
           z);
}
int query(int o, int l, int r, int x) {
  if (l == r) return T[o].empty() ? 0 : *(--T[o].end());
  int res = T[o].empty() ? 0 : *(--T[o].end());
  if (x <= ((l + r) >> 1))
    return max(res, query((o << 1), l, ((l + r) >> 1), x));
  return max(res, query((o << 1 | 1), ((l + r) >> 1) + 1, r, x));
}
int main() {
  h = read();
  w = read();
  n = read();
  for (int i = (1); i <= (n); i++) {
    a[i].u = read();
    a[i].l = read();
    a[i].r = read();
    a[i].s = read();
  }
  a[++n].u = 0;
  a[n].l = 1, a[n].r = w;
  a[n].s = h + 1;
  sort(a + 1, a + n + 1);
  for (int i = (1); i <= (n); i++) {
    if (a[i].l != 1) L[i] = query(1, 1, w, a[i].l - 1);
    if (a[i].r != w) R[i] = query(1, 1, w, a[i].r + 1);
    update(1, 1, w, a[i].l, a[i].r, i);
    if (a[i].u + a[i].s <= h) del[search(a[i].u + a[i].s)].push_back(i);
    while (!del[i].empty()) {
      update(1, 1, w, a[del[i].back()].l, a[del[i].back()].r, -del[i].back());
      del[i].pop_back();
    }
  }
  for (int i = (1); i <= (w); i++) cnt[query(1, 1, w, i)]++;
  for (int i = (n); i >= (2); i--) {
    if (!L[i])
      add(cnt[R[i]], 2 * cnt[i] % MOD);
    else if (!R[i])
      add(cnt[L[i]], 2 * cnt[i] % MOD);
    else {
      add(cnt[R[i]], cnt[i]);
      add(cnt[L[i]], cnt[i]);
    }
  }
  printf("%d\n", cnt[1]);
  return 0;
}
