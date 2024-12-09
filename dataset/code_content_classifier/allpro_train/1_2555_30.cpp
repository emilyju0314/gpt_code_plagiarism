#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MX = 2e5 + 5;
bool idx[MX];
void solve() {
  string s, t;
  cin >> s >> t;
  int len = s.length(), c = 0;
  for (int i = 0; i <= len - 1; i++) {
    if (s[i] != t[i]) {
      c++;
      idx[i] = true;
    }
  }
  if (c & 1) {
    cout << "impossible\n";
    return;
  }
  c /= 2;
  for (int i = 0; i <= len - 1; i++) {
    if (idx[i]) {
      if (c) {
        cout << t[i];
        c--;
      } else
        cout << s[i];
    } else
      cout << s[i];
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
