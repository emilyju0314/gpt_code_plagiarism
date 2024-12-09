#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> tree[4 * 200005];
void update(int n, int st, int en, int idx,
            pair<long long int, long long int> val) {
  if (st == en) {
    tree[n] = val;
    return;
  }
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  if (idx <= mid)
    update(lc, st, mid, idx, val);
  else
    update(rc, mid + 1, en, idx, val);
  tree[n].first = tree[lc].first + tree[rc].first;
  tree[n].second = tree[lc].second + tree[rc].second;
}
pair<long long int, long long int> query(int n, int st, int en, int l, int r) {
  if (r < st || en < l) return {0, 0};
  if (l <= st && en <= r) return tree[n];
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  pair<long long int, long long int> q1 = query(lc, st, mid, l, r);
  pair<long long int, long long int> q2 = query(rc, mid + 1, en, l, r);
  q1.first += q2.first;
  q1.second += q2.second;
  return q1;
}
int main() {
  int n, inp;
  long long int rem;
  cin >> n >> rem;
  for (int i = 0; i < n; i++) {
    scanf("%d", &inp);
    update(1, 1, n, i + 1, {inp, 1});
  }
  long long int ans = 0;
  while (1) {
    while (query(1, 1, n, 1, n).first > rem) {
      int lo = 1, hi = n, firstFail;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (query(1, 1, n, 1, mid).first > rem) {
          firstFail = mid;
          hi = mid - 1;
        } else
          lo = mid + 1;
      }
      update(1, 1, n, firstFail, {0, 0});
    }
    long long int totPrize = query(1, 1, n, 1, n).first;
    long long int totCandy = query(1, 1, n, 1, n).second;
    if (!totCandy) break;
    long long int totGhurbo = rem / totPrize;
    ans += totGhurbo * totCandy;
    rem -= totGhurbo * totPrize;
  }
  cout << ans << '\n';
  return 0;
}
