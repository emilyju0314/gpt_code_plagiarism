#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 100;
int n, q;
set<string> adj[N];
vector<int> h[N];
long long int dfs(int c, int lev) {
  if (lev == (n - 1)) {
    return 1;
  }
  long long int ans = 0;
  for (auto ss : adj[c]) {
    char ch = ss[0] - 'a';
    ans += dfs(ch, lev + 1);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = (int)0; i < (int)q; i++) {
    string aa;
    char bb;
    cin >> aa >> bb;
    adj[bb - 'a'].insert(aa);
  }
  cout << dfs(0, 0) << endl;
  return 0;
}
