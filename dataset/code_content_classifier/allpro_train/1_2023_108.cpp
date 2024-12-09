#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
int a[N], prop[4 * N];
void update(int at, int l, int r, int lo, int hi, int val) {
  if (l > hi or r < lo) return;
  if (l >= lo and r <= hi) {
    prop[at] += val;
    return;
  }
  int left = at + at, right = left + 1, mid = (l + r) / 2;
  update(left, l, mid, lo, hi, val);
  update(right, mid + 1, r, lo, hi, val);
}
int query(int at, int l, int r, int pos) {
  if (l > pos or r < pos) return 0;
  if (l == pos and l == r) return prop[at];
  int left = at + at, right = left + 1, mid = (l + r) / 2;
  prop[left] += prop[at], prop[right] += prop[at], prop[at] = 0;
  if (pos <= mid) return query(left, l, mid, pos);
  return query(right, mid + 1, r, pos);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  memset(prop, 0, sizeof prop);
  while (q--) {
    int l, r;
    cin >> l >> r;
    update(1, 1, n, l, r, 1);
  }
  int cnt[n];
  for (int i = 0; i < n; ++i) cnt[i] = query(1, 1, n, i + 1);
  sort(cnt, cnt + n);
  long long res = 0;
  for (int i = 0; i < n; ++i) res += (long long)a[i] * (long long)cnt[i];
  cout << res;
  return 0;
}
