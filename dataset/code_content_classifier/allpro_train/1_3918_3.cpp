#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) { return (ull)rng() % B; }
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const int N = 10010;
int n;
vector<int> g[N];
int sz[N];
bool bad[N];
vector<pii> ans;
void dfsSz(int v, int par) {
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == par || bad[u]) continue;
    dfsSz(u, v);
    sz[v] += sz[u];
  }
}
int getCentr(int v) {
  dfsSz(v, -1);
  int S = sz[v];
  while (true) {
    int w = v;
    for (int u : g[v]) {
      if (bad[u]) continue;
      if (sz[u] > sz[v]) continue;
      if (2 * sz[u] >= S) {
        w = u;
      }
    }
    if (w == v) break;
    v = w;
  }
  return v;
}
void addEdges(int v, int par, int to) {
  ans.push_back(make_pair(v, to));
  for (int u : g[v]) {
    if (bad[u] || u == par) continue;
    addEdges(u, v, to);
  }
}
int solve(int v, int oldc, int oldv) {
  v = getCentr(v);
  dfsSz(v, -1);
  vector<pii> sons;
  for (int u : g[v]) {
    if (bad[u]) continue;
    sons.push_back(make_pair(sz[u], u));
  }
  bad[v] = 1;
  if (oldc != -1) {
    addEdges(oldv, oldc, oldc);
    ans.push_back(make_pair(v, oldc));
  }
  sort((sons).begin(), (sons).end());
  reverse((sons).begin(), (sons).end());
  for (int i = 0; i < (int)sons.size(); i++) {
    int u = sons[i].second;
    if (i == 0 && oldc == -1) {
      solve(u, v, u);
    } else {
      addEdges(u, v, v);
      solve(u, -1, -1);
    }
  }
  return v;
}
int main() {
  startTime = clock();
  int k;
  scanf("%d%d", &n, &k);
  set<pii> hv;
  for (int i = 1; i < n; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    hv.insert(make_pair(v, u));
    hv.insert(make_pair(u, v));
    g[v].push_back(u);
    g[u].push_back(v);
  }
  solve(1, -1, -1);
  vector<pii> nans;
  for (pii t : ans)
    if (hv.count(t) == 0) nans.push_back(t);
  if ((int)nans.size() > 10 * n) throw;
  printf("%d\n", (int)nans.size());
  for (pii t : nans) {
    printf("%d %d\n", t.first + 1, t.second + 1);
  }
  return 0;
}
