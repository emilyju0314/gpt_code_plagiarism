#include <bits/stdc++.h>
using namespace std;
vector<set<int>> g(26);
vector<set<int>> g_t(26);
vector<int> used(26);
string dfs(int v) {
  used[v] = 1;
  for (auto i = g[v].begin(); i != g[v].end(); i++) {
    int to = *i;
    if (!used[to])
      return string(1, char(v + 'a')) + dfs(to);
    else
      return "!";
  }
  return string(1, char(v + 'a'));
}
int main() {
  int n;
  cin >> n;
  set<int> us;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) us.insert(s[j]);
    for (int j = 0; j < s.size() - 1; j++) {
      int from = s[j] - 'a', to = s[j + 1] - 'a';
      g[from].insert(to);
      g_t[to].insert(from);
    }
  }
  bool f = true;
  set<string> block;
  for (int i = 0; i < 26; i++)
    if (g[i].size() > 1 || g_t[i].size() > 1) return cout << "NO", 0;
  for (int i = 0; i < 26; i++) {
    if (us.count(i + 'a') && !g_t[i].size()) {
      string str = dfs(i);
      if (str[str.size() - 1] == '!') return cout << "NO", 0;
      block.insert(str);
    }
  }
  set<char> used_let;
  for (auto i : block) {
    for (char x : i) used_let.insert(x);
  }
  for (auto x : us)
    if (!used_let.count(x)) return cout << "NO", 0;
  for (auto i : block) cout << i;
  return 0;
}
