#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
vector<int> g[100010];
int res[100010];
void dfs(int x, int l = 0) {
  res[l]++;
  for (int i = 0; i < g[x].size(); i++) {
    dfs(g[x][i], l + 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    g[x].push_back(i);
  }
  dfs(1);
  int r = 0;
  for (int i = 0; i < n; i++) {
    r += res[i] % 2;
  }
  cout << r;
}
