#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
const long long L_INF = 4e18;
const long double EPS = 1e-10;
struct Ring {
  int a, b, h;
  bool operator<(const Ring& other) const {
    if (b != other.b) return b > other.b;
    if (a != other.a) return a > other.a;
    return h > other.h;
  }
};
int n;
Ring ring[MAXN];
unordered_map<int, long long> tree(5000000);
long long dp[MAXN];
void update(int v, int tl, int tr, int p, long long x) {
  if (tr - tl == 1) {
    tree[v] = max(tree[v], x);
    return;
  }
  int tm = (tl + tr) >> 1;
  if (p < tm) {
    update(2 * v + 1, tl, tm, p, x);
    tree[v] = max(tree[v], tree[2 * v + 1]);
  } else {
    update(2 * v + 2, tm, tr, p, x);
    tree[v] = max(tree[v], tree[2 * v + 2]);
  }
}
long long get(int v, int tl, int tr, int l, int r) {
  if (tr <= l || r <= tl) return 0;
  if (l <= tl && tr <= r) return tree.find(v) != tree.end() ? tree[v] : 0;
  int tm = (tl + tr) >> 1;
  return max(get(2 * v + 1, tl, tm, l, r), get(2 * v + 2, tm, tr, l, r));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  srand(566);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, h;
    cin >> a >> b >> h;
    ring[i] = {a, b, h};
  }
  sort(ring, ring + n);
  for (int i = 0; i < n; i++) {
    dp[i] = get(0, 0, INF, 0, ring[i].b) + ring[i].h;
    update(0, 0, INF, ring[i].a, dp[i]);
  }
  cout << get(0, 0, INF, 0, INF);
  return 0;
}
