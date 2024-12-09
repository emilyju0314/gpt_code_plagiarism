#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const double pi = acos(-1);
const double eps = 1e-5;
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
int rev[maxn];
long long a[maxn];
int n, q;
struct STtree {
  struct tree {
    long long a;
    tree() : a(0) {}
  } node[maxn << 2];
  STtree() {}
  inline void push_up(int x, int d) {
    node[x].a = (node[(x << 1) ^ rev[d]].a + node[x << 1 | (1 ^ rev[d])].a);
  }
  void build(int x, int l, int r, long long* a, int d) {
    if (l == r) {
      node[x].a = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build((x << 1) ^ rev[d], l, mid, a, d - 1);
    build(x << 1 | (1 ^ rev[d]), mid + 1, r, a, d - 1);
    push_up(x, d);
  }
  void update(int l, int r, int p, int x, long long k, int d) {
    if (l == r) {
      node[x].a = k;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      update(l, mid, p, (x << 1) ^ rev[d], k, d - 1);
    else
      update(mid + 1, r, p, x << 1 | (1 ^ rev[d]), k, d - 1);
    push_up(x, d);
  }
  long long query(int l, int r, int left, int right, int x, int d) {
    long long res = 0;
    if (left <= l && r <= right) return node[x].a;
    int mid = (l + r) >> 1;
    if (left <= mid)
      res += query(l, mid, left, right, (x << 1) ^ rev[d], d - 1);
    if (right > mid)
      res += query(mid + 1, r, left, right, x << 1 | (1 ^ rev[d]), d - 1);
    return res;
  }
} st;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = (1); i <= (1 << n); i++) {
    cin >> a[i];
  }
  st.build(1, 1, 1 << n, a, n);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      long long x, k;
      cin >> x >> k;
      st.update(1, 1 << n, x, 1, k, n);
    } else if (op == 2) {
      int k;
      cin >> k;
      for (int i = (0); i <= (k); i++) rev[i] ^= 1;
    } else if (op == 3) {
      int k;
      cin >> k;
      rev[k + 1] ^= 1;
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(1, 1 << n, l, r, 1, n) << '\n';
    }
  }
}
