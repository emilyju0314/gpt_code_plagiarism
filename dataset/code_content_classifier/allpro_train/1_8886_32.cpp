#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-12;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 4;
const int maxm = 1e5 + 4;
inline long long rule(long long x) { return (x %= MOD) += x < 0 ? MOD : 0; }
vector<int> words[maxn], G[maxn];
int n, m;
int tag[maxn];
int judge(int a, int b) {
  int l = min(words[a].size(), words[b].size());
  for (int i = 0; i < l; ++i) {
    int x = words[a][i], y = words[b][i];
    if (x < y) {
      G[y].push_back(x);
      return 1;
    } else if (x > y) {
      tag[x] |= 1;
      tag[y] |= 2;
      if (tag[x] == 3 || tag[y] == 3) return 0;
      return 1;
    }
  }
  if (l == words[a].size()) return 1;
  return 0;
}
bool vis[maxn];
void dfs(int u) {
  tag[u] |= 1;
  for (auto v : G[u])
    if (!vis[v]) {
      dfs(v);
    }
}
int main() {
  int ik, i, j, k, kase;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &j);
      words[i].push_back(j);
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (!judge(i - 1, i)) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (tag[i] == 1 && !vis[i]) dfs(i);
  }
  for (int i = 1; i <= m; ++i)
    if (tag[i] == 3) {
      puts("No");
      return 0;
    }
  puts("Yes");
  vector<int> ans;
  for (int i = 1; i <= m; ++i) {
    if (tag[i] == 1) ans.push_back(i);
  }
  printf("%d\n", int(ans.size()));
  for (int i = 0; i < ans.size(); ++i)
    printf("%d%c", ans[i], " \n"[i == (ans.size() - 1)]);
  return 0;
}
