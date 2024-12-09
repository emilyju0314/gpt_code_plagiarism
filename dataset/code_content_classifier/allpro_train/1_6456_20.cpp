#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> mas(n);
  for (int i = 0, a; i < k; i++) {
    cin >> a;
    a--;
    mas[a] = true;
  }
  vector<vector<int>> g(n);
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> ans;
  vector<int> ans1;
  vector<bool> used(n, false);
  long long answer = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      int foo = -1;
      long long cnt = 1;
      long long cnt1 = 0;
      if (mas[i] == true) foo = i;
      queue<int> q;
      q.push(i);
      used[i] = true;
      while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int j = 0; j < g[f].size(); j++) {
          cnt1++;
          if (!used[g[f][j]]) {
            q.push(g[f][j]);
            if (mas[g[f][j]] == true) foo = g[f][j];
            used[g[f][j]] = true;
            cnt++;
          }
        }
      }
      if (foo == -1)
        ans1.push_back(cnt);
      else
        ans.push_back(cnt);
      cnt1 /= 2;
      answer += cnt * (cnt - 1) / 2 - cnt1;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans1.size(); i++) {
    answer += ans1[i] * ans[ans.size() - 1];
    ans[ans.size() - 1] += ans1[i];
  }
  cout << answer;
  return 0;
}
