#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
string s, t;
int n;
vector<pair<int, int> > ans;
vector<int> v[2][N];
void add(int a, int b) {
  while (!v[0][a].empty() && !v[1][b].empty())
    ans.push_back({v[0][a].back(), v[1][b].back()}), v[0][a].pop_back(),
        v[1][b].pop_back();
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  ;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    v[0][s[i]].push_back(i + 1);
    v[1][t[i]].push_back(i + 1);
  }
  for (char ch = 'a'; ch <= 'z'; ch++) add(ch, ch);
  for (char ch = 'a'; ch <= 'z'; ch++) add('?', ch), add(ch, '?');
  add('?', '?');
  cout << ans.size() << endl;
  for (auto x : ans) cout << x.first << " " << x.second << endl;
  return 0;
}
