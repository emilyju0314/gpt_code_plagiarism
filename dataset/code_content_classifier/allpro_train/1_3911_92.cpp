#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int s_size = s.size();
  int t_size = t.size();
  vector<vector<vector<int>>> dist(
      1 + max(s_size, t_size),
      vector<vector<int>>(1 + s_size, vector<int>(1 + t_size, 1000 * 1000)));
  vector<vector<vector<array<int, 3>>>> prev(
      1 + max(s_size, t_size),
      vector<vector<array<int, 3>>>(
          1 + s_size, vector<array<int, 3>>(1 + t_size, {0, 0, 0})));
  dist[0][0][0] = 0;
  queue<array<int, 3>> q;
  q.push({0, 0, 0});
  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    if (curr[0] + 1 < dist.size()) {
      int next1 = curr[1] + (curr[1] < s_size && s[curr[1]] == '(');
      int next2 = curr[2] + (curr[2] < t_size && t[curr[2]] == '(');
      if (dist[curr[0] + 1][next1][next2] == 1000 * 1000) {
        dist[curr[0] + 1][next1][next2] = dist[curr[0]][curr[1]][curr[2]] + 1;
        prev[curr[0] + 1][next1][next2] = curr;
        q.push({curr[0] + 1, next1, next2});
      }
    }
    if (curr[0] - 1 >= 0) {
      int next1 = curr[1] + (curr[1] < s_size && s[curr[1]] == ')');
      int next2 = curr[2] + (curr[2] < t_size && t[curr[2]] == ')');
      if (dist[curr[0] - 1][next1][next2] == 1000 * 1000) {
        dist[curr[0] - 1][next1][next2] = dist[curr[0]][curr[1]][curr[2]] + 1;
        prev[curr[0] - 1][next1][next2] = curr;
        q.push({curr[0] - 1, next1, next2});
      }
    }
  }
  array<int, 3> curr = {0, s_size, t_size};
  string res = "";
  while (curr != array<int, 3>{0, 0, 0}) {
    if (prev[curr[0]][curr[1]][curr[2]][0] + 1 == curr[0]) {
      res += '(';
    } else {
      res += ')';
    }
    curr = prev[curr[0]][curr[1]][curr[2]];
  }
  reverse(res.begin(), res.end());
  cout << res << "\n";
}
