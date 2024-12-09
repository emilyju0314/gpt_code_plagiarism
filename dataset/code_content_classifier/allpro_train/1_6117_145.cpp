#include <bits/stdc++.h>
using namespace std;
long long const N = 2 * 1e5 + 10, pi = acos(-1), OO = 1e9;
int n, a, b;
string s;
int main() {
  cin >> n >> a >> b >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      if (!i) {
        ans++;
        if (a > b)
          s[i] = 'a', a--;
        else
          s[i] = 'b', b--;
      } else if (s[i - 1] == '*') {
        if (a || b) {
          ans++;
          if (a > b)
            s[i] = 'a', a--;
          else
            s[i] = 'b', b--;
        }
      } else if (s[i - 1] != 'a' && a) {
        s[i] = 'a';
        a--;
        ans++;
      } else if (s[i - 1] != 'b' && b) {
        s[i] = 'b';
        b--;
        ans++;
      }
    }
  }
  cout << ans;
}
