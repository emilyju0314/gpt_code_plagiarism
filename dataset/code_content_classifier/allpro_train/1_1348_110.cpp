#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > T;
vector<vector<int> > T2;
set<int> att;
bool keep[123456 + 5];
bool hasa(int from, int v) {
  keep[v] = false;
  if (att.find(v) != att.end()) keep[v] = 1;
  for (int i = 0; i < T[v].size(); ++i) {
    if (T[v][i] != from) keep[v] |= hasa(v, T[v][i]);
  }
  return keep[v];
}
map<pair<int, int>, long long> dp[2];
long long get(bool back, int from, int v) {
  pair<int, int> state(from, v);
  if (dp[back].find(state) == dp[back].end()) {
    long long ans = 0;
    for (int i = 0; i < T2[v].size(); ++i) {
      int u = T2[v][i];
      if (u == from) continue;
      ans += 2 + get(true, v, u);
    }
    long long a2 = ans;
    if (!back) {
      for (int k = 0; k < T2[v].size(); ++k) {
        int u = T2[v][k];
        if (u == from) continue;
        a2 = min(a2, ans - 2 - get(true, v, u) + 1 + get(false, v, u));
      }
    }
    dp[back][state] = a2;
  }
  return dp[back][state];
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    T.push_back(vector<int>());
    T2.push_back(vector<int>());
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    att.insert(a);
  }
  fill(keep, keep + n, false);
  hasa(-1, *att.begin());
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < T[i].size(); ++j) {
      int u = T[i][j];
      if (keep[i] && keep[u]) T2[i].push_back(u);
    }
  }
  long long vert = -1, mn = 0x7fffffffffffffff;
  for (int i = 1; i <= n; ++i) {
    if (keep[i]) {
      long long score = get(false, -1, i);
      if (score < mn) {
        vert = i;
        mn = score;
      }
    }
  }
  cout << vert << "\n" << mn << "\n";
  return 0;
}
