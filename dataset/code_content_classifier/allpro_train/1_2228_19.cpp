#include <bits/stdc++.h>
using namespace std;
bitset<10016> sol;
vector<int> tree[2 << 14];
void upd(int l, int r, int x, int lo, int hi, int nd) {
  if (l >= hi || lo >= r) return;
  if (l <= lo && hi <= r) return tree[nd].push_back(x);
  int mid = (lo + hi) / 2;
  upd(l, r, x, lo, mid, 2 * nd + 1);
  upd(l, r, x, mid, hi, 2 * nd + 2);
}
void go(int lo, int hi, int nd, bitset<10016> curr) {
  for (int x : tree[nd]) curr |= curr << x;
  if (lo + 1 == hi) return (void)(sol |= curr);
  int mid = (lo + hi) / 2;
  go(lo, mid, 2 * nd + 1, curr);
  go(mid, hi, 2 * nd + 2, curr);
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    upd(l - 1, r, x, 0, n, 0);
  }
  go(0, n, 0, 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += sol[i];
  cout << cnt << '\n';
  for (int i = 1; i <= n; ++i)
    if (sol[i]) cout << i << ' ';
}
