#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1010;
int k = 450;
int n;
int is_boy[MAXN], f[MAXN], was[MAXN];
vector<int> g[MAXN];
int st[MAXN], first[MAXN];
int where[2 * MAXN];
int pr[20][MAXN];
vector<int> order;
int cur_t = 0;
void find_time(int v, int _pr) {
  if (was[v]) {
    return;
  }
  was[v] = 1;
  pr[0][v] = _pr;
  int start_t = cur_t;
  assert(order.size() == cur_t);
  order.push_back(v);
  st[v] = cur_t++;
  for (int u : g[v]) {
    find_time(u, v);
  }
  assert(order.size() == cur_t);
  int finish_t = cur_t;
  first[v] = cur_t++;
  order.push_back(v);
  where[start_t] = finish_t;
  where[finish_t] = start_t;
}
bool is_pr(int u, int v) { return (st[u] <= st[v]) && (first[u] >= first[v]); }
int find_lca(int u, int v) {
  if (is_pr(u, v)) {
    return u;
  }
  for (int i = 19; i >= 0; i--) {
    if (!is_pr(pr[i][u], v)) {
      u = pr[i][u];
    }
  }
  return pr[0][u];
}
long long ans[MAXN];
vector<pair<pair<int, int>, int>> seg;
int lca[MAXN];
bool cmp(const pair<pair<int, int>, int>& a,
         const pair<pair<int, int>, int>& b) {
  return (a.first.second < b.first.second);
}
bool in_range(int l, int s, int r) { return l <= s && s < r; }
long long cur_cnt_people[2][MAXN];
long long res = 0;
void process(vector<pair<pair<int, int>, int>>& seg, int ind_in_seg, int r) {
  long long old_res = res;
  int seg_ind = seg[ind_in_seg].second;
  int seg_l = seg[ind_in_seg].first.first;
  int seg_r = seg[ind_in_seg].first.second;
  for (int j = seg_l; j < min(seg_r, r); j++) {
    int cur_v = order[j];
    int cur_f = f[cur_v];
    bool is_cur_boy = is_boy[cur_v];
    if (in_range(seg_l, where[j], j) || in_range(r, where[j], seg_r)) {
      res -= cur_cnt_people[1 - is_cur_boy][cur_f];
      cur_cnt_people[is_cur_boy][cur_f]--;
    } else {
      res += cur_cnt_people[1 - is_cur_boy][cur_f];
      cur_cnt_people[is_cur_boy][cur_f]++;
    }
  }
  int lca_res = 0;
  if (lca[seg_ind] != order[seg_l] && lca[seg_ind] != order[seg_r]) {
    int cur_lca = lca[seg_ind];
    lca_res += cur_cnt_people[1 - is_boy[cur_lca]][f[cur_lca]];
  }
  ans[seg_ind] = res + lca_res;
  for (int j = min(seg_r, r) - 1; j >= seg_l; j--) {
    int cur_v = order[j];
    int cur_f = f[cur_v];
    bool is_cur_boy = is_boy[cur_v];
    if (in_range(seg_l, where[j], j) || in_range(r, where[j], seg_r)) {
      res += cur_cnt_people[1 - is_cur_boy][cur_f];
      cur_cnt_people[is_cur_boy][cur_f]++;
    } else {
      res -= cur_cnt_people[1 - is_cur_boy][cur_f];
      cur_cnt_people[is_cur_boy][cur_f]--;
    }
  }
  ind_in_seg++;
}
void calc(vector<pair<pair<int, int>, int>>& seg, int l, int r) {
  memset(cur_cnt_people, 0, sizeof cur_cnt_people);
  int ind_in_seg = 0;
  sort(seg.begin(), seg.end(), cmp);
  res = 0;
  for (int i = r; i < order.size(); i++) {
    while (ind_in_seg < seg.size() && seg[ind_in_seg].first.second <= i) {
      process(seg, ind_in_seg, r);
      ind_in_seg++;
    }
    int cur_v = order[i];
    int cur_f = f[cur_v];
    bool is_cur_boy = is_boy[cur_v];
    if (in_range(r, where[i], i)) {
      res -= cur_cnt_people[1 - is_cur_boy][cur_f];
      cur_cnt_people[is_cur_boy][cur_f]--;
    } else {
      res += cur_cnt_people[1 - is_cur_boy][cur_f];
      cur_cnt_people[is_cur_boy][cur_f]++;
    }
  }
  while (ind_in_seg < seg.size()) {
    process(seg, ind_in_seg, r);
    ind_in_seg++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> is_boy[i];
  }
  map<int, int> sq;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    sq[f[i]];
  }
  int cnt_f = 0;
  for (auto& it : sq) {
    it.second = cnt_f++;
  }
  for (int i = 0; i < n; i++) {
    f[i] = sq[f[i]];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(was, 0, sizeof was);
  find_time(0, 0);
  for (int i = 1; i < 20; i++)
    for (int j = 0; j < n; j++) {
      pr[i][j] = pr[i - 1][pr[i - 1][j]];
    }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (st[u] >= st[v]) {
      swap(u, v);
    }
    int lca = find_lca(u, v);
    ::lca[i] = lca;
    if (lca != u) {
      seg.push_back({{first[u], st[v] + 1}, i});
    } else {
      seg.push_back({{st[u], st[v] + 1}, i});
    }
  }
  sort(seg.begin(), seg.end());
  int l = 0, r = min(k, (int)order.size());
  int ind = 0;
  while (l < order.size()) {
    vector<pair<pair<int, int>, int>> cur_seg;
    while (ind < seg.size() && seg[ind].first.first < r) {
      cur_seg.push_back(seg[ind]);
      ind++;
    }
    calc(cur_seg, l, r);
    l = r;
    r = min((int)order.size(), r + k);
  }
  assert(ind == seg.size());
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
