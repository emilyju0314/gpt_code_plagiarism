#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
constexpr int infValue =
    std::is_same<T, int>::value ? 2000100007 : 8600000000000000007ll;
template <typename T>
constexpr int maxValue =
    std::is_same<T, int>::value ? 1000000007 : 1000000000000000001ll;
const int INF = infValue<int>;
const long long MOD = 1000000007ll;
const double EPS = 1e-6;
const int MAX = maxValue<int>;
int n, m, pd = 1;
int d[300111];
bool p[300111];
vector<pair<int, int>> g[300111];
bool u[300111], del[300111];
int dc;
bool dfs(int v) {
  u[v] = true;
  for (auto to : g[v]) {
    if (!u[to.first]) {
      if (dfs(to.first)) {
        p[v] ^= 1;
        del[to.second] = true, ++dc;
      }
    }
  }
  if (d[v] == 1 && !p[v]) return true;
  if (!d[v] && p[v]) return true;
  return false;
}
int main(void) {
  scanf("%d %d", &n, &m);
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", d + i);
    if (d[i] < 0) pd = i;
  }
  int u, v;
  for (register int i = 1; i <= m; ++i)
    scanf("%d %d", &u, &v), g[u].push_back({v, i}), g[v].push_back({u, i}),
        p[v] ^= 1, p[u] ^= 1;
  if (dfs(pd))
    puts("-1");
  else {
    printf("%d\n", m - dc);
    for (int i = 1, j = 0; i <= m; ++i) {
      if (!del[i]) printf("%d\n", i);
    }
  }
  return 0;
}
