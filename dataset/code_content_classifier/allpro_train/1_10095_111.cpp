#include <bits/stdc++.h>
using namespace std;
const int mxn = 1024;
int n;
char a[mxn];
int p[mxn];
vector<int> adj[mxn];
int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}
int dp[mxn];
int solve(int v) {
  if (dp[v] != -1) return dp[v];
  dp[v] = 1;
  for (int j = 0; j < adj[v].size(); j++) {
    dp[v] = max(dp[v], 1 + solve(adj[v][j]));
  }
  return dp[v];
}
int main(int argc, char** argv) {
  scanf("%d", &n);
  scanf("%s", a);
  for (int i = 0; i < n; i++) p[i] = i;
  vector<int> F, T;
  for (int i = 0; i + 1 < n; i++) {
    int f = i, t = i + 1;
    if (a[i] == '=') {
      int pf = find(f);
      int pt = find(t);
      p[pf] = pt;
    } else {
      if (a[i] == 'R') {
        swap(f, t);
      }
      F.push_back(f);
      T.push_back(t);
    }
  }
  for (int i = 0; i < (int)F.size(); i++) {
    int f = find(F[i]);
    int t = find(T[i]);
    adj[f].push_back(t);
  }
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) {
    printf("%d", solve(find(i)));
    if (i + 1 == n)
      puts("");
    else
      printf(" ");
  }
  return 0;
}
