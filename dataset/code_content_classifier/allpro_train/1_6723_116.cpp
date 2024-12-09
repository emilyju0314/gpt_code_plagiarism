#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAX_N = 10000;
int ans[30];
int temp[30];
set<char> och;
int main() {
  int n, m, q;
  cin >> n;
  string s, t;
  cin >> s;
  for (int i = 0; i < 26; i++) ans[i] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      ans[s[i] - 'a'] = 0;
      och.insert(s[i]);
    }
  }
  cin >> m;
  for (int qw = 0; qw < m; qw++) {
    cin >> t;
    q = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        if (t[i] != s[i]) q = 0;
      } else {
        if (och.find(t[i]) != och.end()) q = 0;
      }
    }
    for (int i = 0; i < 26; i++) temp[i] = 0;
    if (q == 1) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '*') temp[t[i] - 'a'] = 1;
      }
      for (int i = 0; i < 26; i++) {
        if (temp[i] == 0) ans[i] = 0;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < 26; i++) sum += ans[i];
  cout << sum;
  return 0;
}
