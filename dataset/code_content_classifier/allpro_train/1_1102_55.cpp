#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, pre, post;
  int n;
  cin >> n;
  cin >> s;
  int ans = n;
  for (int i = 1; i < n; i += 2) {
    pre = "", post = "";
    for (int j = 0; j <= i / 2; j++) pre += s[j];
    for (int k = i / 2 + 1; k <= i; k++) post += s[k];
    if (pre == post) ans = n - pre.length() + 1;
  }
  cout << ans;
}
