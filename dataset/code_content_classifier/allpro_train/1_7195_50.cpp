#include <bits/stdc++.h>
using namespace std;
int n, t;
string s;
void setup() {}
void solve() {
  cin >> t;
  for (int z = 1; z <= t; ++z) {
    cin >> n;
    cin >> s;
    int i;
    for (i = 0; i < n; ++i)
      if (s[i] == '8') break;
    cout << (n - i >= 11 ? "YES" : "NO") << endl;
  }
}
int main() {
  setup();
  solve();
  return 0;
}
