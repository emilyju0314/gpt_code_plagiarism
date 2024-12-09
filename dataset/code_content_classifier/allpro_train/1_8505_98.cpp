#include <bits/stdc++.h>
using namespace std;
int fun(string& s, int i, int j) {
  int ans = 0;
  int f = 1;
  for (int i1 = 0; i1 < s.length(); i1++) {
    if (f) {
      if (s[i1] - '0' == i) {
        ans++;
        f = 1 - f;
      }
    } else {
      if (s[i1] - '0' == j) {
        ans++;
        f = 1 - f;
      }
    }
  }
  if (i != j && ans % 2 == 1) return ans - 1;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int fans = s.size();
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        int ans = fun(s, i, j);
        fans = min(fans, n - ans);
      }
    }
    cout << fans << endl;
  }
}
