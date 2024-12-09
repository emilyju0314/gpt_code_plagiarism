#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const int maxn = 1e5 + 10, maxm = 5e2 + 10, lg = 18, mod = 1e9 + 7, inf = 1e18;
int n, q;
string second;
struct node {
  int pre[2], suf[2], pre2[2], suf2[2], ans[2], len;
  bool laz = 0;
} seg[1 << 20];
node mrg(node l, node r) {
  node ret;
  for (int j : {0, 1}) {
    ret.pre[j] = (l.pre[j] == l.len ? l.len + r.pre[j] : l.pre[j]);
    ret.suf[j] = (r.suf[j] == r.len ? r.len + l.suf[j] : r.suf[j]);
    ret.pre2[j] = (l.suf[j] == l.len
                       ? l.len + r.pre2[j]
                       : (l.pre2[j] == l.len ? l.len + r.pre[j] : l.pre2[j]));
    ret.suf2[j] = (r.pre[j] == r.len
                       ? r.len + l.suf2[j]
                       : (r.suf2[j] == r.len ? r.len + l.suf[j] : r.suf2[j]));
    ret.ans[j] =
        max({l.ans[j], r.ans[j], l.suf2[j] + r.pre[j], l.suf[j] + r.pre2[j]});
  }
  ret.len = l.len + r.len;
  return ret;
}
void app(int v, bool b) {
  if (b) {
    swap(seg[v].pre[0], seg[v].pre[1]);
    swap(seg[v].suf[0], seg[v].suf[1]);
    swap(seg[v].pre2[0], seg[v].pre2[1]);
    swap(seg[v].suf2[0], seg[v].suf2[1]);
    swap(seg[v].ans[0], seg[v].ans[1]);
  }
  seg[v].laz ^= b;
}
void shift(int v) {
  if (!seg[v].laz) return;
  app((v << 1), 1);
  app(((v << 1) ^ 1), 1);
  seg[v].laz = 0;
}
void bild(int s = 0, int t = n - 1, int v = 1) {
  if (s == t) {
    int cc = (second[s] != '<');
    seg[v].pre[cc] = seg[v].suf[cc ^ 1] = 1;
    for (int j : {0, 1}) seg[v].pre2[j] = seg[v].suf2[j] = seg[v].ans[j] = 1;
    seg[v].len = 1;
    return;
  }
  bild(s, ((s + t) >> 1), (v << 1));
  bild(((s + t) >> 1) + 1, t, ((v << 1) ^ 1));
  seg[v] = mrg(seg[(v << 1)], seg[((v << 1) ^ 1)]);
}
node get(int l, int r, int s = 0, int t = n - 1, int v = 1) {
  if (l <= s && r >= t) return app(v, 1), seg[v];
  shift(v);
  node ret;
  if (r <= ((s + t) >> 1))
    ret = get(l, r, s, ((s + t) >> 1), (v << 1));
  else if (((s + t) >> 1) < l)
    ret = get(l, r, ((s + t) >> 1) + 1, t, ((v << 1) ^ 1));
  else
    ret = mrg(get(l, r, s, ((s + t) >> 1), (v << 1)),
              get(l, r, ((s + t) >> 1) + 1, t, ((v << 1) ^ 1)));
  seg[v] = mrg(seg[(v << 1)], seg[((v << 1) ^ 1)]);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q >> second;
  bild();
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << get(--l, --r).ans[0] << "\n";
  }
  return 0;
}
