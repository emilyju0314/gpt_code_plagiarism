#include <bits/stdc++.h>
using namespace std;
bool isFile = 0;
void faster() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (isFile) {
    freopen(
        "A"
        ".in",
        "r", stdin);
    freopen(
        "A"
        ".out",
        "w", stdout);
  }
}
void solve() {
  long long n;
  cin >> n;
  long long q = 0;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') {
      q += a[i];
    }
  }
  long long res = q;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') {
      q -= a[i];
    } else {
      q += a[i];
    }
    res = max(res, q);
  }
  q = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') {
      q += a[i];
    }
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == 'B') {
      q -= a[i];
    } else {
      q += a[i];
    }
    res = max(res, q);
  }
  cout << res;
}
int main() {
  faster();
  int t = 1;
  while (t--) solve();
}
