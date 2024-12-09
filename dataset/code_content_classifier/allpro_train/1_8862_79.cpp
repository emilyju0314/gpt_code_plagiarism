#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int N, X;
int a[1024];
int dp[1024][1024];
int used[1024];
void scan() {
  cin >> N >> X;
  for (int i = 1; i <= N; ++i) {
    cin >> a[i];
    if (a[i]) used[a[i]] = 1;
  }
}
vector<int> go(int idx) {
  vector<int> res;
  while (idx != 0) {
    res.push_back(idx);
    idx = a[idx];
  }
  reverse(res.begin(), res.end());
  return res;
}
void solve() {
  for (int i = 1; i <= N; ++i)
    if (!used[i]) v.push_back(go(i));
  for (int i = 0; i < v.size(); ++i) {
    int is = 0;
    for (int j = 0; j < v[i].size(); ++j)
      if (v[i][j] == X) {
        v[i].erase(v[i].begin() + j + 1, v[i].end());
        is = 1;
        break;
      }
    if (is) {
      swap(v[i], v.back());
      break;
    }
  }
  if (v.size() == 1) {
    cout << v[0].size() << endl;
    return;
  }
  dp[0][v[0].size()] = 1;
  dp[0][0] = 1;
  for (int i = 1; i < (int)v.size() - 1; ++i) {
    memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
    for (int j = N; j >= v[i].size(); --j)
      if (dp[i][j - v[i].size()]) dp[i][j] = 1;
  }
  for (int j = 0; j <= N; ++j)
    if (dp[v.size() - 2][j] == 1) cout << j + v.back().size() << endl;
}
int main() {
  scan();
  solve();
}
