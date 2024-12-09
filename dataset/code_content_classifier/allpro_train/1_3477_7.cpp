#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 2020;
int n;
int N[2];
int p[2][maxn];
int X[2][maxn];
int cost[2][maxn][maxn];
void build_cost(int t) {
  for (int l = 1; l <= n; l++) {
    vector<int> deg(N[t] + 1, 0);
    for (int i = 2; i <= N[t]; i++) {
      deg[p[t][i]]++;
    }
    int res = 0;
    for (int r = l; r <= n; r++) {
      int v = X[t][r];
      while (v != 1 && deg[v] == 0) {
        deg[p[t][v]]--;
        v = p[t][v];
        res++;
      }
      cost[t][l][r] = res;
    }
  }
}
int dp[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < 2; i++) {
    cin >> N[i];
    for (int v = 2; v <= N[i]; v++) {
      cin >> p[i][v];
    }
    for (int j = 1; j <= n; j++) {
      cin >> X[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    build_cost(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] = max(dp[i], dp[j - 1] + max(cost[0][j][i], cost[1][j][i]));
    }
  }
  cout << dp[n] << endl;
  return 0;
}
