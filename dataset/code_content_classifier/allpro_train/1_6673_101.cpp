#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int L = 21;
const int MAXN = 1.1e5;
int N, Q;
vector<int> adj[MAXN];
int par[MAXN][L];
int depth[MAXN];
int st[MAXN], ind;
void dfs(int cur = 0, int prv = -1) {
  st[cur] = ind++;
  par[cur][0] = prv;
  for (int i = 1; i < L; i++) {
    par[cur][i] = (par[cur][i - 1] == -1 ? -1 : par[par[cur][i - 1]][i - 1]);
  }
  for (int nxt : adj[cur]) {
    if (nxt == prv) continue;
    depth[nxt] = depth[cur] + 1;
    dfs(nxt, cur);
  }
}
int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int d = depth[a] - depth[b];
  for (int i = 0; (1 << i) <= d; i++) {
    if (d & (1 << i)) {
      a = par[a][i];
    }
  }
  assert(depth[a] == depth[b]);
  if (a == b) return a;
  int i = 0;
  while (par[a][i] != -1) i++;
  while (i) {
    i--;
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  }
  assert(par[a][0] == par[b][0]);
  return par[a][0];
}
vector<int> vadj[MAXN];
int K, M, root;
bool used[MAXN];
const int MAXM = 310;
int pcur = 0, pnxt = 1;
int dp[2][MAXM];
int cnt = 0;
void go(int cur = root, int prv = -1, int d = 0) {
  if (used[cur]) {
    for (int c = 0; c <= M; c++) {
      dp[pnxt][c] = (c == 0 ? 0 : dp[pcur][c - 1]);
      if (c >= d) {
        dp[pnxt][c] += ll(c - d) * dp[pcur][c] % MOD;
      }
      if (dp[pnxt][c] >= MOD) {
        dp[pnxt][c] -= MOD;
      }
    }
    cnt++;
    swap(pcur, pnxt);
  }
  for (int nxt : vadj[cur]) {
    if (nxt == prv) continue;
    go(nxt, cur, d + used[cur]);
  }
  vadj[cur].clear();
  used[cur] = false;
}
int main() {
  scanf("%d %d", &N, &Q);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  for (int q = 0; q < Q; q++) {
    scanf("%d %d %d", &K, &M, &root);
    root--;
    vector<int> verts(K);
    for (int& v : verts) {
      scanf("%d", &v);
      v--;
      used[v] = true;
    }
    verts.push_back(root);
    verts.push_back(0);
    sort(verts.begin(), verts.end(),
         [&](int a, int b) { return st[a] < st[b]; });
    verts.erase(unique(verts.begin(), verts.end()), verts.end());
    auto connect = [&](int a, int b) {
      assert(st[a] < st[b]);
      assert(depth[a] < depth[b]);
      vadj[a].push_back(b);
      vadj[b].push_back(a);
    };
    vector<int> stk;
    for (int v : verts) {
      if (stk.size() <= 1) {
        stk.push_back(v);
        continue;
      }
      int a = lca(stk.back(), v);
      if (a != stk.back()) {
        while (stk.size() > 1 && st[stk.end()[-2]] >= st[a]) {
          connect(stk.end()[-2], stk.back());
          stk.pop_back();
        }
        if (a != stk.back()) {
          assert(depth[a] < depth[stk.back()]);
          connect(a, stk.back());
          stk.back() = a;
        }
      }
      stk.push_back(v);
    }
    while (stk.size() > 1) {
      connect(stk.end()[-2], stk.back());
      stk.pop_back();
    }
    assert(stk.size());
    assert(stk.back() == 0);
    fill_n(dp[pcur] + 1, M, 0);
    dp[pcur][0] = 1;
    cnt = 0;
    go();
    assert(cnt == K);
    int ans = 0;
    for (int c = 0; c <= M; c++) {
      ans += dp[pcur][c];
      if (ans >= MOD) ans -= MOD;
    }
    printf("%d\n", ans);
  }
  return 0;
}
