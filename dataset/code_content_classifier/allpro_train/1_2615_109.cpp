#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const int maxn = 3e5 + 5, N = 1e6 + 5, SQ = 55, base = 879169, mod = 1e9 + 7,
          INF = 1e9 + 5, lg = 20;
const long double eps = 1e-4;
struct node {
  int mn = INF, lz = 0;
  int c1 = 0, c2 = 0;
};
node seg[4 * maxn];
int n, p[maxn], pos[maxn], q[maxn];
inline void shift(int v) {
  seg[2 * v].mn += seg[v].lz;
  seg[2 * v + 1].mn += seg[v].lz;
  seg[2 * v].lz += seg[v].lz;
  seg[2 * v + 1].lz += seg[v].lz;
  seg[v].lz = 0;
}
void add(int l, int r, int x, int v = 1, int s = 0, int e = n) {
  if (l >= e || s >= r) {
    return;
  }
  if (l <= s && e <= r) {
    seg[v].mn += x;
    seg[v].lz += x;
    return;
  }
  shift(v);
  add(l, r, x, 2 * v, s, (s + e) / 2);
  add(l, r, x, 2 * v + 1, (s + e) / 2, e);
  seg[v].mn = min(seg[2 * v].mn, seg[2 * v + 1].mn);
}
pair<int, int> get(int l, int r, int v = 1, int s = 0, int e = n) {
  if (l >= e || s >= r) {
    return {0, 0};
  }
  if (l <= s && e <= r) {
    return {seg[v].c1, seg[v].c2};
  }
  shift(v);
  pair<int, int> a = get(l, r, 2 * v, s, (s + e) / 2);
  pair<int, int> b = get(l, r, 2 * v + 1, (s + e) / 2, e);
  return {a.first + b.first, a.second + b.second};
}
void modify_num(int p, int x, int v = 1, int s = 0, int e = n) {
  seg[v].c2++;
  seg[v].mn = min(seg[v].mn, x);
  if (e - s == 1) {
    return;
  }
  shift(v);
  if (p < (s + e) / 2) {
    modify_num(p, x, 2 * v, s, (s + e) / 2);
    return;
  }
  modify_num(p, x, 2 * v + 1, (s + e) / 2, e);
}
void modify_bomb(int p, int v = 1, int s = 0, int e = n) {
  seg[v].c1++;
  if (e - s == 1) {
    return;
  }
  shift(v);
  if (p < (s + e) / 2) {
    modify_bomb(p, 2 * v, s, (s + e) / 2);
    return;
  }
  modify_bomb(p, 2 * v + 1, (s + e) / 2, e);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
  }
  for (int i = 0; i < n; ++i) {
    p[i]--, q[i]--;
    pos[p[i]] = i;
  }
  int ans = n - 1;
  for (int i = 0; i < n; ++i) {
    while (ans) {
      add(0, pos[ans], -1);
      pair<int, int> res = get(pos[ans], n);
      if (res.first < res.second + 1 || seg[1].mn <= 0) {
        add(0, pos[ans], 1);
        break;
      }
      modify_num(pos[ans], res.first - res.second);
      ans--;
    }
    cout << ans + 1 << ' ';
    modify_bomb(q[i]);
    add(0, q[i] + 1, 1);
  }
  cout << '\n';
}
