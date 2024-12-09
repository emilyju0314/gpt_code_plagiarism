#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long max = 0;
  string s;
  cin >> s;
  for (long long i = 0; i < 26; i++) {
    char c = 'a' + i;
    long long temp = 0, ans = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == c)
        temp++;
      else {
        ans = ans + temp / k;
        temp = 0;
      }
    }
    ans = ans + temp / k;
    max = std::max(max, ans);
  }
  cout << max;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n = 1;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}
