#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
string op(string temp) {
  string s = temp;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0')
      s[i] = '1';
    else
      s[i] = '0';
  }
  reverse(s.begin(), s.end());
  return s;
}
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  string rev = b;
  vector<int> v;
  if (a == b) {
    cout << 0 << '\n';
    return;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == rev[i]) continue;
    if (a[0] == rev[i]) {
      if (a[0] == '1')
        a[0] = '0';
      else
        a[0] = '1';
      v.push_back(1);
    }
    v.push_back(i + 1);
    string temp = a.substr(0, i + 1);
    string temp2 = a.substr(i + 1, n);
    temp = op(temp);
    a = temp + temp2;
  }
  if (v.empty()) v.push_back(n);
  cout << v.size() << " ";
  for (auto c : v) cout << c << " ";
  cout << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
