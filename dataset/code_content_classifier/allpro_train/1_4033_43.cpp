#include <bits/stdc++.h>
using namespace std;
string g[200];
set<int> del;
string ans = "";
int n, m;
int ss = 0;
bool real() {
  for (int i = 0; i < n; i++) {
    if (del.count(i) == 0 && g[i].size() == ss) {
      int cur = ss;
      for (int j = 0; j < ss; j++)
        if (ans[j] == '?' || ans[j] == g[i][j]) cur--;
      if (!cur) return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  for (int i = 0, x; i < m; ++i) {
    cin >> x;
    if (ss != 0 && g[x - 1].size() != ss) {
      cout << "No";
      return 0;
    }
    del.insert(x - 1);
    ss = g[x - 1].size();
  }
  for (int i = 0; i < ss; i++) {
    bool razn = 0;
    char first = g[*del.begin()][i];
    for (auto x : del) {
      if (g[x][i] != first) razn = 1;
    }
    if (razn)
      ans += "?";
    else
      ans += first;
  }
  if (real())
    cout << "Yes\n" << ans;
  else
    cout << "No";
}
