#include <bits/stdc++.h>
using namespace std;
int N, M, a, b, t[500100];
vector<int> g[500100];
vector<int> v;
int cmp(int x, int y) { return t[x] < t[y]; }
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 1; i <= M; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= N; ++i) {
    cin >> t[i];
    v.push_back(i);
  }
  sort(v.begin(), v.end(), cmp);
  for (auto x : v) {
    sort(g[x].begin(), g[x].end(), cmp);
    int nxt = 1;
    for (auto y : g[x]) {
      if (t[y] == nxt) ++nxt;
    }
    if (nxt != t[x]) {
      cout << -1;
      return 0;
    }
  }
  for (auto x : v) cout << x << " ";
  return 0;
}
