#include <bits/stdc++.h>
using namespace std;
int get_int(string s) {
  int i = 0;
  for (;; i++) {
    if (s[i] == '=') {
      i += 2;
      break;
    }
  }
  int ans = 0;
  for (; i < (int)s.size(); i++) {
    ans *= 10;
    ans += s[i] - '0';
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin, s);
  int p = 0, neg = 0;
  for (auto c : s) {
    if (c == '+')
      p++;
    else if (c == '-')
      neg++;
  }
  int n = get_int(s);
  p++;
  int m = p - n * neg;
  int M = n * p - neg;
  if (n < m || n > M) {
    cout << "Impossible" << '\n';
    return 0;
  }
  cout << "Possible" << '\n';
  int S = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] != '?') {
      cout << s[i];
      continue;
    }
    int sgn = (i < 2 || s[i - 2] == '+') ? 1 : -1;
    if (sgn == 1)
      p--;
    else
      neg--;
    for (int j = 1; j <= n; j++) {
      m = S + sgn * j + p - n * neg;
      M = S + sgn * j + p * n - neg;
      if (m > n || n > M) continue;
      S += sgn * j;
      cout << j;
      break;
    }
  }
  return 0;
}
