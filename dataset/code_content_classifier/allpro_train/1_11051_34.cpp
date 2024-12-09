#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1073741824")
using namespace std;
const int MAXN = 5100;
int c[MAXN], d[MAXN], sz[MAXN];
long long int dp[MAXN][MAXN];
vector<int> v[MAXN];
bool cmp(int a, int b) { return v[a].size() > v[b].size(); }
void cSize(int node) {
  sz[node] = 1;
  for (int to : v[node]) {
    cSize(to);
    sz[node] += sz[to];
  }
  sort(v[node].begin(), v[node].end(), cmp);
}
void dfs(int node, vector<int> &a) {
  dp[node][1] = c[node] - d[node];
  dp[node][0] = 0;
  vector<int> ma;
  int s = 1;
  for (int to : v[node]) {
    dfs(to, ma);
    for (int i = s; i >= 1; i--)
      for (int j = 1; j <= sz[to]; j++)
        dp[node][i + j] = min(dp[node][i + j], dp[node][i] + dp[to][j]);
    s += sz[to];
  }
  ma.push_back(c[node]);
  a.insert(a.end(), ma.begin(), ma.end());
  sort(ma.begin(), ma.end());
  long long int sum = 0;
  for (int i = 1; i <= ma.size(); i++) {
    sum += ma[i - 1];
    dp[node][i] = min(dp[node][i], sum);
  }
}
int main() {
#pragma warning(disable : 4996)
  int n, b;
  scanf("%d%d", &n, &b);
  memset(dp, 127, sizeof(dp));
  ;
  scanf("%d%d", &c[0], &d[0]);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d%d%d", &c[i], &d[i], &p);
    v[p - 1].push_back(i);
  }
  vector<int> a;
  cSize(0);
  dfs(0, a);
  for (int i = 0; i <= n; i++) {
    if (dp[0][i + 1] > b) {
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}
