#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 5;
const int LOGN = 20, blk_sz = 800;
int BIT[302][maxn], n, m;
void upd(int t, int idx, int v) {
  while (idx <= n) {
    BIT[t][idx] += v;
    idx += idx & -idx;
  }
}
int ask(int t, int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += BIT[t][idx];
    idx -= idx & -idx;
  }
  return ret;
}
int a[maxn], b[maxn], b_idx[maxn], a_idx[maxn];
int query(int la, int ra, int lb, int rb) {
  int cnt = 0;
  while (la <= ra && la % blk_sz != 0) {
    int x = a[la];
    if (b_idx[x] >= lb && b_idx[x] <= rb) {
      cnt++;
    }
    ++la;
  }
  while (la + blk_sz - 1 <= ra) {
    cnt += ask(la / blk_sz, rb) - ask(la / blk_sz, lb - 1);
    la += blk_sz;
  }
  while (la <= ra) {
    int x = a[la];
    if (b_idx[x] >= lb && b_idx[x] <= rb) {
      cnt++;
    }
    ++la;
  }
  return cnt;
}
void update(int l, int r) {
  int x = b[l], y = b[r];
  upd(a_idx[x] / blk_sz, l, -1);
  upd(a_idx[x] / blk_sz, r, +1);
  upd(a_idx[y] / blk_sz, r, -1);
  upd(a_idx[y] / blk_sz, l, +1);
  b[l] = y, b[r] = x;
  b_idx[y] = l, b_idx[x] = r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a_idx[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b_idx[b[i]] = i;
    upd(a_idx[b[i]] / blk_sz, i, +1);
  }
  while (m--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      cout << query(la, ra, lb, rb) << "\n";
    } else {
      int l, r;
      cin >> l >> r;
      update(l, r);
    }
  }
  return 0;
}
