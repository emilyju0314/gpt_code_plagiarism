#include <bits/stdc++.h>
using namespace std;
struct Item {
  string s;
  int a[3];
  int k, sz;
};
struct Resi {
  string s, fa;
  int k, v;
};
int n, m;
Item a[1005];
Resi b[1005];
map<string, int> gg1, gg2, f;
vector<int> v[1005];
bool cmp(const int& l, const int& r) { return b[l].v > b[r].v; }
void gao0() {
  for (int j = 0; j < m; ++j) {
    int k = f[b[j].fa];
    a[k].a[b[j].k] += b[j].v;
    v[k].push_back(j);
  }
  for (int c = 0; c < 3; ++c) {
    int mx = -1, mi;
    for (int i = 0; i < n; ++i)
      if (a[i].k == c) {
        if (a[i].a[c] > mx) {
          mx = a[i].a[c];
          mi = i;
        }
      }
    printf("%s %d", a[mi].s.c_str(), v[mi].size());
    for (vector<int>::iterator it = v[mi].begin(); it != v[mi].end(); ++it)
      printf(" %s", b[*it].s.c_str());
    puts("");
  }
}
int pi[3], ci[3];
vector<int> pr[3];
bool vis[1005];
void gao1(int sumsz) {
  int gao = 0;
  memset(vis, 0, sizeof(vis));
  for (int c = 0; c < 3; ++c) {
    for (int i = 0; i < n; ++i) v[i].clear();
    for (int j = 0; j < m; ++j)
      if (b[j].k == c)
        for (int i = 0; i < n; ++i)
          if (a[i].k == c) v[i].push_back(j);
    int mx = -1, mi;
    for (int i = 0; i < n; ++i)
      if (a[i].k == c) {
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < a[i].sz && j < v[i].size(); ++j)
          a[i].a[c] += b[v[i][j]].v;
        if (a[i].a[c] > mx) {
          mx = a[i].a[c];
          mi = i;
        }
      }
    int cc = a[mi].sz;
    if (cc > v[mi].size()) cc = v[mi].size();
    pi[c] = mi;
    ci[c] = cc;
    for (int j = 0; j < a[mi].sz && j < v[mi].size(); ++j) {
      vis[v[mi][j]] = 1;
      pr[c].push_back(v[mi][j]);
    }
    sumsz -= a[mi].sz;
  }
  sumsz = max(0, m - sumsz);
  for (int c = 0; c < 3; ++c)
    for (int j = 0; j < m && pr[c].size() < a[pi[c]].sz && sumsz; ++j)
      if (!vis[j]) {
        pr[c].push_back(j);
        vis[j] = 1;
        --sumsz;
        ++ci[c];
      }
  for (int c = 0; c < 3; ++c) {
    printf("%s %d", a[pi[c]].s.c_str(), ci[c]);
    for (vector<int>::iterator it = pr[c].begin(); it != pr[c].end(); ++it)
      printf(" %s", b[*it].s.c_str());
    puts("");
  }
}
int main() {
  gg1["weapon"] = 0;
  gg1["armor"] = 1;
  gg1["orb"] = 2;
  gg2["gladiator"] = 0;
  gg2["sentry"] = 1;
  gg2["physician"] = 2;
  char str[100];
  int sumsz = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", str);
    f[str] = i;
    a[i].s = str;
    scanf("%s", str);
    a[i].k = gg1[str];
    for (int j = 0; j < 3; ++j) scanf("%d", &a[i].a[j]);
    scanf("%d", &a[i].sz);
    sumsz += a[i].sz;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%s", str);
    b[i].s = str;
    scanf("%s", str);
    b[i].k = gg2[str];
    scanf("%d", &b[i].v);
    scanf("%s", str);
    b[i].fa = str;
  }
  if (sumsz == m)
    gao0();
  else
    gao1(sumsz);
  return 0;
}
