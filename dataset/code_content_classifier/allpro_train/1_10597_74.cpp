#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
long long n, x, y, m;
long double ev;
vector<long long> adj[KL];
void dfs(long long node, long long pr, long long cnt) {
  ev += 1.0 / (long double)cnt;
  for (auto v : adj[node]) {
    if (pr == v) continue;
    dfs(v, node, cnt + 1);
  }
}
int main() {
  scanf("%lld", &n);
  m = n - 1;
  while (m--) {
    scanf("%lld", &x);
    scanf("%lld", &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0, 1);
  cout << fixed << setprecision(20) << ev << endl;
  return 0;
}
