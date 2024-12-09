#include <bits/stdc++.h>
using namespace std;
const long long MN = 200111;
long long deg[MN];
vector<long long> ke[MN];
vector<long long> ls[MN];
map<long long, long long> id[MN];
void dfs(long long u, long long fu, long long last) {
  long long c = 0;
  for (long long v : ke[u]) {
    if (v == fu) continue;
    ++c;
    if (c == last) ++c;
    ls[c].push_back(id[u][v]);
    dfs(v, u, c);
  }
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout << (fixed) << setprecision(9);
  long long n;
  while (scanf("%lld", &n) == 1) {
    for (long long i = (1), _b = (n); i <= _b; ++i) {
      ke[i].clear();
      deg[i] = 0;
      id[i].clear();
      ls[i].clear();
    }
    for (long long i = (1), _b = (n - 1); i <= _b; ++i) {
      long long u, v;
      scanf("%lld%lld", &u, &v);
      ke[u].push_back(v);
      ke[v].push_back(u);
      ++deg[u];
      ++deg[v];
      id[u][v] = i;
      id[v][u] = i;
    }
    long long root = 1;
    for (long long i = (2), _b = (n); i <= _b; ++i)
      if (deg[i] > deg[root]) root = i;
    dfs(root, -1, 0);
    printf("%lld\n", deg[root]);
    for (long long i = (1), _b = (deg[root]); i <= _b; ++i) {
      printf("%lld", ((long long)(ls[i]).size()));
      for (auto p : ls[i]) printf(" %lld", p);
      puts("");
    }
  }
}
