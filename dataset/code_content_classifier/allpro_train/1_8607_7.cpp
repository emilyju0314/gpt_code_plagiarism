#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100000 + 10;
int n1, n2, n3;
long long D1, E2;
class Tree {
 public:
  int head[MaxN], nxt[MaxN << 1], to[MaxN << 1], top, son[MaxN], size;
  long long totaldis[MaxN], PD[MaxN], PE[MaxN];
  bool vis[MaxN];
  void addedge(int fr, int tt) {
    top++;
    nxt[top] = head[fr];
    to[top] = tt;
    head[fr] = top;
  }
  long long dfs1(int x, int c) {
    vis[x] = true;
    long long ret = c;
    son[x] = 1;
    for (int i = head[x]; i; i = nxt[i])
      if (!vis[to[i]]) {
        ret += dfs1(to[i], c + 1);
        son[x] += son[to[i]];
      }
    return ret;
  }
  void dfs2(int x) {
    vis[x] = true;
    for (int i = head[x]; i; i = nxt[i])
      if (!vis[to[i]]) {
        totaldis[to[i]] = totaldis[x] + (long long)size - 2LL * son[to[i]];
        dfs2(to[i]);
      }
  }
  long long dfs3(int x) {
    vis[x] = true;
    long long ret, v1, v2;
    PD[x] = (long long)n1 * totaldis[x];
    PE[x] = (long long)n3 * totaldis[x];
    ret = PD[x] + PE[x];
    for (int i = head[x]; i; i = nxt[i])
      if (!vis[to[i]]) {
        ret = max(ret, dfs3(to[i]));
        v1 = PD[to[i]] + ((long long)n1 * (long long)n3);
        v2 = PE[to[i]] + ((long long)n1 * (long long)n3);
        if (v1 + PE[x] > ret) ret = v1 + PE[x];
        if (v2 + PD[x] > ret) ret = v2 + PD[x];
        if (v1 > PD[x]) PD[x] = v1;
        if (v2 > PE[x]) PE[x] = v2;
      }
    return ret;
  }
  void ReadIn(int n) {
    int a, b;
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &a, &b);
      addedge(a, b);
      addedge(b, a);
    }
    size = n;
  }
  void clearVis() {
    for (int i = 1; i <= size; ++i) vis[i] = false;
  }
  long long calcIn() {
    long long ret = 0;
    for (int i = 1; i <= size; ++i) ret += totaldis[i];
    ret /= 2;
    return ret;
  }
  long long findMax() {
    long long mx = totaldis[1];
    for (int i = 2; i <= size; ++i)
      if (totaldis[i] > mx) mx = totaldis[i];
    return mx;
  }
  void clear() {
    clearVis();
    for (int i = 1; i <= size; ++i) son[i] = totaldis[i] = PD[i] = PE[i] = 0;
  }
} T1, T2, T3;
void init() {
  scanf("%d%d%d", &n1, &n2, &n3);
  T1.ReadIn(n1);
  T2.ReadIn(n2);
  T3.ReadIn(n3);
}
long long solve_sub(Tree &T1, Tree &T2, Tree &T3) {
  D1 = E2 = 0;
  n1 = T1.size;
  n2 = T2.size;
  n3 = T3.size;
  T1.clear();
  T2.clear();
  T3.clear();
  T1.totaldis[1] = T1.dfs1(1, 0);
  T2.totaldis[1] = T2.dfs1(1, 0);
  T3.totaldis[1] = T3.dfs1(1, 0);
  T1.clearVis();
  T2.clearVis();
  T3.clearVis();
  T1.dfs2(1);
  T2.dfs2(1);
  T3.dfs2(1);
  T1.clearVis();
  T2.clearVis();
  T3.clearVis();
  long long ret = T1.calcIn() + T2.calcIn() + T3.calcIn();
  D1 = T1.findMax();
  E2 = T3.findMax();
  ret += (long long)(n2 + n3) * D1;
  ret += (long long)(n1 + n2) * E2;
  ret += T2.dfs3(1);
  ret += (long long)n1 * (long long)n2 + (long long)n2 * (long long)n3 +
         2LL * (long long)n1 * (long long)n3;
  return ret;
}
long long ans;
void solve() {
  ans = max(ans, solve_sub(T2, T1, T3));
  ans = max(ans, solve_sub(T1, T2, T3));
  ans = max(ans, solve_sub(T1, T3, T2));
  cout << ans << endl;
}
int main() {
  init();
  solve();
  return 0;
}
