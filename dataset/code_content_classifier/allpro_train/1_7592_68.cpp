#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
const long double PI = acos(-1.0);
const long double EPS = 1e-6;
const long long INF = 1e9;
const long long LINF = 1e18;
const long long mod = 1e9 + 9;
const long long MAX = 1e5 + 47;
int n;
int globalCounter;
string s[100005];
int cnt[100005];
int p[100005];
int depth[100005];
multiset<int> byTime[100006];
vector<int> g[100006];
void push(string s) {
  int curNode = 0;
  for (int i = 0; i < s.size(); i++) {
    if (g[curNode][s[i] - 'a'] == -1) {
      g[curNode][s[i] - 'a'] = ++globalCounter;
    }
    curNode = g[curNode][s[i] - 'a'];
    cnt[curNode]++;
  }
}
int idx;
void dfs(int u) {
  int curCount = cnt[u];
  int maxSubSize = -1;
  for (int i = 0; i < 26; i++) {
    if (g[u][i] != -1) {
      curCount -= cnt[g[u][i]];
      depth[g[u][i]] = depth[u] + 1;
      dfs(g[u][i]);
      if (maxSubSize == -1 || cnt[g[u][i]] > cnt[maxSubSize]) {
        maxSubSize = i;
      }
    }
  }
  if (maxSubSize == -1) {
    p[u] = u;
    byTime[p[u]].insert(depth[u]);
    return;
  } else
    p[u] = p[g[u][maxSubSize]];
  if (p[u] == -1) cout << u << endl;
  for (int i = 0; i < 26; i++) {
    int v = g[u][i];
    if (g[u][i] != -1) {
      if (i != maxSubSize) {
        for (auto it = byTime[p[v]].begin(); it != byTime[p[v]].end(); it++)
          byTime[p[u]].insert(*it);
      }
    }
  }
  if (u == 0) {
    int ans = 0;
    for (auto it = byTime[p[u]].begin(); it != byTime[p[u]].end(); it++)
      ans += *it;
    cout << ans;
    exit(0);
  }
  if (!curCount) {
    byTime[p[u]].erase((--(byTime[p[u]].end())));
    byTime[p[u]].insert(depth[u]);
  } else {
    byTime[p[u]].insert(depth[u]);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i <= 100000; i++) {
    g[i].assign(26, -1);
    p[i] = i;
  }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) push(s[i]);
  dfs(0);
  return 0;
}
