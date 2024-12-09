#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> hh[250000], cc[250000];
int h[10000001];
long long c[10000001], d[10000001];
int l[10000001], r[10000001];
int* bt;
int sz = 1;
void upd(int k, int w, bool inv) {
  while (k) {
    if (!inv) {
      if (bt[k] >= w) return;
    } else {
      if (bt[k] <= w) return;
    }
    bt[k] = w;
    k >>= 1;
  }
}
int qry(int l, int r, bool inv) {
  int ret = (!inv ? -(1 << 30) : (1 << 30));
  while (l <= r) {
    if (l & 1) {
      if (!inv) {
        if (bt[l] > ret) ret = bt[l];
      } else {
        if (bt[l] < ret) ret = bt[l];
      }
      l++;
    }
    if (!(r & 1)) {
      if (!inv) {
        if (bt[r] > ret) ret = bt[r];
      } else {
        if (bt[r] < ret) ret = bt[r];
      }
      r--;
    }
    l >>= 1;
    r >>= 1;
  }
  return ret;
}
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    q;
long long solve() {
  while (sz <= n) sz *= 2;
  bt = new int[sz * 2 + 1];
  for (int i = 0; i < sz * 2; i++) bt[i] = (1 << 30);
  for (int i = 1; i <= n; i++) {
    if (h[i] >= i)
      l[i] = 1;
    else if (h[i] == 1)
      l[i] = i;
    else {
      l[i] = qry(sz + i - h[i] + 1, sz + i - 1, true);
      if (l[i] > i) l[i] = i;
    }
    bt[sz + i] = l[i];
    upd((sz + i) / 2, l[i], true);
  }
  memset(bt, 0, sizeof(bt));
  for (int i = n; i >= 1; i--) {
    if (i + h[i] - 1 >= n)
      r[i] = n;
    else if (h[i] == 1)
      r[i] = i;
    else {
      r[i] = qry(sz + i + 1, sz + i + h[i] - 1, false);
      if (r[i] < i) r[i] = i;
    }
    bt[sz + i] = r[i];
    upd((sz + i) / 2, r[i], false);
  }
  delete[] bt;
  for (int i = 1; i <= n; i++) {
    while (!q.empty() && q.top().second < i) q.pop();
    d[i] = d[l[i] - 1] + c[i];
    if (!q.empty() && q.top().first < d[i]) d[i] = q.top().first;
    q.push(pair<long long, int>(d[i - 1] + c[i], r[i]));
  }
  return d[n];
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    hh[i].resize(k);
    cc[i].resize(k);
    for (int j = 0; j < k; j++) scanf("%d", &hh[i][j]);
    for (int j = 0; j < k; j++) scanf("%d", &cc[i][j]);
  }
  int q;
  scanf("%d", &q);
  int cur = 1;
  while (q--) {
    int id;
    long long mul;
    scanf("%d %lld", &id, &mul);
    for (int j = 0; j < hh[id - 1].size(); j++) {
      h[cur] = hh[id - 1][j];
      c[cur] = cc[id - 1][j] * mul;
      cur++;
    }
  }
  for (int i = 0; i < n; i++) {
    hh[i] = vector<int>();
    cc[i] = vector<int>();
  }
  n = m;
  printf("%lld\n", solve());
  return 0;
}
