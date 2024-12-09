#include <bits/stdc++.h>
using namespace std;
const int INFL = (int)1e9;
const long long int INFLL = (long long int)1e18;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;
const long long int MOD = (long long int)1e9 + 7;
class Extended_Euclid {
 private:
  long long int m, n;
  vector<vector<long long int>> mx_multiply(vector<vector<long long int>> mx1,
                                            vector<vector<long long int>> mx2) {
    vector<vector<long long int>> ret(mx1.size(),
                                      vector<long long int>(mx2[0].size(), 0));
    for (int i = 0; i < (int)mx1.size(); i++) {
      for (int j = 0; j < (int)mx1[0].size(); j++) {
        for (int k = 0; k < (int)mx2[0].size(); k++) {
          ret[i][j] += mx1[i][k] * mx2[k][j];
        }
      }
    }
    return ret;
  }
  bool adjust_into_range(
      long long int m, long long int n, long long int *x, long long int *y,
      pair<long long int, long long int> x_range = {LLONG_MIN, LLONG_MAX},
      pair<long long int, long long int> y_range = {LLONG_MIN, LLONG_MAX}) {
    if ((*x) < x_range.first && (*y) < y_range.first) return false;
    if ((*x) > x_range.second && (*y) > y_range.second) return false;
    long long int d;
    if ((*y) > y_range.second) {
      d = ((long long int)(*y) - y_range.second / (long long int)m +
           ((long long int)(*y) - y_range.second % (long long int)m == 0 ? 0
                                                                         : 1));
      (*x) += n * d;
      (*y) -= m * d;
      if ((*x) > x_range.second || (*y) < y_range.first) return false;
    }
    if ((*y) < y_range.first) {
      d = ((long long int)y_range.first - (*y) / (long long int)m +
           ((long long int)y_range.first - (*y) % (long long int)m == 0 ? 0
                                                                        : 1));
      (*x) -= n * d;
      (*y) += m * d;
      if ((*x) < x_range.first || (*y) > y_range.second) return false;
    }
    if ((*x) < x_range.first) {
      d = ((long long int)x_range.first - (*x) / (long long int)n +
           ((long long int)x_range.first - (*x) % (long long int)n == 0 ? 0
                                                                        : 1));
      (*x) += n * d;
      (*y) -= m * d;
      if ((*x) > x_range.second || (*y) < y_range.first) return false;
    }
    if ((*x) > x_range.second) {
      d = ((long long int)(*x) - x_range.second / (long long int)n +
           ((long long int)(*x) - x_range.second % (long long int)n == 0 ? 0
                                                                         : 1));
      (*x) -= n * d;
      (*y) += m * d;
      if ((*x) < x_range.first || (*y) > y_range.second) return false;
    }
    return true;
  }

