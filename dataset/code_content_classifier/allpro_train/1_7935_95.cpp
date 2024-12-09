#include <bits/stdc++.h>
using namespace std;
struct tree {
  int l, r, s;
  tree(int l = 0, int r = 0, int s = 0) : l(l), r(r), s(s) {}
};
int N, Q, a[300010], T, rt[300010];
tree t[7000000];
int upd(int nod, int l, int r, int p) {
  tree &cr = t[++T];
  cr = t[nod];
  if (l == r) {
    cr.s++;
    cr.l = cr.r = 0;
    return T;
  }
  int mid = (l + r) / 2, id = T;
  if (p <= mid)
    cr.l = upd(t[nod].l, l, mid, p);
  else
    cr.r = upd(t[nod].r, mid + 1, r, p);
  cr.s = t[cr.l].s + t[cr.r].s;
  return id;
}
int query(int nod, int l, int r, int ql, int qr) {
  if (nod == 0) return 0;
  if (ql <= l && r <= qr) return t[nod].s;
  int mid = (l + r) / 2, res = 0;
  if (ql <= mid) res += query(t[nod].l, l, mid, ql, qr);
  if (mid < qr) res += query(t[nod].r, mid + 1, r, ql, qr);
  return res;
}
int find_kth(int p, int q, int l, int r, int k) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  int totl = (t[t[p].l].s - t[t[q].l].s);
  if (totl >= k)
    return find_kth(t[p].l, t[q].l, l, mid, k);
  else
    return find_kth(t[p].r, t[q].r, mid + 1, r, k - totl);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  srand(time(NULL));
  int i, l, r, k;
  for (i = 1; i <= N; i++) {
    cin >> a[i];
    rt[i] = upd(rt[i - 1], 1, N, a[i]);
  }
  while (Q--) {
    cin >> l >> r >> k;
    int nr = -1, len = max((r - l + 1) / k, 1);
    for (i = 0; i <= r - l; i += len) {
      int x = find_kth(rt[r], rt[l - 1], 1, N, i + 1);
      int cnt = query(rt[r], 1, N, x, x) - query(rt[l - 1], 1, N, x, x);
      if (k * cnt > r - l + 1 && (nr == -1 || x < nr)) nr = x;
    }
    cout << nr << "\n";
  }
  return 0;
}
