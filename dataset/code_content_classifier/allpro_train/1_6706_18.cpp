#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, maxz, leftz, rightz, len;
  node() : l(-1), r(-1), maxz(0), leftz(0), rightz(0), len(0){};
} new_node;
int st_size, qst_size;
node st[100010 * 100], qst[100010];
vector<int> P;
int comb(node rf[], int cur) {
  rf[cur].leftz =
      rf[rf[cur].l].leftz +
      (rf[rf[cur].l].leftz == rf[rf[cur].l].len ? rf[rf[cur].r].leftz : 0);
  rf[cur].rightz =
      rf[rf[cur].r].rightz +
      (rf[rf[cur].r].rightz == rf[rf[cur].r].len ? rf[rf[cur].l].rightz : 0);
  rf[cur].maxz = max(max(rf[rf[cur].l].maxz, rf[rf[cur].r].maxz),
                     rf[rf[cur].l].rightz + rf[rf[cur].r].leftz);
  rf[cur].len = rf[rf[cur].l].len + rf[rf[cur].r].len;
  return cur;
}
int build(int b, int e) {
  int cur = st_size++;
  if (b + 1 < e) {
    int m = (b + e) >> 1;
    st[cur].l = build(b, m);
    st[cur].r = build(m, e);
  } else {
    st[cur].len = 1;
    return cur;
  }
  return comb(st, cur);
}
int update(int cur, int b, int e, int p) {
  st[st_size] = st[cur];
  cur = st_size++;
  if (e - b == 1) {
    st[cur].maxz = st[cur].leftz = st[cur].rightz = 1;
    return cur;
  }
  int m = (b + e) >> 1;
  if (p < m)
    st[cur].l = update(st[cur].l, b, m, p);
  else
    st[cur].r = update(st[cur].r, m, e, p);
  return comb(st, cur);
}
int query(int cur, int b, int e, int qb, int qe) {
  qst[qst_size] = st[cur];
  cur = qst_size++;
  if (b >= qb && e <= qe) return cur;
  int m = (b + e) >> 1;
  if (qb < m && m < qe) {
    qst[cur].l = query(qst[cur].l, b, m, qb, qe);
    qst[cur].r = query(qst[cur].r, m, e, qb, qe);
    return comb(qst, cur);
  }
  if (qb < m) return query(qst[cur].l, b, m, qb, qe);
  return query(qst[cur].r, m, e, qb, qe);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, q, w, A, B, h;
  vector<pair<int, int>> H;
  cin >> n;
  P.push_back(build(1, n + 1));
  for (int i = 1; i <= n; i++) {
    cin >> h;
    H.push_back({-h, i});
  }
  sort(H.begin(), H.end());
  for (auto p : H) P.push_back(update(P.back(), 1, n + 1, p.second));
  cin >> q;
  while (q--) {
    cin >> A >> B >> w;
    int b = 1, e = n;
    while (b < e) {
      for (int i = 0; i <= qst_size; i++) qst[i] = new_node;
      qst_size = 0;
      int m = (b + e) >> 1;
      if (qst[query(P[m], 1, n + 1, A, B + 1)].maxz < w)
        b = m + 1;
      else
        e = m;
    }
    cout << -H[b - 1].first << "\n";
  }
  return 0;
}
