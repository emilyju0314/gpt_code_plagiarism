#include <bits/stdc++.h>
using namespace std;
const int MAXM = 100001;
const int MAXV = 200001;
const int MAXE = 500001;
const int MAXL = 51;
struct query {
  int id, l, r;
};
typedef char str[MAXL];
typedef int verArr[MAXV];
typedef int edgArr[MAXE];
int n, m, p, v, k, w, H, N, tk, sid;
verArr lk, lt, rt, dep, dfn, snm;
edgArr nx, tl;
vector<int> ht[MAXV], nm[MAXV];
vector<query> q[MAXV];
int ans[MAXM];
str name;
map<string, int> id;
map<int, int> s;
inline int ID(const string& s) {
  if (id.count(s) > 0)
    return id[s];
  else
    return id[s] = ++sid;
}
inline void addEdge(int u, int v) {
  if (!w) w++;
  w++, nx[w] = lk[u], lk[u] = w, tl[w] = v;
  w++, nx[w] = lk[v], lk[v] = w, tl[w] = u;
}
inline void DFS(int u, int p) {
  dfn[u] = ++tk;
  ht[dep[u]].push_back(dfn[u]);
  nm[dep[u]].push_back(snm[u]);
  lt[u] = tk;
  for (int e = lk[u]; e > 0; e = nx[e]) {
    int v = tl[e];
    if (v != p) {
      dep[v] = dep[u] + 1;
      DFS(v, u);
    }
  }
  rt[u] = tk;
}
inline bool cmp(const query& a, const query& b) {
  int a_pos = a.l / N, b_pos = b.l / N;
  return a_pos < b_pos || (a_pos == b_pos && a.r < b.r);
}
inline void doInsert(int& res, int dep, int l, int r) {
  for (int i = l; i <= r; ++i) {
    int j = nm[dep][i];
    if (!s[j]) res++;
    s[j]++;
  }
}
inline void doErase(int& res, int dep, int l, int r) {
  for (int i = l; i <= r; ++i) {
    int j = nm[dep][i];
    s[j]--;
    if (!s[j]) res--;
  }
}
inline void whileProcess() {
  N = (int)sqrt((double)n);
  for (int i = 1; i <= n; ++i) H = max(H, dep[i]);
  for (int i = 1; i <= H; ++i) {
    sort(q[i].begin(), q[i].end(), cmp);
    s.clear();
    int res = 0, L = 1, R = 0;
    for (int j = 0; j < (int)q[i].size(); ++j) {
      if (q[i][j].l < L) doInsert(res, i, q[i][j].l, L - 1);
      if (q[i][j].l > L) doErase(res, i, L, q[i][j].l - 1);
      if (q[i][j].r < R) doErase(res, i, q[i][j].r + 1, R);
      if (q[i][j].r > R) doInsert(res, i, R + 1, q[i][j].r);
      L = q[i][j].l, R = q[i][j].r;
      ans[q[i][j].id] = res;
    }
  }
}
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s %d\n", name, &p);
    snm[i] = ID(name);
    addEdge(i, p);
  }
  DFS(0, -1);
  scanf("%d\n", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d\n", &v, &k);
    int DEP = dep[v] + k;
    int L =
        lower_bound(ht[DEP].begin(), ht[DEP].end(), lt[v]) - ht[DEP].begin();
    int R =
        upper_bound(ht[DEP].begin(), ht[DEP].end(), rt[v]) - ht[DEP].begin();
    q[DEP].push_back((query){i, L, R - 1});
  }
  whileProcess();
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
