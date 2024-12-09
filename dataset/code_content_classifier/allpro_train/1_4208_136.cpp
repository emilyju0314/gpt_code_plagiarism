#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 9, LG = 19;
vector<pair<int, int> > g[MAXN];
int dep[MAXN];
int par[MAXN][LG];
long long dis[MAXN];
inline void dfs(int node, int from) {
  par[node][0] = from;
  for (int i = 1; i < LG; ++i) {
    par[node][i] = par[par[node][i - 1]][i - 1];
  }
  for (int i = 0; i < (int)g[node].size(); ++i) {
    int next = g[node][i].first;
    if (next != from) {
      dep[next] = dep[node] + 1;
      dis[next] = dis[node] + g[node][i].second;
      dfs(next, node);
    }
  }
}
int getKth(int node, int k) {
  for (int i = LG - 1; i >= 0; --i) {
    if ((1 << i) <= k) {
      node = par[node][i];
      k -= (1 << i);
    }
  }
  return node;
}
long long A[MAXN];
long long B[MAXN];
long long ans[MAXN];
void calc(int x, int N) {
  int lo = 0;
  int hi = dep[x];
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    int kth = getKth(x, mid);
    long long d = dis[x] - dis[kth];
    if (d <= A[x]) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  int kth = getKth(x, lo);
  B[x] += 1;
  B[par[kth][0]] -= 1;
}
inline long long dfs2(int node, int from) {
  long long s = 0;
  for (int i = 0; i < (int)g[node].size(); ++i) {
    int next = g[node][i].first;
    if (next != from) {
      s += dfs2(next, node);
    }
  }
  ans[node] = B[node] + s;
  return (s + B[node]);
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%lld", &A[i]);
  }
  for (int i = 2; i <= N; ++i) {
    int x, w;
    scanf("%d%d", &x, &w);
    g[x].push_back(make_pair(i, w));
    g[i].push_back(make_pair(x, w));
  }
  memset(B, 0, sizeof B);
  dis[0] = 0;
  dis[1] = 0;
  dep[1] = 0;
  dfs(1, 0);
  for (int i = 2; i <= N; ++i) {
    calc(i, N);
  }
  dfs2(1, 0);
  ans[1] += 1;
  for (int i = 1; i <= N; ++i) {
    printf("%lld ", ans[i] - 1);
  }
  cout << "\n";
  return 0;
}