 public:
  long long int x, y, gcd;
  Extended_Euclid(long long int M, long long int N) {
    m = M;
    n = N;
    vector<long long int> r(100), k(100);
    bool swapflag = false, m_negflag = false, n_negflag = false;
    if (m < n) {
      swap(m, n);
      swapflag = true;
    }
    if (m < 0) {
      m *= -1;
      m_negflag = true;
    }
    if (n < 0) {
      n *= -1;
      n_negflag = true;
    }
    r[0] = m;
    r[1] = n;
    int h = 1;
    while (1) {
      k[h - 1] = r[h - 1] / r[h];
      r[h + 1] = r[h - 1] % r[h];
      if (r[h + 1] == 0) break;
      h++;
    }
    gcd = r[h];
    vector<vector<long long int>> mx1 = {{0, 1}, {1, (-1) * k[h - 1]}};
    for (int i = (int)h - 1 - 1; i >= 0; i--) {
      vector<vector<long long int>> mx2 = {{0, 1}, {1, (-1) * k[i]}};
      mx1 = mx_multiply(mx1, mx2);
    }
    x = mx1[0][0];
    y = mx1[0][1];
    if (n_negflag) {
      n *= -1;
      y *= -1;
    }
    if (m_negflag) {
      m *= -1;
      x *= -1;
    }
    if (swapflag) {
      swap(m, n);
      swap(x, y);
    }
  }
  bool solve_equation(long long int r, long long int *x, long long int *y,
                      pair<long long int, long long int> x_range = {LLONG_MIN,
                                                                    LLONG_MAX},
                      pair<long long int, long long int> y_range = {
                          LLONG_MIN, LLONG_MAX}) {
    if (r % gcd != 0)
      return false;
    else {
      bool m_negflag = false, n_negflag = false;
      if (m < 0) {
        m *= -1;
        this->x *= -1;
        x_range = {-x_range.second, -x_range.first};
        m_negflag = true;
      }
      if (n < 0) {
        n *= -1;
        this->y *= -1;
        y_range = {-y_range.second, -y_range.first};
        n_negflag = true;
      }
      long long int ret_x = this->x * (r / gcd);
      long long int ret_y = this->y * (r / gcd);
      bool valid =
          adjust_into_range(m / gcd, n / gcd, &ret_x, &ret_y, x_range, y_range);
      if (n_negflag) {
        n *= -1;
        this->y *= -1;
        ret_y *= -1;
      }
      if (m_negflag) {
        m *= -1;
        this->x *= -1;
        ret_x *= -1;
      }
      if (!valid)
        return false;
      else {
        *x = ret_x;
        *y = ret_y;
        return true;
      }
    }
  }
};
namespace mod_op {
long long int modify(long long int n) {
  long long int ret;
  if (n > 0)
    ret = n - n / MOD * MOD;
  else
    ret = n - (n - MOD + 1) / MOD * MOD;
  return ret;
}
long long int mul(long long int x, long long int y) { return x * y % MOD; }
long long int add(long long int x, long long int y) { return (x + y) % MOD; }
long long int sub(long long int x, long long int y) { return modify(x - y); }
vector<long long int> factlist(long long int n) {
  if (n < 0)
    return {};
  else {
    vector<long long int> ret((int)n + 1);
    ret[0] = 1;
    for (int i = 1; i <= (int)(int)n; i++) ret[i] = mul(ret[i - 1], i);
    return ret;
  }
}
long long int powm(long long int n, long long int p) {
  if (p == 0)
    return 1;
  else if (p == 1)
    return n;
  else {
    long long int ans = powm(n, p / 2);
    ans = mul(ans, ans);
    if (p % 2 == 1) ans = mul(ans, n);
    return ans;
  }
}
long long int inv(long long int n) {
  Extended_Euclid ee(n, MOD * (-1));
  return modify(ee.x);
}
long long int mod_combination(long long int n, long long int r) {
  vector<long long int> facts = factlist(n);
  return mul(facts[(unsigned)n],
             inv(mul(facts[(unsigned)r], facts[(unsigned)(n - r)])));
}
long long int divm(long long int x, long long int y) { return mul(x, inv(y)); }
long long int disc_log(long long int a, long long int b) {
  long long int m =
      (long long int)((double)sqrt(MOD) + (sqrt(MOD) >= 0 ? 0.5 : -0.5)) + 1;
  unordered_map<long long int, long long int> mp;
  long long int y = 1;
  for (int i = 0; i < (int)m; i++) {
    mp[y] = i;
    y = mul(y, a);
  }
  y = inv(powm(a, m));
  long long int k = b;
  for (int i = 0; i < (int)m; i++) {
    if (mp.find(k) == mp.end())
      k = mul(k, y);
    else
      return i * m + mp[k];
  }
  return -1;
}
}  // namespace mod_op
using namespace mod_op;
struct tree_t {
  int n;
  vector<pair<int, int>> edges;
  vector<long long int> vals;
  vector<long long int> costs;
};
class Tree {
 private:
  struct node {
    int id;
    vector<int> childs;
    int parent;
    int deg;
    int eid;
    int subtree_n;
    long long int val;
    long long int cost;
  };
  struct edgeinfo {
    int eid;
    int to;
    long long int cost;
  };
  int n;
  static const long long int init_val = 0;
  static const long long int init_cost = 1;

