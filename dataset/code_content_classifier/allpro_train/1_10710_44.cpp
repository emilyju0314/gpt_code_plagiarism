#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, vis[maxn];
string z, s;
vector<vector<int> > v;
set<pair<char, char> > st;
void dfs(int x, int par) {
  if (vis[x]) return;
  vis[x] = 1;
  if (par != -1) {
    st.insert(make_pair(char(x + 97), char(par + 97)));
  }
  for (int i = 0; i < v[x].size(); i++) {
    dfs(v[x][i], x);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  v.resize(maxn);
  cin >> z >> s;
  for (int i = 0; i < n; i++) {
    if (z[i] != s[i]) {
      v[z[i] - 97].push_back(s[i] - 97);
      v[s[i] - 97].push_back(z[i] - 97);
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!vis[i]) {
      dfs(i, -1);
    }
  }
  cout << st.size() << '\n';
  for (set<pair<char, char> >::iterator it = st.begin(); it != st.end(); it++)
    cout << (*it).first << " " << (*it).second << '\n';
}
