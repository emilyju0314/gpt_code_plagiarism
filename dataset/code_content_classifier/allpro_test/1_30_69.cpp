#include <bits/stdc++.h>
using namespace std;
long long solve(string& s, char c) {
  long long i = 0, j = s.size();
  --j;
  long long ans = 0;
  while (i < j) {
    if (s[i] == s[j]) {
      ++i;
      --j;
    } else if (s[i] == c) {
      ++i;
      ++ans;
    } else if (s[j] == c) {
      --j;
      ++ans;
    } else {
      return 1000000000000000000;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 1000000000000000000;
    for (long long i = 0; i <= 26; ++i) {
      char c = 'a' + i;
      long long a = solve(s, c);
      ans = min(ans, a);
    }
    if (ans == 1000000000000000000) {
      ans = -1;
    }
    cout << ans << endl;
  }
  return 0;
}