 public:
  vector<node> nodes;
  vector<int> deg_order;
  vector<int> leaves;
  int root;
  Tree(tree_t T, int root = -1) {
    n = T.n;
    nodes.resize(n);
    for (int i = 0; i < (int)n; i++)
      nodes[i] = {
          i, {}, -1, -1, -1, 1, T.vals.size() > i ? T.vals[i] : 0, init_cost};
    vector<vector<edgeinfo>> edges(n);
    for (int i = 0; i < (int)n - 1; i++) {
      edges[T.edges[i].first].push_back(
          {i, T.edges[i].second,
           (T.costs.size() > i ? T.costs[i] : init_cost)});
      edges[T.edges[i].second].push_back(
          {i, T.edges[i].first, (T.costs.size() > i ? T.costs[i] : init_cost)});
    }
    if (root < 0) {
      int max_d = -1;
      for (int i = 0; i < (int)n; i++) {
        if (edges[i].size() > max_d) {
          Tree::root = i;
          max_d = edges[i].size();
        }
      }
    } else {
      Tree::root = min(root, n - 1);
    }
    leaves = {};
    queue<int> que;
    que.push(Tree::root);
    while (que.size()) {
      int a = que.front();
      que.pop();
      deg_order.push_back(a);
      if (a == Tree::root) nodes[a].deg = 0;
      int leaf_flag = true;
      for (int i = 0; i < (int)edges[a].size(); i++) {
        int b = edges[a][i].to;
        if (nodes[b].deg != -1) {
          nodes[a].parent = b;
          nodes[a].eid = edges[a][i].eid;
          nodes[a].cost = edges[a][i].cost;
          nodes[a].deg = nodes[b].deg + 1;
        } else {
          leaf_flag = false;
          nodes[a].childs.push_back(b);
          que.push(b);
        }
      }
      if (leaf_flag) leaves.push_back(a);
    }
    for (int i = (int)n - 1; i >= 0; i--) {
      int a = deg_order[i];
      for (int j = 0; j < (int)nodes[a].childs.size(); j++) {
        int b = nodes[a].childs[j];
        nodes[a].subtree_n += nodes[b].subtree_n;
      }
    }
    return;
  }
  vector<int> solve_node_inclusion_cnt_in_all_path(
      bool enable_single_node_path) {
    vector<int> ret(n, 0);
    for (int i = 0; i < (int)n; i++) {
      int a = i;
      for (int j = 0; j < (int)nodes[a].childs.size(); j++) {
        int b = nodes[a].childs[j];
        ret[i] +=
            nodes[b].subtree_n * (nodes[a].subtree_n - nodes[b].subtree_n - 1);
      }
      ret[i] /= 2;
      ret[i] += (nodes[a].subtree_n - 1) * (n - nodes[a].subtree_n);
      ret[i] += n - 1;
      if (enable_single_node_path) ret[i]++;
    }
    return ret;
  }
  vector<int> solve_edge_inclusion_cnt_in_all_path() {
    vector<int> ret(n - 1, 0);
    for (int i = 0; i < (int)n; i++) {
      int eid = nodes[i].eid;
      if (eid < 0) continue;
      ret[eid] = nodes[i].subtree_n * (n - nodes[i].subtree_n);
    }
    return ret;
  }
  long long int solve() {
    vector<long long int> subtree_evencnt(n, 0);
    vector<long long int> pathcnt(n, 0);
    int all_even_cnt = 0;
    for (int i = 0; i < (int)n; i++) {
      if (nodes[i].deg % 2 == 0) all_even_cnt++;
    }
    for (int i = (int)n - 1; i >= 0; i--) {
      int a = deg_order[i];
      for (int j = 0; j < (int)nodes[a].childs.size(); j++) {
        int b = nodes[a].childs[j];
        subtree_evencnt[a] += subtree_evencnt[b];
      }
      if (nodes[a].deg % 2 == 0) subtree_evencnt[a]++;
    }
    for (int i = 0; i < (int)n; i++) {
      int a = i;
      for (int j = 0; j < (int)nodes[a].childs.size(); j++) {
        int b = nodes[a].childs[j];
        pathcnt[a] +=
            subtree_evencnt[b] * (subtree_evencnt[a] - subtree_evencnt[b] -
                                  (nodes[a].deg % 2 == 0 ? 1 : 0));
      }
      pathcnt[a] += (subtree_evencnt[a] - (nodes[a].deg % 2 == 0 ? 1 : 0)) *
                    (all_even_cnt - subtree_evencnt[a]) * 2;
      if (nodes[a].deg % 2 == 0) pathcnt[a] += (all_even_cnt - 1) * 2;
      if (nodes[a].deg % 2 == 0) pathcnt[a]++;
    }
    long long int ret = 0;
    for (int i = 0; i < (int)n; i++) {
      if (nodes[i].deg % 2 == 0) {
        ret = add(ret, mul(nodes[i].val, modify(pathcnt[i])));
      } else {
        ret = sub(ret, mul(nodes[i].val, modify(pathcnt[i])));
      }
    }
    return ret;
  }
};
int main() {
  tree_t T;
  cin >> T.n;
  for (int i = 0; i < (int)T.n; i++) {
    long long int x;
    cin >> x;
    T.vals.push_back(modify(x));
  }
  for (int i = 0; i < (int)T.n - 1; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    T.edges.push_back({s, t});
  }
  Tree tree(T, 0);
  int r0 = tree.leaves[0];
  int r1 = tree.nodes[r0].parent;
  Tree tree0(T, r0), tree1(T, r1);
  long long int ans = add(tree0.solve(), tree1.solve());
  cout << ans << endl;
}
