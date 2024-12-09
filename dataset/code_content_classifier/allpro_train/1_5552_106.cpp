#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
int t[16000005];
int lazy[16000005];
void push(int v) {
  t[v * 2] += lazy[v];
  lazy[v * 2] += lazy[v];
  t[v * 2 + 1] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, int addend) {
  if (l > r) return;
  if (l == tl && tr == r) {
    t[v] += addend;
    lazy[v] += addend;
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), addend);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}
int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l <= tl && tr <= r) return t[v];
  push(v);
  int tm = (tl + tr) / 2;
  return max(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, r;
  cin >> n >> r;
  r = 2 * r;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  int x[n];
  int y[n];
  for (int i = 0; i < n; i++) {
    x[i] = v[i].first - v[i].second;
    y[i] = v[i].first + v[i].second;
    x[i] += 2000000;
    y[i] += 2000000;
  }
  vector<vector<int>> xc;
  xc.resize(4000005);
  for (int i = 0; i < n; i++) {
    xc[x[i]].push_back(y[i]);
  }
  int maxi = 0;
  for (int i = 0; i <= 4000000; i++) {
    for (auto u : xc[i]) {
      update(1, 0, 4000000, max(0, u - r), u, 1);
    }
    if (i - r - 1 >= 0) {
      for (auto u : xc[i - r - 1]) {
        update(1, 0, 4000000, max(0, u - r), u, -1);
      }
    }
    maxi = max(maxi, query(1, 0, 4000000, 0, 4000000));
  }
  cout << maxi;
  return 0;
}
