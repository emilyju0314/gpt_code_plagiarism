#include <bits/stdc++.h>
using namespace std;
const long long M = 1e6 + 100;
string s[101];
long long n, mx;
long long ch(char c1, char c2) {
  long long ct = 0;
  bool b = false;
  for (long long i = (0); i <= (n - 1); i++) {
    b = false;
    for (long long j = (0); j <= (s[i].length() - 1); j++) {
      if (s[i][j] != c1 && s[i][j] != c2) b = true;
    }
    if (!b) ct += s[i].length();
  }
  return ct;
}
int main() {
  ios::sync_with_stdio(false);
  string s1 = "abcdefghijklmnopqrstuvwxyz";
  cin >> n;
  for (long long i = (0); i <= (n - 1); i++) cin >> s[i];
  for (long long i = (0); i <= (25); i++) {
    for (long long j = (0); j <= (25); j++) {
      mx = max(mx, ch(s1[i], s1[j]));
    }
  }
  cout << mx;
  return 0;
}
