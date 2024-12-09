#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 100;
int lm[N], low[N], num[N], Time, lab[N], Bri[N], L[N], R[N], W[N], Val[N],
    Res[N];
map<int, int> Map[N], id[N];
vector<int> a[N], ed[N], vec;
int n, m, A, B, cnt;
void dfs(int u, int par) {
  low[u] = num[u] = ++Time;
  for (int v : a[u]) {
    if (v == par) continue;
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      dfs(v, u);
      if (low[v] >= num[v]) Bri[id[u][v]] = 1;
      low[u] = min(low[u], low[v]);
    }
  }
}
int get(int u) { return lab[u] == u ? u : lab[u] = get(lab[u]); }
bool dfs2(int u, int par) {
  if (u == B) return 1;
  for (int v : ed[u]) {
    if (v == par) continue;
    if (dfs2(v, u)) {
      vec.push_back(v);
      return 1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int u, v, c, x, y;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> c;
    a[u].push_back(v);
    a[v].push_back(u);
    id[u][v] = id[v][u] = i;
    L[i] = u;
    R[i] = v;
    W[i] = c;
  }
  cin >> A >> B;
  dfs(1, 1);
  for (int i = 1; i <= n; ++i) lab[i] = i;
  for (int i = 1; i <= m; ++i) {
    u = L[i];
    v = R[i];
    if (!Bri[i]) {
      x = get(u);
      y = get(v);
      if (x != y) {
        lab[y] = x;
      }
      Val[x] = max(Val[x], max(Val[y], W[i]));
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (get(i) == i) {
      ++cnt;
      lm[i] = cnt;
      Res[cnt] = Val[i];
    }
  }
  for (int i = 1; i <= m; ++i) {
    u = L[i];
    v = R[i];
    if (Bri[i]) {
      x = get(u);
      y = get(v);
      ed[lm[x]].push_back(lm[y]);
      ed[lm[y]].push_back(lm[x]);
      Map[lm[x]][lm[y]] = Map[lm[y]][lm[x]] = max(W[i], Map[lm[y]][lm[x]]);
    }
  }
  if (get(A) == get(B)) {
    if (Val[get(A)]) {
      cout << "YES";
    } else
      cout << "NO";
    return 0;
  }
  A = lm[get(A)];
  B = lm[get(B)];
  vec.push_back(A);
  dfs2(A, A);
  for (int i = 0; i < vec.size(); ++i) {
    if (Res[vec[i]]) {
      cout << "YES";
      return 0;
    }
    if (i + 1 < vec.size()) {
      if (Map[vec[i]][vec[i + 1]]) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
