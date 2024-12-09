#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MAX = 1000000;
class MergeSortTree {
 public:
  vector<vector<int>> t;
  MergeSortTree(int n) { t = vector<vector<int>>(4 * n); }
  void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = vector<int>(1, a[tl]);
    } else {
      int tm = (tl + tr) / 2;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(),
            t[v * 2 + 1].end(), back_inserter(t[v]));
    }
  }
  int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
      int cnt = t[v].end() - lower_bound(t[v].begin(), t[v].end(), x);
      return cnt;
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm), x) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
  }
};
long long pwr(int a, int n) {
  if (n == 0) return 1 % MOD;
  long long q = pwr(a, n / 2);
  q = q * q % MOD;
  if (n & 1) q = q * a % MOD;
  return q;
}
long long inv(long long a) { return pwr(a, MOD - 2); }
vector<long long> fact(MAX);
vector<long long> ifac(MAX);
void init() {
  fact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  for (int i = 0; i < MAX; i++) ifac[i] = inv(fact[i]);
}
long long C(int n, int k) {
  if (k > n) return 0;
  return ((fact[n] * ifac[k] % MOD) * ifac[n - k] % MOD);
}
void solve() {
  init();
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = v[i].second;
  }
  MergeSortTree tree(n + 2);
  tree.build(a, 1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int el = v[i].first;
    int rt = tree.query(1, 1, n, 1, i, el) - 1;
    ans = (ans + C(rt, k - 1)) % MOD;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
