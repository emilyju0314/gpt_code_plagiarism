#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const int MAXN = 1001;
int n, m1, m2, m;
struct edg {
  bitset<MAXN> a;
  bitset<MAXN> b;
  bool good;
};
pair<int, int> e1[MAXN * MAXN];
pair<int, int> e2[MAXN * MAXN];
edg a[4 * MAXN];
vector<int> e[4 * MAXN];
vector<int> eo[4 * MAXN];
bool w[4 * MAXN];
vector<int> tout;
inline int rekt(int x) {
  if (x > 0)
    return x - 1;
  else
    return 2 * n + x;
}
void dfs(int v) {
  if (w[v]) return;
  w[v] = true;
  for (int i = 0; i < e[v].size(); i++) {
    dfs(e[v][i]);
  }
  tout.push_back(v);
}
vector<int> cc;
void dfs2(int v) {
  if (w[v]) return;
  w[v] = true;
  cc.push_back(v);
  for (int i = 0; i < eo[v].size(); i++) {
    dfs2(eo[v][i]);
  }
}
bool good(edg& a, edg& b) {
  return (a.good && b.good && ((a.b ^ b.b) & a.a & b.a).none());
}
bool merg(edg& a, edg& b) {
  if (!a.good || !b.good) return false;
  if (((a.b ^ b.b) & a.a & b.a).any()) return false;
  a.a |= b.a;
  a.b |= (b.a & b.b);
  return true;
}
void solve() {
  memset(w, 0, sizeof(w));
  tout.clear();
  for (int i = 0; i < 2 * n; i++) {
    e[i].clear();
    eo[i].clear();
  }
  for (int i = 0; i < m1; i++) {
    e[m - e1[i].first].push_back(e1[i].second);
    e[m - e1[i].second].push_back(e1[i].first);
    eo[e1[i].second].push_back(m - e1[i].first);
    eo[e1[i].first].push_back(m - e1[i].second);
  }
  for (int i = 0; i < 2 * n; i++) dfs(i);
  reverse(tout.begin(), tout.end());
  for (int i = 0; i < 2 * n; i++) {
    a[i].a.reset();
    a[i].b.reset();
    a[i].good = true;
    a[i].a[min(i, m - i)] = 1, a[i].b[min(i, m - i)] = i / n;
  }
  for (int i = tout.size() - 1; i >= 0; i--) {
    int v = tout[i];
    for (int j = 0; j < e[v].size(); j++) {
      if (!merg(a[v], a[e[v][j]])) a[v].good = false;
    }
  }
  memset(w, 0, sizeof(w));
  for (int i = 0; i < tout.size(); i++) {
    cc.clear();
    int v = tout[i];
    if (w[v]) continue;
    dfs2(v);
    for (int j = 1; j < cc.size(); j++) {
      if (!merg(a[v], a[cc[j]])) a[v].good = false;
    }
    for (int j = 1; j < cc.size(); j++) {
      if (!merg(a[cc[j]], a[v])) a[cc[j]].good = false;
    }
  }
  memset(w, 0, sizeof(w));
  for (int i = 0; i < m2; i++) {
    if (good(a[m - e2[i].first], a[m - e2[i].second])) {
      edg cur;
      cur.a.reset();
      cur.b.reset();
      merg(cur, a[m - e2[i].first]);
      merg(cur, a[m - e2[i].second]);
      for (int j = 0; j < 2 * n; j++) {
        merg(cur, a[j]);
      }
      for (int j = 0; j < n; j++) {
        cout << 1 - cur.b[j] << " ";
      }
      cout << endl;
      exit(0);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  m = 2 * n - 1;
  for (int i = 0; i < m1; i++) {
    scanf("%d%d", &e1[i].first, &e1[i].second);
    e1[i] = make_pair(rekt(e1[i].first), rekt(e1[i].second));
  }
  for (int i = 0; i < m2; i++) {
    scanf("%d%d", &e2[i].first, &e2[i].second);
    e2[i] = make_pair(rekt(e2[i].first), rekt(e2[i].second));
  }
  solve();
  swap(m1, m2);
  for (int i = 0; i < max(m1, m2); i++) swap(e1[i], e2[i]);
  solve();
  cout << "SIMILAR" << endl;
  return 0;
}
