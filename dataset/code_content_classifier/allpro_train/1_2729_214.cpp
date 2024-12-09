#include <bits/stdc++.h>
using namespace std;
int lim = 1e6;
int inf = 1e8;
long long mod = 1e9 + 7;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2> v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
vector<vector<pair<int, int> > > lazy;
vector<int> seg_tree;
int n;
void helper_update(int node, vector<pair<int, int> > opv) {
  int tmps = opv.size();
  if (tmps == 0) return;
  if (tmps == 2 or (tmps == 1 and opv[0].first == 2))
    lazy[node] = opv;
  else {
    int tmpk = lazy[node].size();
    if (tmpk == 0)
      lazy[node] = opv;
    else if (tmpk == 1) {
      if (lazy[node][0].first == 2)
        lazy[node].push_back(opv[0]);
      else
        lazy[node][0].second += opv[0].second;
    } else
      lazy[node][1].second += opv[0].second;
  }
}
void helper_seg(int node, vector<pair<int, int> > opv) {
  int tmps = opv.size();
  if (tmps == 0) return;
  if (tmps == 1) {
    if (opv[0].first == 1)
      seg_tree[node] += opv[0].second;
    else
      seg_tree[node] = 0;
  } else {
    seg_tree[node] = opv[1].second;
  }
}
void recurse_update(int st, int en, int l, int r, int node, int val, int op) {
  if (st > en or l > r) return;
  int mid = (st + en) / 2;
  int lnode = 2 * node + 1, rnode = 2 * node + 2;
  if (lazy[node].size() > 0) {
    if (st != en) {
      helper_update(lnode, lazy[node]);
      helper_update(rnode, lazy[node]);
    }
    helper_seg(node, lazy[node]);
    lazy[node].clear();
  }
  if (st == l and en == r) {
    auto oper = vector<pair<int, int> >{make_pair(op, val)};
    if (st != en) {
      helper_update(lnode, oper);
      helper_update(rnode, oper);
    }
    helper_seg(node, oper);
  } else if (l > mid) {
    seg_tree[node] += (r - l + 1) * val;
    recurse_update(mid + 1, en, l, r, rnode, val, op);
  } else if (r <= mid) {
    seg_tree[node] += (r - l + 1) * val;
    recurse_update(st, mid, l, r, lnode, val, op);
  } else {
    seg_tree[node] += (r - l + 1) * val;
    recurse_update(st, mid, l, mid, lnode, val, op);
    recurse_update(mid + 1, en, mid + 1, r, rnode, val, op);
  }
}
void update_seg(int l, int r, int val, int op) {
  recurse_update(0, n - 1, l, r, 0, val, op);
}
int recurse_query(int st, int en, int l, int r, int node) {
  if (st > en or l > r) return 0;
  int mid = (st + en) / 2;
  int lnode = 2 * node + 1, rnode = 2 * node + 2;
  if (lazy[node].size() > 0) {
    if (st != en) {
      helper_update(lnode, lazy[node]);
      helper_update(rnode, lazy[node]);
    }
    helper_seg(node, lazy[node]);
    lazy[node].clear();
  }
  if (st == l and en == r)
    return seg_tree[node];
  else if (l > mid)
    return recurse_query(mid + 1, en, l, r, rnode);
  else if (r <= mid)
    return recurse_query(st, mid, l, r, lnode);
  else {
    return (recurse_query(st, mid, l, mid, lnode) +
            recurse_query(mid + 1, en, mid + 1, r, rnode));
  }
}
int query_seg(int l, int r) { return recurse_query(0, n - 1, l, r, 0); }
int get_pow2(int n) {
  int m = n;
  int r = 0;
  while (m > 1) {
    r++;
    m /= 2;
  }
  if (pow(2, r) == n)
    return n;
  else
    return (int)pow(2, r + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int nq;
  cin >> nq;
  int k = 0;
  map<int, vector<vector<int> > > mp;
  map<int, int> mts;
  for (int i = 0; i < nq; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (mts.find(y) == mts.end()) {
      mts[y] = 0;
    }
    if (mp.find(z) == mp.end()) {
      vector<vector<int> > tmp;
      mp[z] = tmp;
    }
    if (x == 3) {
      mp[z].push_back(vector<int>{x, y, k});
      k++;
    } else
      mp[z].push_back(vector<int>{x, y});
  }
  vector<int> ans(k, 0);
  int cnt = 0;
  for (auto it = mts.begin(); it != mts.end(); it++) {
    it->second = cnt;
    cnt++;
  }
  int N = mts.size();
  n = get_pow2(N);
  seg_tree.assign(2 * n - 1, 0);
  lazy.assign(2 * n - 1, vector<pair<int, int> >{});
  for (auto it = mp.begin(); it != mp.end(); it++) {
    auto queries = it->second;
    for (int i = 0; i < queries.size(); i++) {
      if (queries[i][0] == 1)
        update_seg(mts[queries[i][1]], N - 1, 1, 1);
      else if (queries[i][0] == 2)
        update_seg(mts[queries[i][1]], N - 1, -1, 1);
      else {
        ans[queries[i][2]] = query_seg(mts[queries[i][1]], mts[queries[i][1]]);
      }
    }
    update_seg(0, n - 1, 0, 2);
  }
  for (int i = 0; i < k; i++) cout << ans[i] << '\n';
}
