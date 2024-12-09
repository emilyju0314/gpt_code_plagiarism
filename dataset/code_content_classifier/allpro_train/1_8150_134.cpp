#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
const int maxlog = 18;
vector<pair<int, int> > g[maxn];
long long n, q, w;
int br, euler[maxn];
long long cost[maxn];
long long dist[maxn];
int opentt[maxn], sbtsizee[maxn];
long long aa[maxn], bb[maxn];
long long parent[maxn];
bool deleted[maxn];
int sbt[maxn], p[maxn];
int open_node[maxlog][maxn];
int opent[maxlog][maxn];
int sbtsize[maxlog][maxn];
int centroid_parent[maxn];
int centroid_root[maxlog][maxn];
int ttsize[maxn];
multiset<long long> ms[maxn], globalms;
class segment_tree {
 public:
  vector<long long> tree, lazy;
  int sz;
  void init(int _sz) {
    sz = _sz;
    tree.resize(4 * sz, 0);
    lazy.resize(4 * sz, 0);
  }
  void build(int li, int ri, int index) {
    if (li == ri) {
      tree[index] = dist[euler[li]];
    } else {
      int mid = (li + ri) / 2;
      build(li, mid, 2 * index);
      build(mid + 1, ri, 2 * index + 1);
      tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    }
  }
  void push_update(int li, int ri, int index) {
    if (lazy[index] != 0) {
      tree[index] += lazy[index];
      if (li != ri) {
        lazy[2 * index] += lazy[index];
        lazy[2 * index + 1] += lazy[index];
      }
      lazy[index] = 0;
    }
  }
  void update(int ul, int ur, long long uval, int li, int ri, int index) {
    push_update(li, ri, index);
    if (li > ur || ri < ul)
      return;
    else if (li >= ul && ri <= ur) {
      lazy[index] += uval;
      push_update(li, ri, index);
    } else {
      int mid = (li + ri) / 2;
      update(ul, ur, uval, li, mid, 2 * index);
      update(ul, ur, uval, mid + 1, ri, 2 * index + 1);
      tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    }
  }
  long long query(int ql, int qr, int li, int ri, int index) {
    push_update(li, ri, index);
    if (li > qr || ri < ql)
      return LLONG_MIN;
    else if (li >= ql && ri <= qr)
      return tree[index];
    else {
      int mid = (li + ri) / 2;
      long long lftquery = query(ql, qr, li, mid, 2 * index);
      long long rghquery = query(ql, qr, mid + 1, ri, 2 * index + 1);
      tree[index] = max(tree[2 * index], tree[2 * index + 1]);
      return max(lftquery, rghquery);
    }
  }
};
segment_tree trees[maxn];
class path {
 public:
  long long node, cost, open_time, sbt_size, froot;
};
vector<path> paths;
void get_paths(int node, int par, long long _cost, int froot) {
  euler[br] = node;
  opentt[node] = br;
  sbtsizee[node] = 1;
  br++;
  for (auto i : g[node]) {
    int nxt_node = i.first;
    long long nxt_cost = cost[i.second];
    if (nxt_node == par || deleted[nxt_node]) continue;
    get_paths(nxt_node, node, _cost + nxt_cost, froot);
    sbtsizee[node] += sbtsizee[nxt_node];
  }
  paths.push_back({node, _cost, opentt[node], sbtsizee[node], froot});
}
void precompute(int centroid, int depth) {
  br = 0;
  int total_size = 0;
  for (auto i : g[centroid]) {
    int nxt_node = i.first;
    long long nxt_cost = cost[i.second];
    if (deleted[nxt_node]) continue;
    get_paths(nxt_node, centroid, nxt_cost, nxt_node);
    total_size += sbtsizee[nxt_node];
  }
  for (auto i : paths) {
    open_node[depth][i.node] = i.froot;
    opent[depth][i.node] = i.open_time;
    sbtsize[depth][i.node] = i.sbt_size;
    dist[i.node] = i.cost;
    centroid_root[depth][i.node] = centroid;
  }
  centroid_root[depth][centroid] = centroid;
  total_size += 1;
  ttsize[centroid] = total_size;
  sbtsize[depth][centroid] = total_size - 1;
  trees[centroid].init(total_size);
  trees[centroid].build(0, total_size - 1, 1);
  for (auto i : g[centroid]) {
    int nxt_node = i.first;
    if (deleted[nxt_node]) continue;
    ms[centroid].insert(trees[centroid].query(
        opent[depth][nxt_node],
        opent[depth][nxt_node] + sbtsize[depth][nxt_node] - 1, 0,
        total_size - 1, 1));
  }
  if (ms[centroid].size() == 0) {
    paths.clear();
    return;
  }
  long long fst = *(ms[centroid].rbegin());
  ms[centroid].erase(ms[centroid].find(fst));
  long long tmp = fst;
  if (ms[centroid].size() > 0) {
    long long scd = *(ms[centroid].rbegin());
    tmp += scd;
  }
  ms[centroid].insert(fst);
  globalms.insert(tmp);
  paths.clear();
}
void dfs_sbt(int node, int par) {
  sbt[node] = 1;
  p[node] = par;
  for (auto i : g[node]) {
    int nxt_node = i.first;
    if (nxt_node == par || deleted[nxt_node]) continue;
    dfs_sbt(nxt_node, node);
    sbt[node] += sbt[nxt_node];
  }
}
int decompose(int node, int depth) {
  dfs_sbt(node, -1);
  queue<int> q;
  q.push(node);
  int min_sbt = INT_MAX;
  int ind = -1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    int curr_subtree = sbt[node] - sbt[curr];
    for (auto i : g[curr]) {
      int nxt_node = i.first;
      if (deleted[nxt_node] || nxt_node == p[curr]) continue;
      q.push(nxt_node);
      curr_subtree = max(curr_subtree, sbt[nxt_node]);
    }
    if (curr_subtree < min_sbt) {
      min_sbt = curr_subtree;
      ind = curr;
    }
  }
  deleted[ind] = true;
  precompute(ind, depth);
  for (auto i : g[ind]) {
    int nxt_node = i.first;
    if (deleted[nxt_node]) continue;
    int nxt_root = decompose(nxt_node, depth + 1);
    centroid_parent[nxt_root] = ind;
  }
  return ind;
}
void update_tree(int centroid, int edge_ind, long long edge_val, int depth) {
  int curr;
  if (sbtsize[depth][aa[edge_ind]] > sbtsize[depth][bb[edge_ind]])
    curr = bb[edge_ind];
  else
    curr = aa[edge_ind];
  if (ms[centroid].size() > 0) {
    long long fst = *(ms[centroid].rbegin());
    ms[centroid].erase(ms[centroid].find(fst));
    long long tmp = fst;
    if (ms[centroid].size() > 0) {
      long long scd = *(ms[centroid].rbegin());
      tmp += scd;
    }
    ms[centroid].insert(fst);
    globalms.erase(globalms.find(tmp));
    long long old_info =
        trees[centroid].query(opent[depth][open_node[depth][curr]],
                              opent[depth][open_node[depth][curr]] +
                                  sbtsize[depth][open_node[depth][curr]] - 1,
                              0, ttsize[centroid] - 1, 1);
    if (ms[centroid].find(old_info) != ms[centroid].end()) {
      ms[centroid].erase(ms[centroid].find(old_info));
    }
    trees[centroid].update(
        opent[depth][curr], opent[depth][curr] + sbtsize[depth][curr] - 1,
        edge_val - cost[edge_ind], 0, ttsize[centroid] - 1, 1);
    ms[centroid].insert(
        trees[centroid].query(opent[depth][open_node[depth][curr]],
                              opent[depth][open_node[depth][curr]] +
                                  sbtsize[depth][open_node[depth][curr]] - 1,
                              0, ttsize[centroid] - 1, 1));
    fst = *(ms[centroid].rbegin());
    ms[centroid].erase(ms[centroid].find(fst));
    tmp = fst;
    if (ms[centroid].size() > 0) {
      long long scd = *(ms[centroid].rbegin());
      tmp += scd;
    }
    ms[centroid].insert(fst);
    globalms.insert(tmp);
  }
}
bool star_graph() {
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (aa[i] == 1 || bb[i] == 1) cnt++;
  }
  return n - 1 == cnt;
}
int main() {
  cin >> n >> q >> w;
  for (int i = 0; i < n - 1; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    g[a].push_back(make_pair(b, i));
    g[b].push_back(make_pair(a, i));
    aa[i] = a;
    bb[i] = b;
    cost[i] = c;
  }
  if (star_graph()) {
    multiset<long long> st;
    for (int i = 0; i < n - 1; i++) {
      st.insert(cost[i]);
    }
    long long result = 0LL;
    long long lst_res = 0LL;
    while (q--) {
      long long _d, _e;
      cin >> _d >> _e;
      long long ind = (_d + lst_res) % (n - 1);
      long long nw_cost = (_e + lst_res) % w;
      st.erase(st.find(cost[ind]));
      cost[ind] = nw_cost;
      st.insert(nw_cost);
      long long fst = *(st.rbegin());
      st.erase(st.find(fst));
      result = fst;
      if (n > 2) {
        long long scd = *(st.rbegin());
        result += scd;
      }
      st.insert(fst);
      lst_res = result;
      cout << result << "\n";
    }
    return 0;
  }
  memset(centroid_root, -1, sizeof(centroid_root));
  decompose(1, 0);
  long long lst_res = 0LL;
  long long result = 0LL;
  while (q--) {
    long long _d, _e;
    cin >> _d >> _e;
    long long ind = (_d + lst_res) % (n - 1);
    long long nw_cost = (_e + lst_res) % w;
    for (int level = maxlog - 1; level >= 0; level--) {
      if (centroid_root[level][aa[ind]] == -1 ||
          centroid_root[level][bb[ind]] == -1)
        continue;
      if (centroid_root[level][aa[ind]] != centroid_root[level][bb[ind]])
        continue;
      update_tree(centroid_root[level][aa[ind]], ind, nw_cost, level);
    }
    cost[ind] = nw_cost;
    long long result = *(globalms.rbegin());
    lst_res = result;
    cout << result << "\n";
  }
}
