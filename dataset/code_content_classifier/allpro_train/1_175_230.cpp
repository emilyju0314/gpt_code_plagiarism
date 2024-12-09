#include <bits/stdc++.h>
using namespace std;
vector<int> let[26];
int n;
const int maxn = 1e5;
int get_id[26][maxn];
string s;
void build() {
  for (int i = 0; i < 26; ++i) {
    int st = n, id = 0;
    if (let[i].size()) st = let[i][0];
    for (int j = 0; j < n; ++j) {
      if (s[j] - 'a' == i) ++id;
      if (id < let[i].size())
        st = let[i][id];
      else
        st = n;
      get_id[i][j] = st;
    }
  }
}
int get_next(int num, char ch) {
  if (num == -1) {
    if (let[ch - 'a'].size()) return let[ch - 'a'][0];
    return n;
  }
  if (num == n) return n;
  return get_id[ch - 'a'][num];
}
void solve() {
  int q;
  cin >> n >> q;
  cin >> s;
  for (int i = 0; i < n; ++i) let[s[i] - 'a'].push_back(i);
  build();
  int dp[3][251][251];
  for (int i = 0; i <= 250; ++i)
    for (int j = 0; j <= 250; ++j) dp[0][i][j] = n;
  for (int i = 0; i <= 250; ++i)
    for (int j = 0; j <= 250; ++j) dp[1][i][j] = n;
  for (int i = 0; i <= 250; ++i)
    for (int j = 0; j <= 250; ++j) dp[2][i][j] = n;
  vector<string> st(3);
  dp[0][0][0] = -1;
  dp[1][0][0] = -1;
  dp[2][0][0] = -1;
  while (q) {
    --q;
    char type;
    cin >> type;
    if (type == '-') {
      int num;
      cin >> num;
      --num;
      st[num].erase(st[num].begin() + st[num].size() - 1);
      for (int i = 0; i < 251; ++i)
        for (int j = 0; j < 251; ++j) dp[num][i][j] = n;
      dp[num][0][0] = -1;
      for (int i = 0; i <= st[(num + 1) % 3].size(); ++i) {
        for (int j = 0; j <= st[(num + 2) % 3].size(); ++j) {
          if (i)
            dp[num][i][j] =
                min(dp[num][i][j],
                    get_next(dp[num][i - 1][j], st[(num + 1) % 3][i - 1]));
          if (j)
            dp[num][i][j] =
                min(dp[num][i][j],
                    get_next(dp[num][i][j - 1], st[(num + 2) % 3][j - 1]));
        }
      }
      for (int i = 0; i < st[num].size(); ++i) {
        for (int j = 0; j <= st[(num + 1) % 3].size(); ++j) {
          for (int k = 0; k <= st[(num + 2) % 3].size(); ++k) {
            int val = get_next(dp[num][j][k], st[num][i]);
            if (j)
              val = min(val,
                        get_next(dp[num][j - 1][k], st[(num + 1) % 3][j - 1]));
            if (k)
              val = min(val,
                        get_next(dp[num][j][k - 1], st[(num + 2) % 3][k - 1]));
            dp[num][j][k] = val;
          }
        }
      }
      for (int i = 0; i <= st[(num + 2) % 3].size(); ++i)
        dp[(num + 1) % 3][i][st[num].size() + 1] = n;
      for (int i = 0; i <= st[(num + 1) % 3].size(); ++i)
        dp[(num + 2) % 3][st[num].size() + 1][i] = n;
    } else {
      int num;
      char ch;
      cin >> num >> ch;
      --num;
      st[num] += ch;
      for (int i = 0; i <= st[(num + 1) % 3].size(); ++i) {
        for (int j = 0; j <= st[(num + 2) % 3].size(); ++j) {
          int val = get_next(dp[num][i][j], ch);
          if (i)
            val =
                min(val, get_next(dp[num][i - 1][j], st[(num + 1) % 3][i - 1]));
          if (j)
            val =
                min(val, get_next(dp[num][i][j - 1], st[(num + 2) % 3][j - 1]));
          dp[num][i][j] = val;
        }
      }
      for (int i = 0; i <= st[(num + 2) % 3].size(); ++i)
        dp[(num + 1) % 3][i][st[num].size()] =
            dp[num][st[(num + 1) % 3].size()][i];
      for (int i = 0; i <= st[(num + 1) % 3].size(); ++i)
        dp[(num + 2) % 3][st[num].size()][i] =
            dp[num][i][st[(num + 2) % 3].size()];
    }
    if (dp[0][st[1].size()][st[2].size()] != n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
