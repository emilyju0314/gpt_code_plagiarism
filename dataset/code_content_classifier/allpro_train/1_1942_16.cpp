#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
long long INF = 2e18;
const int MAXN = 2e6 + 10;
long long n, m, b, dp[MAXN];
struct Node {
  int x, k, m;
  friend bool operator<(const Node A, const Node B) { return A.k < B.k; }
} node[110];
int main() {
  cin >> n >> m >> b;
  for (int i = 1; i <= n; i++) {
    int temp;
    scanf("%d%d%d", &node[i].x, &node[i].k, &temp);
    int sum = 0;
    for (int j = 1; j <= temp; j++) {
      int x;
      scanf("%d", &x);
      sum += 1 << (x - 1);
    }
    node[i].m = sum;
  }
  sort(node + 1, node + 1 + n);
  long long ans = INF;
  for (int j = (1 << m) - 1; j >= 0; j--) dp[j] = INF;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = (1 << m) - 1; j >= 0; j--) {
      if (dp[j] >= INF) continue;
      dp[j | node[i].m] = min(dp[j | node[i].m], dp[j] + node[i].x);
    }
    ans = min(ans, dp[(1 << m) - 1] + node[i].k * b);
  }
  if (ans >= INF)
    printf("-1\n");
  else
    printf("%lld\n", ans);
  return 0;
}
