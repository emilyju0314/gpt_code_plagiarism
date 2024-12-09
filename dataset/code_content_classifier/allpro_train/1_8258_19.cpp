#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
int n, m;
inline int Num(int a, char t) {
  a--;
  if (t == 'L')
    return a;
  else if (t == 'R')
    return a + n;
  else if (t == 'T')
    return a + n + n;
  else if (t == 'B')
    return a + n + n + m;
}
inline char Side(int a) {
  if (a < n)
    return 'L';
  else if (a < n + n)
    return 'R';
  else if (a < n + n + m)
    return 'T';
  else
    return 'B';
}
vector<int> g[N];
inline void make_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
int rt;
bool vis[N];
string s1, s2;
vector<int> p1, p2;
vector<string> vs;
vector<vector<int>> pp;
int P[N];
inline int T_T(string &s) {
  int l = s.length(), i = 0, j = 1, k = 0;
  for (; i < l && j < l && k < l;)
    if (s[(i + k) % l] == s[(j + k) % l])
      k++;
    else {
      if (s[(i + k) % l] > s[(j + k) % l])
        i += k + 1;
      else
        j += k + 1;
      if (i == j) j++;
      k = 0;
    }
  return min(i, j);
}
inline void O_O(string &s, vector<int> &rs) {
  memset(vis, 0, sizeof(vis));
  vs.clear();
  pp.clear();
  for (int i = 0; i < n + n + m + m; i++)
    if (!vis[i]) {
      string cs, t1, t2;
      vector<int> cp;
      int pr = i, cu = g[i][0];
      for (cp.push_back(pr), cp.push_back(cu);;) {
        int r = g[cu][pr == g[cu][0]];
        if (r == i) break;
        cp.push_back(r);
        pr = cu;
        cu = r;
      }
      for (auto &a : cp) vis[a] = 1, cs.push_back(Side(a));
      int tp1 = T_T(cs);
      for (int j = 0; j < cp.size(); j++)
        t1.push_back(cs[(tp1 + j) % cp.size()]);
      reverse(cs.begin(), cs.end());
      int tp2 = T_T(cs);
      for (int j = 0; j < cp.size(); j++)
        t2.push_back(cs[(tp2 + j) % cp.size()]);
      if (t2 < t1) t2.swap(t1), swap(tp1, tp2), reverse(cp.begin(), cp.end());
      vs.push_back(t1);
      vector<int> tt;
      for (int j = 0; j < cp.size(); j++)
        tt.push_back(cp[(tp1 + j) % cp.size()]);
      pp.push_back(tt);
    }
  for (int i = 0; i < vs.size(); i++) P[i] = i;
  sort(P, P + vs.size(), [](int a, int b) -> bool { return vs[a] < vs[b]; });
  for (int i = 0; i < vs.size(); i++) {
    s += vs[P[i]];
    s += "#";
    for (auto &x : pp[P[i]]) rs.push_back(x);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) make_edge(Num(i, 'L'), Num(i, 'R'));
  for (int i = 1; i <= m; i++) make_edge(Num(i, 'T'), Num(i, 'B'));
  for (int i = 1; i <= n + m; i++) {
    char a[2], b[2];
    int u, v;
    scanf("%s%s%d%d", a, b, &u, &v);
    make_edge(Num(u, a[0]), Num(v, b[0]));
    if (a[0] == 'R' && b[0] == 'T' || a[0] == 'T' && b[0] == 'R') rt++;
  }
  O_O(s1, p1);
  for (int i = 0; i < n + n + m + m; i++) g[i].clear();
  for (int i = 1; i <= n; i++) make_edge(Num(i, 'L'), Num(i, 'R'));
  for (int i = 1; i <= m; i++) make_edge(Num(i, 'T'), Num(i, 'B'));
  if (n < m) {
    for (int i = 1; i <= n - rt; i++)
      make_edge(Num(i, 'L'), Num(i, 'T')),
          make_edge(Num(m - i + 1, 'B'), Num(n - i + 1, 'R'));
    for (int i = 1; i <= rt; i++)
      make_edge(Num(n - i + 1, 'L'), Num(i, 'B')),
          make_edge(Num(m - i + 1, 'T'), Num(i, 'R'));
    for (int i = 1; i <= m - n; i++)
      make_edge(Num(n - rt + i, 'T'), Num(rt + i, 'B'));
  } else {
    for (int i = 1; i <= m - rt; i++)
      make_edge(Num(i, 'L'), Num(i, 'T')),
          make_edge(Num(m - i + 1, 'B'), Num(n - i + 1, 'R'));
    for (int i = 1; i <= rt; i++)
      make_edge(Num(n - i + 1, 'L'), Num(i, 'B')),
          make_edge(Num(m - i + 1, 'T'), Num(i, 'R'));
    for (int i = 1; i <= n - m; i++)
      make_edge(Num(m - rt + i, 'L'), Num(rt + i, 'R'));
  }
  O_O(s2, p2);
  if (s1 != s2)
    puts("No solution");
  else {
    for (int i = 0; i < p1.size(); i++) P[p2[i]] = p1[i];
    for (int i = 0; i < n; i++) printf("%d ", P[i] + 1);
    puts("");
    for (int i = n + n; i < n + n + m; i++) printf("%d ", P[i] - n - n + 1);
    puts("");
  }
  return 0;
}
