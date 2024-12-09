#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  vector<int> v;
  for (int i = 0; i < n; i++)
    if (s1[i] != s2[i]) v.push_back(i);
  if (v.size() != 0 && v.size() != 2) {
    cout << "No" << endl;
  } else if (s1[v[0]] != s1[v[1]] || s2[v[0]] != s2[v[1]]) {
    cout << "No" << endl;
  } else
    cout << "Yes" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
