#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  long long n;
  string s;
  while (t--) {
    cin >> n >> s;
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    long long i = 0;
    long long j = n - 1;
    while (i < n && s[i] != '>') i++;
    while (j >= 0 && s[j] != '<') j--;
    if (i == n)
      cout << n - 1 - j << '\n';
    else if (j == -1)
      cout << i << '\n';
    else
      cout << min(n - 1 - j, i) << '\n';
  }
  return 0;
}
