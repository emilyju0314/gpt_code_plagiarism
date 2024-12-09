#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
const int N = 1e5 + 10;
vector<pair<int, int>> ad[N];
int n;
long long int ans;
long long int dfs(int v, int par) {
  long long int re = 0;
  for (auto ed : ad[v])
    if (ed.first != par) re = max(ed.second + dfs(ed.first, v), re);
  return re;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    ad[x].push_back({y, z});
    ad[y].push_back({x, z});
    ans += 2ll * z;
  }
  ans -= dfs(1, 0);
  printf("%I64d\n", ans);
  return 0;
}
