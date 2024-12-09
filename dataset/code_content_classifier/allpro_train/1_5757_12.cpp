#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int head[maxn];
long long dp[maxn];
int k, n, m;
struct Edge {
  int u, v, next;
} e[4 * maxn];
void addedge(int u, int v) {
  e[++k] = Edge{u, v, head[u]};
  head[u] = k;
  e[++k] = Edge{v, u, head[v]};
  head[v] = k;
}
int main() {
  k = 0;
  memset(head, -1, sizeof head);
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    addedge(a, b);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    int tmp = 0;
    for (int j = head[i]; ~j; j = e[j].next) {
      tmp++;
      int v = e[j].v;
      if (v < i) {
        dp[i] = max(dp[i], dp[v] + 1);
      }
    }
    ans = max(ans, 1LL * dp[i] * tmp);
  }
  cout << ans << endl;
}
