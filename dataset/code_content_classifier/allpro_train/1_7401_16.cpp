#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, maxk = 50, pot = 524288, Log = 19;
pair<int, int> edge[maxn];
pair<int, int> col[maxn];
int sol[maxn];
struct union_find {
  int parent[maxn];
  bool prom[maxn];
  int sz[maxn];
  union_find() {
    for (int i = 0; i < maxn; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return find(parent[x]);
  }
  bool racunaj(int x) {
    if (parent[x] == x) {
      return 0;
    }
    return racunaj(parent[x]) ^ prom[x];
  }
  int update(int x, int y) {
    bool z = 0;
    if (racunaj(x) == racunaj(y)) {
      z = 1;
    }
    x = find(x);
    y = find(y);
    if (sz[x] > sz[y]) {
      if (z) {
        prom[y] = 1;
      }
      parent[y] = x;
      return y;
    } else {
      if (z) {
        prom[x] = 1;
      }
      parent[x] = y;
      sz[y] = max(sz[y], sz[x] + 1);
      return x;
    }
  }
  bool query(int x, int y) { return find(x) == find(y); }
};
int n, m, k, qq;
union_find U[maxk];
vector<pair<int, pair<int, int> > > t[pot * 2];
vector<int> s[maxk][Log];
int prosl[maxn];
void update(int L, int D, int x, int l, int d, pair<int, pair<int, int> > val) {
  if (L >= l && D <= d) {
    t[x].push_back(val);
    return;
  }
  if ((L + D) / 2 >= l) {
    update(L, (L + D) / 2, x * 2, l, d, val);
  }
  if ((L + D) / 2 + 1 <= d) {
    update((L + D) / 2 + 1, D, x * 2 + 1, l, d, val);
  }
}
bool kontradikcija;
void rijesi(int x, int dep) {
  int i;
  pair<int, int> p;
  for (int j = 0; j < t[x].size(); j++) {
    i = t[x][j].first;
    p = t[x][j].second;
    if (sol[p.second]) {
      if (!U[i].query(edge[p.first].first, edge[p.first].second)) {
        s[i][dep].push_back(
            U[i].update(edge[p.first].first, edge[p.first].second));
      } else {
        if (U[i].racunaj(edge[p.first].first) ==
            U[i].racunaj(edge[p.first].second)) {
          kontradikcija = 1;
        }
      }
    } else {
      if (prosl[p.first] != -1) {
        if (!U[prosl[p.first]].query(edge[p.first].first,
                                     edge[p.first].second)) {
          s[prosl[p.first]][dep].push_back(U[prosl[p.first]].update(
              edge[p.first].first, edge[p.first].second));
        } else {
          if (U[prosl[p.first]].racunaj(edge[p.first].first) ==
              U[prosl[p.first]].racunaj(edge[p.first].second)) {
            kontradikcija = 1;
          }
        }
      }
    }
  }
  if (x < pot) {
    rijesi(x * 2, dep + 1);
  }
  for (int i = 0; i < k; i++) {
    while (!s[i][dep].empty()) {
      U[i].parent[s[i][dep].back()] = s[i][dep].back();
      U[i].prom[s[i][dep].back()] = 0;
      s[i][dep].pop_back();
    }
  }
}
void solve(int x, int dep) {
  int i;
  pair<int, int> p;
  for (int j = 0; j < t[x].size(); j++) {
    i = t[x][j].first;
    p = t[x][j].second;
    if (sol[p.second] == -1) {
      kontradikcija = 0;
      rijesi(x, dep);
      if (kontradikcija) {
        sol[p.second] = 0;
      } else {
        sol[p.second] = 1;
      }
    }
  }
  for (int j = 0; j < t[x].size(); j++) {
    i = t[x][j].first;
    p = t[x][j].second;
    if (sol[p.second]) {
      prosl[p.first] = i;
      if (!U[i].query(edge[p.first].first, edge[p.first].second)) {
        s[i][dep].push_back(
            U[i].update(edge[p.first].first, edge[p.first].second));
      }
    } else {
      if (prosl[p.first] != -1 &&
          !U[prosl[p.first]].query(edge[p.first].first, edge[p.first].second)) {
        s[prosl[p.first]][dep].push_back(U[prosl[p.first]].update(
            edge[p.first].first, edge[p.first].second));
      }
    }
  }
  if (x < pot) {
    solve(x * 2, dep + 1);
    solve(x * 2 + 1, dep + 1);
  }
  for (int i = 0; i < k; i++) {
    while (!s[i][dep].empty()) {
      U[i].parent[s[i][dep].back()] = s[i][dep].back();
      U[i].prom[s[i][dep].back()] = 0;
      s[i][dep].pop_back();
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &qq);
  int a, b;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    edge[i] = {a, b};
    col[i] = {-1, -1};
  }
  for (int i = 0; i < qq; i++) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if (col[a].first != -1) {
      update(0, pot - 1, 1, col[a].second, i - 1,
             {col[a].first, {a, col[a].second}});
    }
    col[a] = {b, i};
  }
  for (int i = 0; i < m; i++) {
    if (col[i].first != -1) {
      update(0, pot - 1, 1, col[i].second, pot - 1,
             {col[i].first, {i, col[i].second}});
    }
  }
  memset(sol, -1, sizeof(sol));
  memset(prosl, -1, sizeof(prosl));
  solve(1, 0);
  for (int i = 0; i < qq; i++) {
    if (sol[i]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
