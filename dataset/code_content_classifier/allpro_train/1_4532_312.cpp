#include <bits/stdc++.h>
using namespace std;
long long n, d[100010];
double ans;
vector<int> a[100010];
void dfs(long long u, long long fa, long long d) {
  ans = ans + 1.00000000000000 / d;
  for (int i = 0, v; i < a[u].size(); ++i) {
    v = a[u][i];
    if (v != fa) {
      dfs(v, u, d + 1);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  d[1] = 1;
  dfs(1, 0, 1);
  printf("%.20lf", ans);
  return 0;
}
