#include <bits/stdc++.h>
const int64_t INF = 1e18;
const int64_t MOD_1 = 1e9 + 7;
const int64_t MOD_2 = 998244353;
using namespace std;
void start() {}
void solve() {
  string s, t;
  cin >> s >> t;
  map<char, int64_t> mp;
  for (char ch : s) mp[ch]++;
  if (mp['a'] == 0 || mp['b'] == 0 || mp['c'] == 0) {
    sort((s).begin(), (s).end());
    cout << s << '\n';
    return;
  }
  if (t[0] != 'a') {
    for (int64_t i = 0; i < mp['a']; i++) cout << 'a';
    for (int64_t i = 0; i < mp['b']; i++) cout << 'b';
    for (int64_t i = 0; i < mp['c']; i++) cout << 'c';
  } else {
    for (int64_t i = 0; i < mp['a']; i++) cout << 'a';
    if (t[1] == 'b' && t[2] == 'c') {
      for (int64_t i = 0; i < mp['c']; i++) cout << 'c';
      for (int64_t i = 0; i < mp['b']; i++) cout << 'b';
    } else {
      for (int64_t i = 0; i < mp['b']; i++) cout << 'b';
      for (int64_t i = 0; i < mp['c']; i++) cout << 'c';
    }
  }
  for (auto x : mp) {
    if (x.first == 'a' || x.first == 'b' || x.first == 'c') continue;
    for (int64_t i = 0; i < x.second; i++) cout << x.first;
  }
  cout << '\n';
}
int main() {
  start();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
