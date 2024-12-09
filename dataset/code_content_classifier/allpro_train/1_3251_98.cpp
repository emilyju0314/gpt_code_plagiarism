#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int par[N], sz[N];
int n, m;
int s, t, ds, dt;
int root(int x) {
  while (x != par[x]) {
    par[x] = par[par[x]];
    x = par[x];
  }
  return x;
}
void onion(int x, int y) {
  if (x == y) return;
  if (sz[x] < sz[y]) {
    par[x] = y;
    sz[y] += sz[x];
  } else {
    par[y] = x;
    sz[x] += sz[y];
  }
}
vector<pair<int, int> > adjs[N], adjt[N];
bool vstd[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  vector<pair<int, int> > e, sol, se, te, ste, reg;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    e.push_back({x, y});
  }
  cin >> s >> t >> ds >> dt;
  for (int i = 0; i < m; i++) {
    int x = e[i].first, y = e[i].second;
    if ((x == s && y == t) || (x == t && y == s)) {
      ste.push_back({x, y});
      continue;
    }
    if (x == s || y == s) {
      se.push_back({x, y});
      continue;
    }
    if (x == t || y == t) {
      te.push_back({x, y});
      continue;
    }
    reg.push_back({x, y});
  }
  for (int i = 0; i < (int)reg.size(); i++) {
    int x = reg[i].first, y = reg[i].second;
    x = root(x);
    y = root(y);
    if (x == y) continue;
    sol.push_back({reg[i].first, reg[i].second});
    onion(x, y);
  }
  for (int i = 0; i < (int)se.size(); i++) {
    int x = se[i].first, y = se[i].second;
    x = root(x);
    y = root(y);
    if (x == s) {
      adjs[y].push_back(se[i]);
    } else {
      adjs[x].push_back(se[i]);
    }
  }
  for (int i = 0; i < (int)te.size(); i++) {
    int x = te[i].first, y = te[i].second;
    x = root(x);
    y = root(y);
    if (x == t) {
      adjt[y].push_back(te[i]);
    } else {
      adjt[x].push_back(te[i]);
    }
  }
  vector<int> roots;
  for (int i = 1; i <= n; i++) {
    int x = root(i);
    if (vstd[x]) continue;
    vstd[x] = true;
    if (!adjs[x].empty() && !adjt[x].empty()) {
      roots.push_back(x);
      continue;
    }
    if (!adjs[x].empty()) {
      sol.push_back(adjs[x][0]);
      onion(root(adjs[x][0].first), root(adjs[x][0].second));
      ds--;
    }
    if (!adjt[x].empty()) {
      sol.push_back(adjt[x][0]);
      onion(root(adjt[x][0].first), root(adjt[x][0].second));
      dt--;
    }
  }
  if (!roots.empty()) {
    ds--;
    dt--;
    sol.push_back(adjs[roots.back()][0]);
    onion(root(adjs[roots.back()][0].first),
          root(adjs[roots.back()][0].second));
    sol.push_back(adjt[roots.back()][0]);
    onion(root(adjt[roots.back()][0].first),
          root(adjt[roots.back()][0].second));
    roots.pop_back();
  } else {
    if (!ste.empty()) {
      ds--;
      dt--;
      sol.push_back(ste[0]);
      onion(root(ste[0].first), root(ste[0].second));
    }
  }
  while (sz[root(1)] != n && !roots.empty() && ds > 0) {
    ds--;
    sol.push_back(adjs[roots.back()][0]);
    onion(root(adjs[roots.back()][0].first),
          root(adjs[roots.back()][0].second));
    roots.pop_back();
  }
  while (sz[root(1)] != n && !roots.empty() && dt > 0) {
    dt--;
    sol.push_back(adjt[roots.back()][0]);
    onion(root(adjt[roots.back()][0].first),
          root(adjt[roots.back()][0].second));
    roots.pop_back();
  }
  if (ds < 0 || dt < 0 || sz[root(1)] != n) {
    cout << "No";
    return 0;
  }
  cout << "Yes\n";
  for (int i = 0; i < (int)sol.size(); i++) {
    cout << sol[i].first << " " << sol[i].second << '\n';
  }
  return 0;
}
