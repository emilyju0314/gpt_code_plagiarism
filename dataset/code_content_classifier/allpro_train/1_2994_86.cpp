#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, m, l_[MAXN], r_[MAXN], arr[MAXN];
int max_o, max_e, lazy[2][2 * MAXN];
long long answer;
pair<int, pair<int, long long>> seg[2][2 * MAXN];
vector<int> s[MAXN], e[MAXN];
inline pair<int, pair<int, long long>> smin(pair<int, pair<int, long long>> l,
                                            pair<int, pair<int, long long>> r) {
  pair<int, pair<int, long long>> d = min(l, r);
  if (l.first == r.first) {
    d.second.first = l.second.first + r.second.first;
    d.second.second = l.second.second + r.second.second;
  }
  return d;
}
inline void shift_e(int id) {
  lazy[0][id << 1] += lazy[0][id];
  lazy[0][id << 1 | 1] += lazy[0][id];
  seg[0][id << 1].first += lazy[0][id];
  seg[0][id << 1 | 1].first += lazy[0][id];
  lazy[0][id] = 0;
  seg[0][id] = smin(seg[0][id << 1], seg[0][id << 1 | 1]);
  return;
}
inline void shift_o(int id) {
  lazy[1][id << 1] += lazy[1][id];
  lazy[1][id << 1 | 1] += lazy[1][id];
  seg[1][id << 1].first += lazy[1][id];
  seg[1][id << 1 | 1].first += lazy[1][id];
  lazy[1][id] = 0;
  seg[1][id] = smin(seg[1][id << 1], seg[1][id << 1 | 1]);
  return;
}
void build_e(int l = 1, int r = max_e, int id = 1) {
  lazy[0][id] = 0;
  if (l == (r - 1)) {
    seg[0][id] = {0, {1, 2 * l}};
    return;
  }
  int mid = l + r >> 1;
  build_e(l, mid, id << 1);
  build_e(mid, r, id << 1 | 1);
  seg[0][id] = smin(seg[0][id << 1], seg[0][id << 1 | 1]);
  return;
}
void build_o(int l = 1, int r = max_o, int id = 1) {
  lazy[1][id] = 0;
  if (l == (r - 1)) {
    seg[1][id] = {0, {1, 2 * l - 1}};
    return;
  }
  int mid = l + r >> 1;
  build_o(l, mid, id << 1);
  build_o(mid, r, id << 1 | 1);
  seg[1][id] = smin(seg[1][id << 1], seg[1][id << 1 | 1]);
  return;
}
void seg_e_upt(int lp, int rp, int val, int l = 1, int r = max_e, int id = 1) {
  if (l >= rp || r <= lp) return;
  if (l >= lp && r <= rp) {
    lazy[0][id] += val;
    seg[0][id].first += val;
    return;
  }
  shift_e(id);
  int mid = (l + r) >> 1;
  seg_e_upt(lp, rp, val, l, mid, id << 1);
  seg_e_upt(lp, rp, val, mid, r, id << 1 | 1);
  seg[0][id] = smin(seg[0][id << 1], seg[0][id << 1 | 1]);
  return;
}
void seg_o_upt(int lp, int rp, int val, int l = 1, int r = max_o, int id = 1) {
  if (l >= rp || r <= lp) return;
  if (l >= lp && r <= rp) {
    lazy[1][id] += val;
    seg[1][id].first += val;
    return;
  }
  shift_o(id);
  int mid = (l + r) >> 1;
  seg_o_upt(lp, rp, val, l, mid, id << 1);
  seg_o_upt(lp, rp, val, mid, r, id << 1 | 1);
  seg[1][id] = smin(seg[1][id << 1], seg[1][id << 1 | 1]);
  return;
}
pair<int, pair<int, long long>> seg_e_get(int lp, int rp, int l = 1,
                                          int r = max_e, int id = 1) {
  if (l >= rp || r <= lp) return {(int)1e9, {0, 0}};
  if (l >= lp && r <= rp) return seg[0][id];
  shift_e(id);
  int mid = (l + r) >> 1;
  return smin(seg_e_get(lp, rp, l, mid, id << 1),
              seg_e_get(lp, rp, mid, r, id << 1 | 1));
}
pair<int, pair<int, long long>> seg_o_get(int lp, int rp, int l = 1,
                                          int r = max_o, int id = 1) {
  if (l >= rp || r <= lp) return {(int)1e9, {0, 0}};
  if (l >= lp && r <= rp) return seg[1][id];
  shift_o(id);
  int mid = (l + r) >> 1;
  return smin(seg_o_get(lp, rp, l, mid, id << 1),
              seg_o_get(lp, rp, mid, r, id << 1 | 1));
}
void upt(int i, int val) {
  int l = l_[i], r = r_[i];
  if (l & 1)
    seg_e_upt(l / 2 + 1, r / 2 + 1, val);
  else
    seg_o_upt(l / 2 + 1, (r + 1) / 2 + 1, val);
  if ((r - l) & 1) {
    r++;
    seg_e_upt((r + 1) / 2, max_e, val);
    seg_o_upt(r / 2 + 1, max_o, val);
  }
}
void upt(int l, int r, int val) {
  if (l & 1)
    seg_e_upt(l / 2 + 1, r / 2 + 1, val);
  else
    seg_o_upt(l / 2 + 1, (r + 1) / 2 + 1, val);
  if ((r - l) & 1) {
    r++;
    seg_e_upt((r + 1) / 2, max_e, val);
    seg_o_upt(r / 2 + 1, max_o, val);
  }
}
void go(int v) {
  for (long long i = 1; i <= v; i++) answer -= i * (v - i + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  if (m == 1) return cout << 1 << endl, 0;
  max_o = (m + 1) / 2 + 1;
  max_e = m / 2 + 1;
  for (int i = 0; i < n; i++) {
    cin >> l_[i] >> r_[i];
    arr[l_[i]]++;
    arr[r_[i] + 1]--;
    e[r_[i]].push_back(i);
    s[l_[i]].push_back(i);
  }
  for (int i = 1; i <= m; i++) arr[i] += arr[i - 1];
  int hh = 0;
  for (int i = 1; i <= m; i++) {
    if (arr[i]) {
      go(hh);
      hh = 0;
    } else
      hh++;
  }
  go(hh);
  build_o();
  build_e();
  for (int i = 0; i < n; i++) upt(i, 1);
  pair<int, pair<int, long long>> lo = seg_o_get(1, max_o);
  pair<int, pair<int, long long>> ro = seg_e_get(1, max_e);
  if (lo.first == 0) answer += lo.second.second;
  if (ro.first == 0) answer += ro.second.second;
  for (int i = 3; i <= m; i += 2) {
    for (auto j : e[i - 2]) upt(i - 2, i - 2, -1);
    for (auto j : e[i - 1]) upt(max(i - 2, l_[j]), i - 1, -1);
    for (auto j : s[i - 1]) {
      if (r_[j] < i) continue;
      upt(j, -1);
      upt(i, r_[j], 1);
    }
    pair<int, pair<int, long long>> l = seg_o_get((i + 1) / 2, max_o);
    pair<int, pair<int, long long>> r = seg_e_get((i + 1) / 2, max_e);
    if (l.first == 0)
      answer += l.second.second - 1ll * l.second.first * (i - 1);
    if (r.first == 0)
      answer += r.second.second - 1ll * r.second.first * (i - 1);
  }
  build_o();
  build_e();
  for (int i = 0; i < n; i++)
    if (r_[i] >= 2) upt(max(2, l_[i]), r_[i], 1);
  pair<int, pair<int, long long>> l = seg_o_get(2, max_o);
  pair<int, pair<int, long long>> r = seg_e_get(1, max_e);
  if (l.first == 0) answer += l.second.second - 1ll * l.second.first * 1;
  if (r.first == 0) answer += r.second.second - 1ll * r.second.first * 1;
  for (int i = 4; i <= m; i += 2) {
    for (auto j : e[i - 2]) upt(i - 2, i - 2, -1);
    for (auto j : e[i - 1]) upt(max(i - 2, l_[j]), i - 1, -1);
    for (auto j : s[i - 1]) {
      if (r_[j] < i) continue;
      upt(j, -1);
      upt(i, r_[j], 1);
    }
    pair<int, pair<int, long long>> l = seg_o_get(i / 2 + 1, max_o);
    pair<int, pair<int, long long>> r = seg_e_get(i / 2, max_e);
    if (l.first == 0)
      answer += l.second.second - 1ll * l.second.first * (i - 1);
    if (r.first == 0)
      answer += r.second.second - 1ll * r.second.first * (i - 1);
  }
  cout << answer << endl;
  return 0;
}
