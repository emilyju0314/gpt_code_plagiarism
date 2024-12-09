#include <bits/stdc++.h>
using namespace std;
vector<string> val;
void gerar(int x, string s, int sum) {
  if (sum == x) val.push_back(s);
  for (char i = '1'; i <= '9'; i++) {
    bool pos = true;
    int l = i - '0';
    if (x % l == 0 && l < x) pos = false;
    for (int j = s.size() - 1; j >= 0; j--) {
      l += s[j] - '0';
      if (x % l == 0 && l < x) pos = false;
    }
    if (pos && l <= x) gerar(x, s + i, l);
  }
}
const int K = 11;
struct Vertex {
  int next[K];
  bool leaf = false;
  int p = -1;
  char pch;
  int link = -1;
  int go[K];
  Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
  }
};
vector<Vertex> t(1);
void add_string(string const& s) {
  int v = 0;
  for (char ch : s) {
    int c = ch - '0';
    if (t[v].next[c] == -1) {
      t[v].next[c] = t.size();
      t.emplace_back(v, ch);
    }
    v = t[v].next[c];
  }
  t[v].leaf = true;
}
int go(int v, char ch);
int get_link(int v) {
  if (t[v].link == -1) {
    if (v == 0 || t[v].p == 0)
      t[v].link = 0;
    else
      t[v].link = go(get_link(t[v].p), t[v].pch);
  }
  return t[v].link;
}
int go(int v, char ch) {
  int c = ch - '0';
  if (t[v].go[c] == -1) {
    if (t[v].next[c] != -1)
      t[v].go[c] = t[v].next[c];
    else
      t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
  }
  return t[v].go[c];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int x;
  cin >> s >> x;
  gerar(x, "", 0);
  for (auto st : val) add_string(st);
  int v = t.size(), n = s.size();
  vector<vector<int>> dp;
  dp.assign(v + 1, vector<int>(n + 1, 2000));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int pos = 0; pos <= v; pos++) {
      if (dp[pos][i] == 2000) continue;
      int u = go(pos, s[i]);
      if (!t[u].leaf) dp[u][i + 1] = min(dp[u][i + 1], dp[pos][i]);
      dp[pos][i + 1] = min(dp[pos][i + 1], dp[pos][i] + 1);
    }
  }
  int ans = 2000;
  for (int pos = 0; pos <= v; pos++) {
    if (dp[pos][n] <= ans) ans = dp[pos][n];
  }
  cout << ans << endl;
}
