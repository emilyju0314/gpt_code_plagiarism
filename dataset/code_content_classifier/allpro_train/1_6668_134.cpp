#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, x, cur = 0, arr[N], l, r, val, idx2, k, i, j;
struct S {
  vector<pair<int, int> > v;
  vector<long long> sum;
  long long val;
  S() {
    sum.clear();
    v.clear();
    val = 0;
  }
  void cl() {
    val = 0;
    sum.clear();
    v.clear();
  }
};
inline void doit(S &a, S &b) {
  a.v = b.v;
  a.sum = b.sum;
  a.val = b.val;
}
S seg[4 * N][2], tmpp[4 * N][2];
inline void make(S &tmp, S &a, S &b, S &a2, S &b2, bool c) {
  tmp.cl();
  tmp.val += a.val + b.val;
  i = 0, j = (int)b.v.size() - 1;
  for (j = (int)b.v.size() - 1; j >= 0; j--) {
    while (i < (int)a.v.size() && (b.v[j].first | a.v[i].first) < x) i++;
    if (i == (int)a.v.size()) break;
    tmp.val +=
        (long long)b.v[j].second * (a.sum.back() - (i == 0 ? 0 : a.sum[i - 1]));
  }
  cur = 0;
  if (c) {
    for (i = 0; i < a2.v.size(); i++) {
      cur |= a2.v[i].first;
      tmp.v.push_back(a2.v[i]);
    }
    for (i = 0; i < b.v.size(); i++) {
      if ((int)tmp.v.size() > 0 && tmp.v.back().first == (b.v[i].first | cur))
        tmp.v.back().second += b.v[i].second;
      else
        tmp.v.push_back(make_pair((b.v[i].first | cur), b.v[i].second));
    }
  } else {
    for (i = 0; i < b2.v.size(); i++) {
      cur |= b2.v[i].first;
      tmp.v.push_back(b2.v[i]);
    }
    for (i = 0; i < a.v.size(); i++) {
      if ((int)tmp.v.size() > 0 && tmp.v.back().first == (a.v[i].first | cur))
        tmp.v.back().second += a.v[i].second;
      else
        tmp.v.push_back(make_pair((a.v[i].first | cur), a.v[i].second));
    }
  }
  if ((int)tmp.v.size() > 0) tmp.sum.push_back(tmp.v[0].second);
  for (i = 1; i < (int)tmp.v.size(); i++)
    tmp.sum.push_back(tmp.sum.back() + tmp.v[i].second);
}
void build(int s, int e, int idx) {
  if (s == e) {
    seg[idx][0].v.push_back(make_pair(arr[s], 1));
    seg[idx][0].val = (arr[s] >= x);
    seg[idx][1].v.push_back(make_pair(arr[s], 1));
    seg[idx][1].val = (arr[s] >= x);
    seg[idx][0].sum.push_back(1);
    seg[idx][1].sum.push_back(1);
    return;
  }
  build(s, ((s + e) >> 1), (idx << 1));
  build(((s + e) >> 1) + 1, e, (idx << 1) + 1);
  make(seg[idx][0], seg[idx * 2][0], seg[idx * 2 + 1][1], seg[idx * 2][1],
       seg[idx * 2 + 1][0], 0);
  make(seg[idx][1], seg[idx * 2][0], seg[idx * 2 + 1][1], seg[idx * 2][1],
       seg[idx * 2 + 1][0], 1);
}
void update(int s, int e, int idx) {
  if (s > idx2 || e < idx2) return;
  if (s == e) {
    arr[s] = val;
    seg[idx][0].v.clear();
    seg[idx][1].v.clear();
    seg[idx][0].v.push_back(make_pair(arr[s], 1));
    seg[idx][0].val = (arr[s] >= x);
    seg[idx][1].v.push_back(make_pair(arr[s], 1));
    seg[idx][1].val = (arr[s] >= x);
    seg[idx][0].sum.push_back(1);
    seg[idx][1].sum.push_back(1);
    return;
  }
  update(s, ((s + e) >> 1), (idx << 1));
  update(((s + e) >> 1) + 1, e, (idx << 1) + 1);
  make(seg[idx][0], seg[idx * 2][0], seg[idx * 2 + 1][1], seg[idx * 2][1],
       seg[idx * 2 + 1][0], 0);
  make(seg[idx][1], seg[idx * 2][0], seg[idx * 2 + 1][1], seg[idx * 2][1],
       seg[idx * 2 + 1][0], 1);
}
void get(int s, int e, int idx) {
  if (s > r || e < l) {
    tmpp[idx][0].cl();
    tmpp[idx][1].cl();
    return;
  }
  if (s >= l && e <= r) {
    doit(tmpp[idx][0], seg[idx][0]);
    doit(tmpp[idx][1], seg[idx][1]);
    return;
  }
  get(s, ((s + e) >> 1), (idx << 1));
  get(((s + e) >> 1) + 1, e, (idx << 1) + 1);
  make(tmpp[idx][0], tmpp[idx * 2][0], tmpp[idx * 2 + 1][1], tmpp[idx * 2][1],
       tmpp[idx * 2 + 1][0], 0);
  make(tmpp[idx][1], tmpp[idx * 2][0], tmpp[idx * 2 + 1][1], tmpp[idx * 2][1],
       tmpp[idx * 2 + 1][0], 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  build(0, n - 1, 1);
  while (m--) {
    scanf("%d", &k);
    if (k == 1) {
      scanf("%d%d", &idx2, &val);
      idx2--;
      update(0, n - 1, 1);
    } else {
      scanf("%d%d", &l, &r);
      l--, r--;
      get(0, n - 1, 1);
      printf("%lld\n", tmpp[1][0].val);
    }
  }
  return 0;
}
