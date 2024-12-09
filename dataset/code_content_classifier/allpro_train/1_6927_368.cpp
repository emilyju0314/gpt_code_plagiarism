#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, k, ans = 1;
  cin >> n >> k;
  string s, s1, s2;
  cin >> s;
  for (i = 1; i < n; i++) {
    s1 = s.substr(0, n - i);
    s2 = s.substr(i, n);
    if (s1 == s2) break;
  }
  if (i == n) {
    for (i = 0; i < k; i++) cout << s;
    return 0;
  }
  cout << s1;
  s2 = s.substr(n - i, n);
  for (i = 0; i < k; i++) cout << s2;
  return 0;
}
