#include <bits/stdc++.h>
using namespace std;
constexpr int inf32 = 0x3f3f3f3f;
constexpr long long inf64 = 0x3f3f3f3f3f3f3f3f;
pair<long long, long long> operator+(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  return pair<long long, long long>(a.first + b.first, a.second + b.second);
}
pair<long long, long long> operator-(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  return pair<long long, long long>(a.first - b.first, a.second - b.second);
}
struct node {
  pair<long long, long long> key;
  node *ls, *rs;
  node() {}
  node(pair<long long, long long> key, node *ls, node *rs)
      : key(key), ls(ls), rs(rs) {}
};
node *my0;
void node_init() {
  my0 = new node();
  my0->ls = my0->rs = my0;
}
node *add(node *u, int i, pair<long long, long long> k, int l, int r) {
  if (r <= i || i < l) return u;
  assert(u != nullptr);
  node *v = new node(u->key + k, my0, my0);
  if (r - l == 1) return v;
  v->ls = add(u->ls, i, k, l, (l + r >> 1));
  v->rs = add(u->rs, i, k, (l + r >> 1), r);
  return v;
}
pair<long long, long long> get(node *u, node *v, int i, int l, int r) {
  if (i <= l) return pair<long long, long long>(0, 0);
  assert(u != nullptr && v != nullptr);
  if (r <= i) return v->key - u->key;
  return get(u->ls, v->ls, i, l, (l + r >> 1)) +
         get(u->rs, v->rs, i, (l + r >> 1), r);
}
constexpr int W = 1e9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  node_init();
  int n;
  cin >> n;
  vector<node *> p(n + 1);
  node *rt = p[0] = my0;
  for (int t = 0; t < (n); ++t) {
    int l, r, first[3], second;
    cin >> l >> r >> first[0] >> second >> first[1] >> first[2], ++l, ++r;
    rt = add(rt, 0, pair<long long, long long>(first[0], 0), 0, W);
    rt = add(rt, l, pair<long long, long long>(first[1] - first[0], second), 0,
             W);
    rt = add(rt, r, pair<long long, long long>(first[2] - first[1], -second), 0,
             W);
    p[t + 1] = rt;
  }
  int nq;
  cin >> nq;
  long long ns = 0;
  while (nq--) {
    int l, r, i;
    cin >> l >> r >> i, --l, i = (ns + i) % W;
    pair<long long, long long> f = get(p[l], p[r], i + 1, 0, W);
    cout << (ns = f.first + f.second * i) << '\n';
  }
  return 0;
}
