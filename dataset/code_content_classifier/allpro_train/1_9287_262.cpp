#include <bits/stdc++.h>
using namespace std;
void JIZZ(string output = "") {
  cout << output;
  exit(0);
}
const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i + k < n; ++i) {
    if (s[i] != '?' && s[i + k] == '?') {
      s[i + k] = s[i];
    }
  }
  for (int i = n - 1 - k; i >= 0; --i) {
    if (s[i + k] != '?' && s[i] == '?') {
      s[i] = s[i + k];
    }
  };
  ;
  for (int i = 0; i + k < n; ++i) {
    ;
    ;
    if (s[i] != s[i + k]) {
      cout << "NO" << endl;
      return;
    }
  }
  int cnt[266] = {0};
  for (int i = 0; i < k; ++i) {
    ++cnt[s[i]];
  }
  if (cnt['0'] > k / 2 || cnt['1'] > k / 2) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < k; ++i) {
    if (s[i] != '?') continue;
    if (cnt['0'] < k / 2) {
      s[i] = '0';
      ++cnt['0'];
    } else
      s[i] = '1';
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
