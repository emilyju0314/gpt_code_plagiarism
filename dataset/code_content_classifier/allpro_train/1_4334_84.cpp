#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  long long n = s.size();
  long long sum = 0;
  long long l = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    l++;
    sum += s[i] - '0';
    if (l > 2 || sum % 3 == 0 || s[i] % 3 == 0) {
      ans++;
      sum = 0;
      l = 0;
    }
  }
  cout << ans << endl;
}
