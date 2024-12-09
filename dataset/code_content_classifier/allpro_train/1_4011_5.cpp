#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Node {
  using pnode = Node *;
  T val;
  int prior, size, id;
  pnode l, r;
  int pairings_including_me;
  int pairings_excluding_me;
  Node(int _val, int pri, int idx)
      : val(_val), id(idx), prior(pri), size(1), l(nullptr), r(nullptr) {
    pairings_excluding_me = pairings_including_me = 0;
  }
  static int get_size(pnode l) { return l ? l->size : 0; }
  static void refresh(pnode t) {
    if (not t) return;
    auto l = t->l, r = t->r;
    t->size = get_size(l) + get_size(r) + 1;
    t->pairings_excluding_me = get_ans(l) + get_ans(r);
    auto lpem = l ? l->pairings_excluding_me : -1;
    auto lpim = l ? l->pairings_including_me : 0;
    auto rpem = r ? r->pairings_excluding_me : -1;
    auto rpim = r ? r->pairings_including_me : 0;
    t->pairings_including_me =
        max(t->pairings_excluding_me, 1 + max(lpem + rpim, lpim + rpem));
  }
  static pnode merge(pnode l, pnode r) {
    if (not l or not r) return l ? l : r;
    if (l->prior > r->prior) {
      l->r = merge(l->r, r);
      refresh(l);
      return l;
    }
    r->l = merge(l, r->l);
    refresh(r);
    return r;
  }
  static pnode build(const vector<pair<int, int> > &arr, int l, int r) {
    if (l == r) return new Node(arr[l].first, arr[l].second, l);
    int mid = (l + r) / 2;
    return merge(build(arr, l, mid), build(arr, mid + 1, r));
  }
  static void split_by_val(pnode t, pnode &l, pnode &r, T val) {
    if (not t) {
      l = r = nullptr;
      return;
    }
    if (t->val <= val) {
      split_by_val(t->r, t->r, r, val);
      l = t;
    } else {
      split_by_val(t->l, l, t->l, val);
      r = t;
    }
    refresh(t);
  }
  static int get_ans(pnode t) { return t ? t->pairings_including_me : 0; }
  int inorder(pnode t, int depth = 0) {
    if (not t) return -1;
    int a = inorder(t->l, depth + 1);
    cout << t->id << " " << t->val << " " << t->prior << " " << depth << "\n";
    int b = inorder(t->r, depth + 1);
    cout << "Children of counter " << t->id << " are " << a << " " << b << "\n";
    return t->id;
  }
};
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > points(k);
  for (auto &[x, y] : points) cin >> x >> y;
  points.resize(n);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  const int mod = 1e9 + 9;
  for (int i = k; i < n; i++) {
    points[i].first = (1ll * a * points[i - 1].first + b) % mod;
    points[i].second = (1ll * c * points[i - 1].second + d) % mod;
  }
  sort(points.begin(), points.end());
  auto treap = Node<int>::build(points, 0, n - 1);
  int m;
  cin >> m;
  Node<int> *l, *mid, *r;
  for (int i = 0; i < m; i++) {
    int ql, qr;
    cin >> ql >> qr;
    treap->split_by_val(treap, l, r, ql - 1);
    treap->split_by_val(r, mid, r, qr);
    cout << treap->get_ans(mid) << "\n";
    treap = treap->merge(l, mid);
    treap = treap->merge(treap, r);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
