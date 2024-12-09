#include <bits/stdc++.h>
using namespace std;
struct _ {
  ios_base::Init i;
  _() {
    cin.sync_with_stdio(0);
    cin.tie(0);
  }
} _;
const int maxn = 200000;
vector<int> graph[maxn];
long long ef[maxn];
long long dp[3][maxn];
void dfs(int v) {
  dp[0][v] = 0;
  dp[1][v] = LLONG_MIN / 4;
  for (int i = 0; i < (int)graph[v].size(); ++i) {
    int to = graph[v][i];
    dfs(to);
    long long pre = dp[0][v];
    dp[0][v] =
        max(max(pre + dp[0][to], dp[1][v] + dp[1][to]), dp[1][v] + dp[2][to]);
    dp[1][v] = max(max(pre + dp[1][to], dp[1][v] + dp[0][to]), pre + dp[2][to]);
  }
  dp[2][v] = dp[0][v] + ef[v];
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int p;
    long long a;
    cin >> p >> a;
    --p;
    if (p != -2) graph[p].push_back(i);
    ef[i] = a;
  }
  dfs(0);
  cout << max(max(dp[0][0], dp[1][0]), dp[2][0]);
  return 0;
}
