#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    long long cur = 0;
    long long ans = 0;
    long long x = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-') {
        cur--;
      } else {
        cur++;
      }
      if (cur + x < 0) {
        ans += i + 1;
        x++;
      }
    }
    ans += (long long)s.length();
    cout << ans << '\n';
  }
  return 0;
}
