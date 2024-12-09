#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > g;
void endProg() {
  cout << "NO";
  exit(0);
}
void dfs(long long v, long long p) {
  long long l = 0;
  for (auto i : g[v]) {
    if (i == p) continue;
    if (g[i].size() == 1) {
      l++;
      continue;
    }
    dfs(i, v);
  }
  if (v == 0) {
    if (g[v].size() == 2) endProg();
  } else {
    if (g[v].size() == 2) endProg();
  }
}
int main() {
  long long n;
  cin >> n;
  g.resize(n);
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs(0, 0);
  cout << "YES";
  return 0;
}
