#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int INF = (int)1E9 + 7;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int NMAX = 300000;
const int LOG = 20;
int n, m;
vector<int> g[NMAX];
int p[LOG][NMAX], dep[NMAX], tin[NMAX], tout[NMAX], timer = 0, ord[NMAX];
struct node {
  int sum;
  node *l;
  node *r;
  node() { sum = 0, l = 0, r = 0; }
};
const int SZBUF = 4 * NMAX + LOG * 110000 * 4;
node buf[SZBUF];
int szbuf = 0;
typedef node *tree;
tree allocate() {
  if (szbuf == SZBUF) throw;
  tree cur = &buf[szbuf++];
  return cur;
}
tree copy(tree val) {
  if (!val) return allocate();
  tree ans = allocate();
  ans->sum = val->sum, ans->l = val->l, ans->r = val->r;
  return ans;
}
int get_sum(tree t) {
  if (!t) return 0;
  return t->sum;
}
tree upd(int pos, int val, tree idx, int l, int r) {
  tree t = copy(idx);
  if (l == r) {
    t->sum += val;
    return t;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    t->l = upd(pos, val, t->l, l, mid);
  else
    t->r = upd(pos, val, t->r, mid + 1, r);
  t->sum = get_sum(t->l) + get_sum(t->r);
  return t;
}
int sum(int l, int r, tree idx, int tl, int tr) {
  if (!idx) return 0;
  if (l == tl && r == tr) {
    return idx->sum;
  }
  int ans = 0, mid = (tl + tr) >> 1;
  if (l <= mid) ans += sum(l, min(mid, r), idx->l, tl, mid);
  if (r >= mid + 1) ans += sum(max(l, mid + 1), r, idx->r, mid + 1, tr);
  return ans;
}
void dfs(int v) {
  ord[timer] = v;
  tin[v] = timer++;
  for (int i = int(1); i < int(LOG); ++i) p[i][v] = p[i - 1][p[i - 1][v]];
  for (int i = 0; i < int(int((g[v]).size())); ++i) {
    int u = g[v][i];
    dep[u] = dep[v] + 1;
    dfs(u);
  }
  ord[timer] = v;
  tout[v] = timer++;
}
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int i = int(LOG) - 1; i >= 0; --i)
    if (dep[p[i][a]] > dep[b]) a = p[i][a];
  if (dep[a] != dep[b]) a = p[0][a];
  assert(dep[a] == dep[b]);
  for (int i = int(LOG) - 1; i >= 0; --i)
    if (p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
  if (a != b) a = p[0][a], b = p[0][b];
  assert(a == b);
  return a;
}
tree times[NMAX];
int getSum(int cur_time, int a, int b) {
  if (dep[a] > dep[b]) swap(a, b);
  int l = tin[a], r = tin[b];
  assert(l <= r);
  return sum(l, r, times[cur_time], 0, 2 * n - 1);
}
int getGood(int t1, int t2, int a, int b) {
  if (dep[a] > dep[b]) swap(a, b);
  int cnt = dep[b] - dep[a] + 1;
  return cnt - (getSum(t1, a, b) - getSum(t2, a, b));
}
int get_kth(int k, int t1, int t2, int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  int sa = a;
  for (int i = int(LOG) - 1; i >= 0; --i) {
    if (dep[p[i][a]] >= dep[b] && getGood(t1, t2, sa, p[i][a]) < k) a = p[i][a];
  }
  if (dep[p[0][a]] >= dep[b] && getGood(t1, t2, sa, p[0][a]) < k) {
    a = p[0][a];
  }
  return getGood(t1, t2, sa, a) == k ? a : p[0][a];
}
int main() {
  scanf("%d", &n);
  int r = -1;
  for (int i = 0; i < int(n); ++i) {
    int pi;
    scanf("%d", &pi);
    pi--;
    if (pi != -1) {
      g[pi].push_back(i);
    } else {
      r = i;
    }
    p[0][i] = (pi == -1) ? i : pi;
  }
  dfs(r);
  scanf("%d", &m);
  for (int i = 0; i < int(m); ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int idx;
      scanf("%d", &idx);
      idx--;
      times[i + 1] = upd(tin[idx], 1, times[i], 0, 2 * n - 1);
      times[i + 1] = upd(tout[idx], -1, times[i + 1], 0, 2 * n - 1);
    } else {
      int a, b, ki, yi;
      scanf("%d%d%d%d", &a, &b, &ki, &yi);
      --a, --b;
      int mid = lca(a, b);
      times[i + 1] = times[i];
      int goodA = getGood(i + 1, yi, a, a);
      int goodMid = getGood(i + 1, yi, mid, mid);
      ki += goodA;
      int part1 = getGood(i + 1, yi, a, mid),
          part2 = getGood(i + 1, yi, b, mid);
      int allk = part1 + part2 - goodMid;
      if (allk < ki)
        puts("-1");
      else {
        int ans = -1;
        if (ki <= part1)
          ans = get_kth(ki, i + 1, yi, a, mid);
        else {
          ki -= part1;
          ki += goodMid;
          assert(ki <= part2);
          ans = get_kth(part2 - ki + 1, i + 1, yi, b, mid);
        }
        printf("%d\n", (ans == b ? -1 : ans + 1));
      }
    }
  }
  return 0;
}
