#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 305;
int n, m;
int a[maxn], l[maxm], r[maxm];
bool used[maxm];
int ans, ans_id;
vector<int> trace;
int t[maxn << 2], lazy[maxn << 2], cnt = 1;
void build(int ll, int rr, int idx) {
  if (ll == rr) {
    scanf("%d", &t[idx]);
    a[cnt++] = t[idx];
    return;
  }
  int mid = (ll + rr) / 2;
  int lid = idx * 2, rid = idx * 2 + 1;
  build(ll, mid, lid);
  build(mid + 1, rr, rid);
  t[idx] = min(t[lid], t[rid]);
}
void push_down(int ll, int rr, int idx) {
  if (lazy[idx] == 0 || ll == rr) return;
  int lid = idx * 2, rid = idx * 2 + 1;
  t[lid] += lazy[idx], lazy[lid] += lazy[idx];
  t[rid] += lazy[idx], lazy[rid] += lazy[idx];
  lazy[idx] = 0;
}
void update(int l1, int r1, int x, int l2, int r2, int idx) {
  if (l1 > r2 || r1 < l2) return;
  if (l2 >= l1 && r2 <= r1) {
    t[idx] += x;
    lazy[idx] += x;
    return;
  }
  push_down(l2, r2, idx);
  int mid = (l2 + r2) / 2;
  int lid = idx * 2, rid = idx * 2 + 1;
  update(l1, r1, x, l2, mid, lid);
  update(l1, r1, x, mid + 1, r2, rid);
  t[idx] = min(t[lid], t[rid]);
}
int main() {
  scanf("%d%d", &n, &m);
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l[i], &r[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (i >= l[j] && i <= r[j]) {
        if (used[j]) {
          used[j] = false;
          update(l[j], r[j], 1, 1, n, 1);
        }
      } else {
        if (!used[j]) {
          used[j] = true;
          update(l[j], r[j], -1, 1, n, 1);
        }
      }
    }
    int can = a[i] - t[1];
    if (can > ans) {
      ans = can;
      ans_id = i;
      trace.clear();
      for (int j = 0; j < m; j++) {
        if (used[j]) trace.push_back(j + 1);
      }
    }
  }
  printf("%d\n%d\n", ans, trace.size());
  for (int item : trace) printf("%d ", item);
  return 0;
}
