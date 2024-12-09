#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 3;
const long long int LOG = 20 + 5;
const long long int MOD = 1e9 + 7;
const long long int INF = 2e9 + 10;
int n, a[N], q, lq[N], rq[N], l[N], r[N], lazy[4 * N];
long long int sum[4 * N];
vector<int> ql[N], qr[N];
stack<int> st;
long long int ans[N];
inline void shift(int b, int e, int ind) {
  if (b + 1 < e) {
    lazy[ind << 1] += lazy[ind];
    lazy[(ind << 1) | 1] += lazy[ind];
  }
  sum[ind] += 1ll * lazy[ind] * (e - b);
  lazy[ind] = 0;
  return;
}
inline void add(int l, int r, int b = 0, int e = n, int ind = 1) {
  shift(b, e, ind);
  if (r <= b || e <= l) return;
  if (l <= b && e <= r) {
    lazy[ind]++;
    shift(b, e, ind);
    return;
  }
  int mid = (b + e) >> 1;
  add(l, r, b, mid, ind << 1), add(l, r, mid, e, (ind << 1) | 1);
  sum[ind] = sum[ind << 1] + sum[(ind << 1) | 1];
  return;
}
inline long long int get(int l, int r, int b = 0, int e = n, int ind = 1) {
  shift(b, e, ind);
  if (r <= b || e <= l) return 0;
  if (l <= b && e <= r) {
    return sum[ind];
  }
  int mid = (b + e) >> 1;
  long long int res = 0;
  res = get(l, r, b, mid, ind << 1) + get(l, r, mid, e, (ind << 1) | 1);
  sum[ind] = sum[ind << 1] + sum[(ind << 1) | 1];
  return res;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &lq[i]);
    lq[i]--;
    ql[lq[i]].emplace_back(i);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &rq[i]);
    rq[i]--;
    qr[rq[i]].emplace_back(i);
  }
  for (int i = 0; i < n; i++) {
    while (st.size() && a[st.top()] < a[i]) st.pop();
    if (st.size()) l[i] = st.top() + 1;
    st.push(i);
  }
  while (st.size()) st.pop();
  for (int i = n - 1; i >= 0; i--) {
    r[i] = n - 1;
    while (st.size() && a[st.top()] < a[i]) st.pop();
    if (st.size()) r[i] = st.top() - 1;
    st.push(i);
  }
  for (int i = 0; i < n; i++) {
    add(l[i], i + 1);
    for (int id : qr[i]) {
      ans[id] += get(lq[id], i + 1);
    }
  }
  for (int i = 0; i < 4 * N; i++) {
    sum[i] = lazy[i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    add(i, r[i] + 1);
    for (int id : ql[i]) {
      ans[id] += get(i, rq[id] + 1);
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%lld ", ans[i] - (rq[i] - lq[i] + 1));
  }
  return 0;
}
